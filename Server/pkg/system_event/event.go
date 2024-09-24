package systemevent

import (
	event_pb "GrpcServer/grpc/event_proto"
	"encoding/json"
	"fmt"
	"io"
	"net"
	"os"
	"unicode"

	"google.golang.org/grpc"
	"google.golang.org/grpc/peer"
)

var (
	e string = "[-]"
	i string = "[!]"
	s string = "[+]"
)

type eventServer struct {
	event_pb.UnimplementedEventInfoServer
}

type Process struct {
	Opcode     int32  `json:"opcode"`
	OpcodeName string `json:"opcode_name"`
	PID        uint32 `json:"pid"`
	PPID       uint32 `json:"ppid"`
	CmdLine    string `json:"cmd_line"`
}

type FileIO struct {
	Opcode     int32  `json:"opcode"`
	OpcodeName string `json:"opcode_name"`
	Filename   string `json:"filename"`
}

type Registry struct {
	Opcode     int32  `json:"opcode"`
	OpcodeName string `json:"opcode_name"`
	InitTime   int64  `json:"init_time"`
	Status     uint32 `json:"status"`
	Index      uint32 `json:"index"`
	KeyName    string `json:"key_name"`
}

func CleanString(s string) string {
	var result []rune
	for _, r := range s {
		if unicode.IsPrint(r) {
			result = append(result, r)
		}
	}
	return string(result)
}

func SaveProcessToJson(processChan chan Process, fileName string) {
	fmt.Printf("%s Start writing to file %s\n", i, fileName)
	firstTime := true
	f, err := os.Create(fmt.Sprintf("./output/%s", fileName))

	if err != nil {
		fmt.Printf("%s Error while create file %s: %s\n", e, fileName, err.Error())
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

func SaveFileToJSON(fileIoChan chan FileIO, fileName string) {
	fmt.Printf("%s Start writing to file %s\n", i, fileName)
	firstTime := true
	f, err := os.Create(fmt.Sprintf("./output/%s", fileName))

	if err != nil {
		fmt.Printf("%s Error while create file %s: %s\n", e, fileName, err.Error())
		return
	}

	defer f.Close()
	f.WriteString("[")
	for {
		fileio, ok := <-fileIoChan
		if ok {
			data, _ := json.MarshalIndent(fileio, "", "	")
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

func SaveRegistryToJSON(registryChan chan Registry, fileName string) {
	fmt.Printf("%s Start writing to file %s\n", i, fileName)
	firstTime := true
	f, err := os.Create(fmt.Sprintf("./output/%s", fileName))

	if err != nil {
		fmt.Printf("%s Error while create file %s: %s\n", e, fileName, err.Error())
		return
	}

	defer f.Close()
	f.WriteString("[")
	for {
		registry, ok := <-registryChan
		if ok {
			data, _ := json.MarshalIndent(registry, "", "	")
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

func (server *eventServer) ProcessEvent(stream event_pb.EventInfo_ProcessEventServer) error {
	p, ok := peer.FromContext(stream.Context())
	if !ok {
		return fmt.Errorf("%s Unable to retrieve client peer info", e)
	}

	clientIP, clientPort, err := net.SplitHostPort(p.Addr.String())
	if err != nil {
		return fmt.Errorf("%s Error extracting client IP: %v", e, err)
	}

	fmt.Printf("%s Receiving process stream from %s:%s\n", i, clientIP, clientPort)

	processChan := make(chan Process, 100)
	go SaveProcessToJson(processChan, fmt.Sprintf("%s(%s)_process.json", clientIP, clientPort))
	for {
		process, err := stream.Recv()
		if err != nil {
			if err == io.EOF {
				// Client has finished sending data, send a response and close the channel.
				fmt.Printf("%s Receiving from %s:%s process stream done\n", s, clientIP, clientPort)
				close(processChan)
				return stream.SendAndClose(&event_pb.ServerResponse{
					Msg: "Received all process information",
				})
			}
			close(processChan)
			return stream.SendAndClose(&event_pb.ServerResponse{
				Msg: "Error occurred during receiving process event",
			})
		}

		tmp := Process{
			Opcode:     process.GetOpcode(),
			OpcodeName: process.GetOpcodeName(),
			PID:        process.GetPid(),
			PPID:       process.GetPpid(),
			CmdLine:    process.GetCmdLine(),
		}

		processChan <- tmp
	}
}

func (server *eventServer) FileIoEvent(stream event_pb.EventInfo_FileIoEventServer) error {
	p, ok := peer.FromContext(stream.Context())
	if !ok {
		return fmt.Errorf("%s Unable to retrieve client peer info", e)
	}

	clientIP, clientPort, err := net.SplitHostPort(p.Addr.String())
	if err != nil {
		return fmt.Errorf("%s Error extracting client IP: %v", e, err)
	}

	fmt.Printf("%s Receiving fileIO stream from %s:%s\n", i, clientIP, clientPort)
	fileIoChan := make(chan FileIO, 100)
	go SaveFileToJSON(fileIoChan, fmt.Sprintf("%s(%s)_fileio.json", clientIP, clientPort))

	for {
		fileIO, err := stream.Recv()
		if err != nil {
			if err == io.EOF {
				// Client has finished sending data, send a response and close the channel.
				fmt.Printf("%s Receiving from %s:%s fileio stream done\n", s, clientIP, clientPort)
				close(fileIoChan)
				return stream.SendAndClose(&event_pb.ServerResponse{
					Msg: "Received all fileio information",
				})
			}
			close(fileIoChan)
			return stream.SendAndClose(&event_pb.ServerResponse{
				Msg: "Error occurred during receiving fileIo event",
			})
		}
		tmp := FileIO{
			Opcode:     fileIO.GetOpcode(),
			OpcodeName: fileIO.GetOpcodeName(),
			Filename:   fileIO.GetFilename(),
		}

		fileIoChan <- tmp
	}
}

func (server *eventServer) RegistryEvent(stream event_pb.EventInfo_RegistryEventServer) error {
	p, ok := peer.FromContext(stream.Context())
	if !ok {
		return fmt.Errorf("%s Unable to retrieve client peer info", e)
	}

	clientIP, clientPort, err := net.SplitHostPort(p.Addr.String())
	if err != nil {
		return fmt.Errorf("%s Error extracting client IP: %v", e, err)
	}

	fmt.Printf("%s Receiving registry stream from %s:%s\n", i, clientIP, clientPort)
	registryChan := make(chan Registry, 100)
	go SaveRegistryToJSON(registryChan, fmt.Sprintf("%s(%s)_registry.json", clientIP, clientPort))
	for {
		registry, err := stream.Recv()
		if err != nil {
			if err == io.EOF {
				// Client has finished sending data, send a response and close the channel.
				fmt.Printf("%s Receiving from %s:%s registry stream done\n", s, clientIP, clientPort)
				close(registryChan)
				return stream.SendAndClose(&event_pb.ServerResponse{
					Msg: "Received all registry information",
				})
			}
			close(registryChan)
			return stream.SendAndClose(&event_pb.ServerResponse{
				Msg: "Error occurred during receiving registry event",
			})
		}
		tmp := Registry{
			Opcode:     registry.GetOpcode(),
			OpcodeName: registry.GetOpcodeName(),
			InitTime:   registry.GetInitTime(),
			Status:     registry.GetStatus(),
			Index:      registry.GetIndex(),
			KeyName:    registry.GetKeyName(),
		}

		registryChan <- tmp
	}
}

func RegisterEventInfoService(grpcServer *grpc.Server) {
	event_pb.RegisterEventInfoServer(grpcServer, &eventServer{})
}