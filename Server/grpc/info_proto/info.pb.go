// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.2
// 	protoc        v5.27.2
// source: grpc/info_proto/info.proto

package proto

import (
	protoreflect "google.golang.org/protobuf/reflect/protoreflect"
	protoimpl "google.golang.org/protobuf/runtime/protoimpl"
	reflect "reflect"
	sync "sync"
)

const (
	// Verify that this generated code is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(20 - protoimpl.MinVersion)
	// Verify that runtime/protoimpl is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(protoimpl.MaxVersion - 20)
)

type Process struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Pid          uint32 `protobuf:"varint,1,opt,name=pid,proto3" json:"pid,omitempty"`                                       // DWORD in C++ is an unsigned 32-bit integer
	Path         string `protobuf:"bytes,2,opt,name=path,proto3" json:"path,omitempty"`                                      // std::string -> string
	Exefile      string `protobuf:"bytes,3,opt,name=exefile,proto3" json:"exefile,omitempty"`                                // std::string -> string
	ProcessType  string `protobuf:"bytes,4,opt,name=process_type,json=processType,proto3" json:"process_type,omitempty"`     // std::string -> string
	Company      string `protobuf:"bytes,5,opt,name=company,proto3" json:"company,omitempty"`                                // std::string -> string
	Username     string `protobuf:"bytes,6,opt,name=username,proto3" json:"username,omitempty"`                              // std::string -> string
	PrivateBytes uint64 `protobuf:"varint,7,opt,name=private_bytes,json=privateBytes,proto3" json:"private_bytes,omitempty"` // SIZE_T in C++ is a platform-specific type, use uint64 for large values
	WorkingSet   uint64 `protobuf:"varint,8,opt,name=working_set,json=workingSet,proto3" json:"working_set,omitempty"`       // Use uint64 for large memory-related values
	VirtualBytes uint64 `protobuf:"varint,9,opt,name=virtual_bytes,json=virtualBytes,proto3" json:"virtual_bytes,omitempty"` // uint64 for virtual memory size
}

func (x *Process) Reset() {
	*x = Process{}
	if protoimpl.UnsafeEnabled {
		mi := &file_grpc_info_proto_info_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *Process) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*Process) ProtoMessage() {}

func (x *Process) ProtoReflect() protoreflect.Message {
	mi := &file_grpc_info_proto_info_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use Process.ProtoReflect.Descriptor instead.
func (*Process) Descriptor() ([]byte, []int) {
	return file_grpc_info_proto_info_proto_rawDescGZIP(), []int{0}
}

func (x *Process) GetPid() uint32 {
	if x != nil {
		return x.Pid
	}
	return 0
}

func (x *Process) GetPath() string {
	if x != nil {
		return x.Path
	}
	return ""
}

func (x *Process) GetExefile() string {
	if x != nil {
		return x.Exefile
	}
	return ""
}

func (x *Process) GetProcessType() string {
	if x != nil {
		return x.ProcessType
	}
	return ""
}

func (x *Process) GetCompany() string {
	if x != nil {
		return x.Company
	}
	return ""
}

func (x *Process) GetUsername() string {
	if x != nil {
		return x.Username
	}
	return ""
}

func (x *Process) GetPrivateBytes() uint64 {
	if x != nil {
		return x.PrivateBytes
	}
	return 0
}

func (x *Process) GetWorkingSet() uint64 {
	if x != nil {
		return x.WorkingSet
	}
	return 0
}

func (x *Process) GetVirtualBytes() uint64 {
	if x != nil {
		return x.VirtualBytes
	}
	return 0
}

type ServerResponse struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Msg string `protobuf:"bytes,1,opt,name=msg,proto3" json:"msg,omitempty"`
}

func (x *ServerResponse) Reset() {
	*x = ServerResponse{}
	if protoimpl.UnsafeEnabled {
		mi := &file_grpc_info_proto_info_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *ServerResponse) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*ServerResponse) ProtoMessage() {}

func (x *ServerResponse) ProtoReflect() protoreflect.Message {
	mi := &file_grpc_info_proto_info_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use ServerResponse.ProtoReflect.Descriptor instead.
func (*ServerResponse) Descriptor() ([]byte, []int) {
	return file_grpc_info_proto_info_proto_rawDescGZIP(), []int{1}
}

func (x *ServerResponse) GetMsg() string {
	if x != nil {
		return x.Msg
	}
	return ""
}

var File_grpc_info_proto_info_proto protoreflect.FileDescriptor

var file_grpc_info_proto_info_proto_rawDesc = []byte{
	0x0a, 0x1a, 0x67, 0x72, 0x70, 0x63, 0x2f, 0x69, 0x6e, 0x66, 0x6f, 0x5f, 0x70, 0x72, 0x6f, 0x74,
	0x6f, 0x2f, 0x69, 0x6e, 0x66, 0x6f, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x12, 0x07, 0x73, 0x79,
	0x73, 0x69, 0x6e, 0x66, 0x6f, 0x22, 0x8d, 0x02, 0x0a, 0x07, 0x50, 0x72, 0x6f, 0x63, 0x65, 0x73,
	0x73, 0x12, 0x10, 0x0a, 0x03, 0x70, 0x69, 0x64, 0x18, 0x01, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x03,
	0x70, 0x69, 0x64, 0x12, 0x12, 0x0a, 0x04, 0x70, 0x61, 0x74, 0x68, 0x18, 0x02, 0x20, 0x01, 0x28,
	0x09, 0x52, 0x04, 0x70, 0x61, 0x74, 0x68, 0x12, 0x18, 0x0a, 0x07, 0x65, 0x78, 0x65, 0x66, 0x69,
	0x6c, 0x65, 0x18, 0x03, 0x20, 0x01, 0x28, 0x09, 0x52, 0x07, 0x65, 0x78, 0x65, 0x66, 0x69, 0x6c,
	0x65, 0x12, 0x21, 0x0a, 0x0c, 0x70, 0x72, 0x6f, 0x63, 0x65, 0x73, 0x73, 0x5f, 0x74, 0x79, 0x70,
	0x65, 0x18, 0x04, 0x20, 0x01, 0x28, 0x09, 0x52, 0x0b, 0x70, 0x72, 0x6f, 0x63, 0x65, 0x73, 0x73,
	0x54, 0x79, 0x70, 0x65, 0x12, 0x18, 0x0a, 0x07, 0x63, 0x6f, 0x6d, 0x70, 0x61, 0x6e, 0x79, 0x18,
	0x05, 0x20, 0x01, 0x28, 0x09, 0x52, 0x07, 0x63, 0x6f, 0x6d, 0x70, 0x61, 0x6e, 0x79, 0x12, 0x1a,
	0x0a, 0x08, 0x75, 0x73, 0x65, 0x72, 0x6e, 0x61, 0x6d, 0x65, 0x18, 0x06, 0x20, 0x01, 0x28, 0x09,
	0x52, 0x08, 0x75, 0x73, 0x65, 0x72, 0x6e, 0x61, 0x6d, 0x65, 0x12, 0x23, 0x0a, 0x0d, 0x70, 0x72,
	0x69, 0x76, 0x61, 0x74, 0x65, 0x5f, 0x62, 0x79, 0x74, 0x65, 0x73, 0x18, 0x07, 0x20, 0x01, 0x28,
	0x04, 0x52, 0x0c, 0x70, 0x72, 0x69, 0x76, 0x61, 0x74, 0x65, 0x42, 0x79, 0x74, 0x65, 0x73, 0x12,
	0x1f, 0x0a, 0x0b, 0x77, 0x6f, 0x72, 0x6b, 0x69, 0x6e, 0x67, 0x5f, 0x73, 0x65, 0x74, 0x18, 0x08,
	0x20, 0x01, 0x28, 0x04, 0x52, 0x0a, 0x77, 0x6f, 0x72, 0x6b, 0x69, 0x6e, 0x67, 0x53, 0x65, 0x74,
	0x12, 0x23, 0x0a, 0x0d, 0x76, 0x69, 0x72, 0x74, 0x75, 0x61, 0x6c, 0x5f, 0x62, 0x79, 0x74, 0x65,
	0x73, 0x18, 0x09, 0x20, 0x01, 0x28, 0x04, 0x52, 0x0c, 0x76, 0x69, 0x72, 0x74, 0x75, 0x61, 0x6c,
	0x42, 0x79, 0x74, 0x65, 0x73, 0x22, 0x22, 0x0a, 0x0e, 0x53, 0x65, 0x72, 0x76, 0x65, 0x72, 0x52,
	0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x12, 0x10, 0x0a, 0x03, 0x6d, 0x73, 0x67, 0x18, 0x01,
	0x20, 0x01, 0x28, 0x09, 0x52, 0x03, 0x6d, 0x73, 0x67, 0x32, 0x48, 0x0a, 0x0a, 0x53, 0x79, 0x73,
	0x74, 0x65, 0x6d, 0x49, 0x6e, 0x66, 0x6f, 0x12, 0x3a, 0x0a, 0x09, 0x50, 0x72, 0x6f, 0x63, 0x65,
	0x73, 0x73, 0x65, 0x73, 0x12, 0x10, 0x2e, 0x73, 0x79, 0x73, 0x69, 0x6e, 0x66, 0x6f, 0x2e, 0x50,
	0x72, 0x6f, 0x63, 0x65, 0x73, 0x73, 0x1a, 0x17, 0x2e, 0x73, 0x79, 0x73, 0x69, 0x6e, 0x66, 0x6f,
	0x2e, 0x53, 0x65, 0x72, 0x76, 0x65, 0x72, 0x52, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x22,
	0x00, 0x28, 0x01, 0x42, 0x0a, 0x5a, 0x08, 0x2e, 0x2f, 0x3b, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x62,
	0x06, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_grpc_info_proto_info_proto_rawDescOnce sync.Once
	file_grpc_info_proto_info_proto_rawDescData = file_grpc_info_proto_info_proto_rawDesc
)

func file_grpc_info_proto_info_proto_rawDescGZIP() []byte {
	file_grpc_info_proto_info_proto_rawDescOnce.Do(func() {
		file_grpc_info_proto_info_proto_rawDescData = protoimpl.X.CompressGZIP(file_grpc_info_proto_info_proto_rawDescData)
	})
	return file_grpc_info_proto_info_proto_rawDescData
}

var file_grpc_info_proto_info_proto_msgTypes = make([]protoimpl.MessageInfo, 2)
var file_grpc_info_proto_info_proto_goTypes = []any{
	(*Process)(nil),        // 0: sysinfo.Process
	(*ServerResponse)(nil), // 1: sysinfo.ServerResponse
}
var file_grpc_info_proto_info_proto_depIdxs = []int32{
	0, // 0: sysinfo.SystemInfo.Processes:input_type -> sysinfo.Process
	1, // 1: sysinfo.SystemInfo.Processes:output_type -> sysinfo.ServerResponse
	1, // [1:2] is the sub-list for method output_type
	0, // [0:1] is the sub-list for method input_type
	0, // [0:0] is the sub-list for extension type_name
	0, // [0:0] is the sub-list for extension extendee
	0, // [0:0] is the sub-list for field type_name
}

func init() { file_grpc_info_proto_info_proto_init() }
func file_grpc_info_proto_info_proto_init() {
	if File_grpc_info_proto_info_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_grpc_info_proto_info_proto_msgTypes[0].Exporter = func(v any, i int) any {
			switch v := v.(*Process); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_grpc_info_proto_info_proto_msgTypes[1].Exporter = func(v any, i int) any {
			switch v := v.(*ServerResponse); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
	}
	type x struct{}
	out := protoimpl.TypeBuilder{
		File: protoimpl.DescBuilder{
			GoPackagePath: reflect.TypeOf(x{}).PkgPath(),
			RawDescriptor: file_grpc_info_proto_info_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   2,
			NumExtensions: 0,
			NumServices:   1,
		},
		GoTypes:           file_grpc_info_proto_info_proto_goTypes,
		DependencyIndexes: file_grpc_info_proto_info_proto_depIdxs,
		MessageInfos:      file_grpc_info_proto_info_proto_msgTypes,
	}.Build()
	File_grpc_info_proto_info_proto = out.File
	file_grpc_info_proto_info_proto_rawDesc = nil
	file_grpc_info_proto_info_proto_goTypes = nil
	file_grpc_info_proto_info_proto_depIdxs = nil
}
