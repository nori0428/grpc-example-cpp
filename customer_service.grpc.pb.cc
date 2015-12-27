// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: customer_service.proto

#include "customer_service.pb.h"
#include "customer_service.grpc.pb.h"

#include <grpc++/channel.h>
#include <grpc++/impl/client_unary_call.h>
#include <grpc++/impl/rpc_service_method.h>
#include <grpc++/impl/service_type.h>
#include <grpc++/support/async_unary_call.h>
#include <grpc++/support/async_stream.h>
#include <grpc++/support/sync_stream.h>
namespace proto {

static const char* CustomerService_method_names[] = {
  "/proto.CustomerService/ListPerson",
  "/proto.CustomerService/AddPerson",
};

std::unique_ptr< CustomerService::Stub> CustomerService::NewStub(const std::shared_ptr< ::grpc::Channel>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< CustomerService::Stub> stub(new CustomerService::Stub(channel));
  return stub;
}

CustomerService::Stub::Stub(const std::shared_ptr< ::grpc::Channel>& channel)
  : channel_(channel), rpcmethod_ListPerson_(CustomerService_method_names[0], ::grpc::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_AddPerson_(CustomerService_method_names[1], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::ClientReader< ::proto::Person>* CustomerService::Stub::ListPersonRaw(::grpc::ClientContext* context, const ::proto::RequestType& request) {
  return new ::grpc::ClientReader< ::proto::Person>(channel_.get(), rpcmethod_ListPerson_, context, request);
}

::grpc::ClientAsyncReader< ::proto::Person>* CustomerService::Stub::AsyncListPersonRaw(::grpc::ClientContext* context, const ::proto::RequestType& request, ::grpc::CompletionQueue* cq, void* tag) {
  return new ::grpc::ClientAsyncReader< ::proto::Person>(channel_.get(), cq, rpcmethod_ListPerson_, context, request, tag);
}

::grpc::Status CustomerService::Stub::AddPerson(::grpc::ClientContext* context, const ::proto::Person& request, ::proto::ResponseType* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_AddPerson_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::proto::ResponseType>* CustomerService::Stub::AsyncAddPersonRaw(::grpc::ClientContext* context, const ::proto::Person& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::proto::ResponseType>(channel_.get(), cq, rpcmethod_AddPerson_, context, request);
}

CustomerService::AsyncService::AsyncService() : ::grpc::AsynchronousService(CustomerService_method_names, 2) {}

CustomerService::Service::Service() {
}

CustomerService::Service::~Service() {
}

::grpc::Status CustomerService::Service::ListPerson(::grpc::ServerContext* context, const ::proto::RequestType* request, ::grpc::ServerWriter< ::proto::Person>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

void CustomerService::AsyncService::RequestListPerson(::grpc::ServerContext* context, ::proto::RequestType* request, ::grpc::ServerAsyncWriter< ::proto::Person>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
  AsynchronousService::RequestServerStreaming(0, context, request, writer, new_call_cq, notification_cq, tag);
}

::grpc::Status CustomerService::Service::AddPerson(::grpc::ServerContext* context, const ::proto::Person* request, ::proto::ResponseType* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

void CustomerService::AsyncService::RequestAddPerson(::grpc::ServerContext* context, ::proto::Person* request, ::grpc::ServerAsyncResponseWriter< ::proto::ResponseType>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
  AsynchronousService::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
}

::grpc::RpcService* CustomerService::Service::service() {
  if (service_) {
    return service_.get();
  }
  service_ = std::unique_ptr< ::grpc::RpcService>(new ::grpc::RpcService());
  service_->AddMethod(new ::grpc::RpcServiceMethod(
      CustomerService_method_names[0],
      ::grpc::RpcMethod::SERVER_STREAMING,
      new ::grpc::ServerStreamingHandler< CustomerService::Service, ::proto::RequestType, ::proto::Person>(
          std::mem_fn(&CustomerService::Service::ListPerson), this)));
  service_->AddMethod(new ::grpc::RpcServiceMethod(
      CustomerService_method_names[1],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< CustomerService::Service, ::proto::Person, ::proto::ResponseType>(
          std::mem_fn(&CustomerService::Service::AddPerson), this)));
  return service_.get();
}


}  // namespace proto
