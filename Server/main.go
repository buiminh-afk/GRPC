package main

import (
	process_service "GrpcServer/pkg/process_info"
	event_service "GrpcServer/pkg/system_event"
	"flag"
	"fmt"
	"log"
	"net"

	"google.golang.org/grpc"
)

var (
	e    string = "[-]"
	i    string = "[!]"
	s    string = "[+]"
	port        = flag.Int("port", 50051, "The server port")
)

func main() {
	flag.Parse()
	lis, err := net.Listen("tcp", fmt.Sprintf(":%d", *port))
	if err != nil {
		log.Fatalf("%s Failed to listen: %v", e, err)
	}

	newServer := grpc.NewServer()
	process_service.RegisterSystemInfoService(newServer)
	event_service.RegisterEventInfoService(newServer)
	
	fmt.Printf("%s Server is running on localhost:%d\n", i, *port)
	if err := newServer.Serve(lis); err != nil {
		log.Fatalf("%s Failed to serve: %v", e, err)
	}
}
