// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: event.proto

#include "event.pb.h"
#include "event.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace eventinfo {

static const char* EventInfo_method_names[] = {
  "/eventinfo.EventInfo/ProcessEvent",
  "/eventinfo.EventInfo/FileIoEvent",
  "/eventinfo.EventInfo/RegistryEvent",
};

std::unique_ptr< EventInfo::Stub> EventInfo::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< EventInfo::Stub> stub(new EventInfo::Stub(channel, options));
  return stub;
}

EventInfo::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_ProcessEvent_(EventInfo_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  , rpcmethod_FileIoEvent_(EventInfo_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  , rpcmethod_RegistryEvent_(EventInfo_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  {}

::grpc::ClientWriter< ::eventinfo::Process>* EventInfo::Stub::ProcessEventRaw(::grpc::ClientContext* context, ::eventinfo::ServerResponse* response) {
  return ::grpc::internal::ClientWriterFactory< ::eventinfo::Process>::Create(channel_.get(), rpcmethod_ProcessEvent_, context, response);
}

void EventInfo::Stub::async::ProcessEvent(::grpc::ClientContext* context, ::eventinfo::ServerResponse* response, ::grpc::ClientWriteReactor< ::eventinfo::Process>* reactor) {
  ::grpc::internal::ClientCallbackWriterFactory< ::eventinfo::Process>::Create(stub_->channel_.get(), stub_->rpcmethod_ProcessEvent_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::eventinfo::Process>* EventInfo::Stub::AsyncProcessEventRaw(::grpc::ClientContext* context, ::eventinfo::ServerResponse* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::eventinfo::Process>::Create(channel_.get(), cq, rpcmethod_ProcessEvent_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::eventinfo::Process>* EventInfo::Stub::PrepareAsyncProcessEventRaw(::grpc::ClientContext* context, ::eventinfo::ServerResponse* response, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::eventinfo::Process>::Create(channel_.get(), cq, rpcmethod_ProcessEvent_, context, response, false, nullptr);
}

::grpc::ClientWriter< ::eventinfo::FileIO>* EventInfo::Stub::FileIoEventRaw(::grpc::ClientContext* context, ::eventinfo::ServerResponse* response) {
  return ::grpc::internal::ClientWriterFactory< ::eventinfo::FileIO>::Create(channel_.get(), rpcmethod_FileIoEvent_, context, response);
}

void EventInfo::Stub::async::FileIoEvent(::grpc::ClientContext* context, ::eventinfo::ServerResponse* response, ::grpc::ClientWriteReactor< ::eventinfo::FileIO>* reactor) {
  ::grpc::internal::ClientCallbackWriterFactory< ::eventinfo::FileIO>::Create(stub_->channel_.get(), stub_->rpcmethod_FileIoEvent_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::eventinfo::FileIO>* EventInfo::Stub::AsyncFileIoEventRaw(::grpc::ClientContext* context, ::eventinfo::ServerResponse* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::eventinfo::FileIO>::Create(channel_.get(), cq, rpcmethod_FileIoEvent_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::eventinfo::FileIO>* EventInfo::Stub::PrepareAsyncFileIoEventRaw(::grpc::ClientContext* context, ::eventinfo::ServerResponse* response, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::eventinfo::FileIO>::Create(channel_.get(), cq, rpcmethod_FileIoEvent_, context, response, false, nullptr);
}

::grpc::ClientWriter< ::eventinfo::Registry>* EventInfo::Stub::RegistryEventRaw(::grpc::ClientContext* context, ::eventinfo::ServerResponse* response) {
  return ::grpc::internal::ClientWriterFactory< ::eventinfo::Registry>::Create(channel_.get(), rpcmethod_RegistryEvent_, context, response);
}

void EventInfo::Stub::async::RegistryEvent(::grpc::ClientContext* context, ::eventinfo::ServerResponse* response, ::grpc::ClientWriteReactor< ::eventinfo::Registry>* reactor) {
  ::grpc::internal::ClientCallbackWriterFactory< ::eventinfo::Registry>::Create(stub_->channel_.get(), stub_->rpcmethod_RegistryEvent_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::eventinfo::Registry>* EventInfo::Stub::AsyncRegistryEventRaw(::grpc::ClientContext* context, ::eventinfo::ServerResponse* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::eventinfo::Registry>::Create(channel_.get(), cq, rpcmethod_RegistryEvent_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::eventinfo::Registry>* EventInfo::Stub::PrepareAsyncRegistryEventRaw(::grpc::ClientContext* context, ::eventinfo::ServerResponse* response, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::eventinfo::Registry>::Create(channel_.get(), cq, rpcmethod_RegistryEvent_, context, response, false, nullptr);
}

EventInfo::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      EventInfo_method_names[0],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< EventInfo::Service, ::eventinfo::Process, ::eventinfo::ServerResponse>(
          [](EventInfo::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReader<::eventinfo::Process>* reader,
             ::eventinfo::ServerResponse* resp) {
               return service->ProcessEvent(ctx, reader, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      EventInfo_method_names[1],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< EventInfo::Service, ::eventinfo::FileIO, ::eventinfo::ServerResponse>(
          [](EventInfo::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReader<::eventinfo::FileIO>* reader,
             ::eventinfo::ServerResponse* resp) {
               return service->FileIoEvent(ctx, reader, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      EventInfo_method_names[2],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< EventInfo::Service, ::eventinfo::Registry, ::eventinfo::ServerResponse>(
          [](EventInfo::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReader<::eventinfo::Registry>* reader,
             ::eventinfo::ServerResponse* resp) {
               return service->RegistryEvent(ctx, reader, resp);
             }, this)));
}

EventInfo::Service::~Service() {
}

::grpc::Status EventInfo::Service::ProcessEvent(::grpc::ServerContext* context, ::grpc::ServerReader< ::eventinfo::Process>* reader, ::eventinfo::ServerResponse* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status EventInfo::Service::FileIoEvent(::grpc::ServerContext* context, ::grpc::ServerReader< ::eventinfo::FileIO>* reader, ::eventinfo::ServerResponse* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status EventInfo::Service::RegistryEvent(::grpc::ServerContext* context, ::grpc::ServerReader< ::eventinfo::Registry>* reader, ::eventinfo::ServerResponse* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace eventinfo

