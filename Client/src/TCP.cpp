#include "TCP.hpp"

TCP* TCP::instance = nullptr;

// === Functions ===

void TCP::create_socket(){
  if((_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    throw Error("TCP::create_socket::socket creation failed");
}

void TCP::connect_to_server(){
  if(connect(_socket, (struct sockaddr *)&_sockaddr, sizeof(_sockaddr)) < 0)
    throw Error("TCP::connect_to_server::connexion to server failed");
}

void TCP::send_to_server(std::string msg){
  if(write(_socket, msg.c_str(), msg.size()) < 0)
    throw Error("TCP::send_to_server::message sending failed");
}

void TCP::disconnect_from_server(){
  if(shutdown(_socket, SHUT_RD) < 0)
    throw Error("TCP::disconnect_from_server::shutdown of reading failed");

  if(shutdown(_socket, SHUT_WR) < 0)
    throw Error("TCP::disconnect_from_server::shutdown of writing failed");

  if(close(_socket) < 0)
    throw Error("TCP::disconnect_from_server::closing failed");
}
