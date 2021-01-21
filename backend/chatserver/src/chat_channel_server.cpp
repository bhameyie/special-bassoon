//
// Created by Boguste Hameyie on 1/20/21.
//

#include <memory>
#include <variant>
#include "chatting.pb.h"
#include "chatting.grpc.pb.h"
#include "utils.h"
#include "chat_channel_service.h"

using namespace chatting;

class ChatChannelServerImpl final : public ChatChannelServer::Service {

 public:
  explicit ChatChannelServerImpl(std::unique_ptr<ChatChannelService> service)
      : service_(std::move(service)) {}

 private:
  std::unique_ptr<ChatChannelService> service_;
};