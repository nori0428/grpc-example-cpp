#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <grpc/grpc.h>
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>
#include <grpc++/grpc++.h>
#include "customer_service.grpc.pb.h"

using namespace proto;
using namespace grpc;

int
main(int argc, char** argv) {
  grpc_init();
  std::unique_ptr<CustomerService::Stub> client = CustomerService::NewStub(
      grpc::CreateChannel("127.0.0.1:11111", grpc::InsecureChannelCredentials()));
  ClientContext context;
  RequestType request;
  ResponseType response;
  Person person;

  Status status;
  if (argc == 3) {
    person.set_name(argv[1]);
    person.set_age(atoi(argv[2]));
    status = client->AddPerson(&context, person, &response);
  } else {
    std::unique_ptr<ClientReader<Person>> reader = client->ListPerson(&context, request);
    while (reader->Read(&person)) {
      std::cout << "name=" << person.name() << ", age=" << person.age() << std::endl;
    }
    status = reader->Finish();
  }
  if (!status.ok()) {
    std::cout << "ListFeatures rpc failed." << std::endl;
  }
  client.reset();
  //grpc_shutdown();
}
