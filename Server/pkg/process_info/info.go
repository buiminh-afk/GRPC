package processinfo

import (
	info_pb "GrpcServer/grpc/info_proto"
	"encoding/json"
	"fmt"
	"io"
	"net"
	"os"
	"strings"
	"unicode"

	"google.golang.org/grpc"
	"google.golang.org/grpc/peer"
)

var (
	e string = "[-]"
	i string = "[!]"
	s string = "[+]"
)

// CleanString removes unprintable characters from a string.
func CleanString(s string) string {
	var result []rune
	for _, r := range s {
		if unicode.IsPrint(r) {
			result = append(result, r)
		}
	}
	return string(result)
}

// ProcessJSON holds the process data structure.
type ProcessJSON struct {
	PID          uint32 `json:"pid"`
	Path         string `json:"path"`
	ExeFile      string `json:"exefile"`
	ProcessType  string `json:"process_type"`
	Company      string `json:"company"`
	Username     string `json:"username"`
	PrivateBytes uint64 `json:"private_bytes"`
	WorkingSet   uint64 `json:"working_set"`
	VirtualBytes uint64 `json:"virtual_bytes"`
}

// SaveProcessToJson saves process information to a JSON file.
func SaveProcessToJson(processChan chan ProcessJSON, fileName string) {
	fmt.Printf("%s Start writing to file %s\n", i, fileName)
	firstTime := true
	f, err := os.Create(fmt.Sprintf("./output/%s", fileName))

	if err != nil {
		fmt.Printf("%s Error while create file %s: %s\n", e,fileName, err.Error())
		return
	}

	defer f.Close()
	f.WriteString("[")
	for {
		process, ok := <-processChan
		if ok {
			data, _ := json.MarshalIndent(process, "", "	")
			if firstTime {
				_, err = f.WriteString(CleanString(string(data)))
				firstTime = false
			} else {
				_, err = f.WriteString("," + string(data))
			}
			if err != nil {
				fmt.Printf("%s Error while writing to file %s (%s)\n", e, fileName, err.Error())
			}
		} else {
			fmt.Printf("%s Done writing to file %s\n", s, fileName)
			f.WriteString("]")
			return
		}
	}
}

// server is the gRPC server implementation.
type server struct {
	info_pb.UnimplementedSystemInfoServer
}

// Processes receives process data from a stream and saves it to a JSON file.
func (server *server) Processes(stream info_pb.SystemInfo_ProcessesServer) error {
	p, ok := peer.FromContext(stream.Context())
	if !ok {
		return fmt.Errorf("%s Unable to retrieve client peer info", e)
	}

	clientIP, clientPort, err := net.SplitHostPort(p.Addr.String())
	if err != nil {
		return fmt.Errorf("%s Error extracting client IP: %v", e, err)
	}

	fmt.Printf("%s Receiving process stream from %s:%s\n", i, clientIP, clientPort)
	processChan := make(chan ProcessJSON, 100)
	go SaveProcessToJson(processChan, fmt.Sprintf("%s(%s).json", clientIP, clientPort))

	for {
		process, err := stream.Recv()
		if err != nil {
			if err == io.EOF {
				// Stream ended, return success message
				fmt.Printf("%s Receiving from %s:%s done\n", s, clientIP, clientPort)
				close(processChan)
				return stream.SendAndClose(&info_pb.ServerResponse{
					Msg: "Received all process information",
				})
			}
			return fmt.Errorf("%s Error receiving process: %v", e, err)
		}

		tmp := ProcessJSON{
			PID:          process.GetPid(),
			Path:         process.GetPath(),
			ExeFile:      strings.Trim(process.GetExefile(), "\u0000"),
			ProcessType:  process.GetProcessType(),
			Company:      strings.Trim(process.GetCompany(), "\u0000"),
			Username:     strings.Trim(process.GetUsername(), "\u0000"),
			PrivateBytes: process.GetPrivateBytes(),
			WorkingSet:   process.GetWorkingSet(),
			VirtualBytes: process.GetVirtualBytes(),
		}

		processChan <- tmp
	}
}

// RegisterSystemInfoService registers the SystemInfo service with the gRPC server.
func RegisterSystemInfoService(grpcServer *grpc.Server) {
	info_pb.RegisterSystemInfoServer(grpcServer, &server{})
}
