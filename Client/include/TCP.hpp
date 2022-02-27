/**
 * @file TCP.hpp
 * File containing methods to communicate via TCP to a server
 */
#ifndef TCP_HPP
#define TCP_HPP

#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstring>
#include <string>

#include "Error.hpp"

#define BUFFER 2048

class TCP {
  private :
    // === Variables ===
    /** @var instance
     * @brief instance of the singleton class
     */
    static TCP* instance;

    /** @var _socket
     * @brief int containing the client socket
     */
    int _socket;

    /** @TODO remove (obselete) */
    char _data[BUFFER];

    /** @var _sockadrr
     * @brief sockaddr_in structure containing all info to communicate with the server
     */
    struct sockaddr_in _sockaddr;

  public :
    // === Constructor & Destructor ===
    /**
     * @fn TCP(std::string serv_ip = "127.0.0.1", int serv_port = 9111)
     * @brief Constructor of the TCP class
     * @param serv_ip ip address of the server (default=127.0.0.1)
     * @param serv_port port of the server (default=9111)
     */
    TCP(std::string serv_ip = "127.0.0.1", int serv_port = 9111){
      memset(_data, '0', sizeof(_data));

      _sockaddr.sin_family = AF_INET;
      _sockaddr.sin_addr.s_addr = inet_addr(serv_ip.c_str());
      _sockaddr.sin_port = htons(serv_port);
    }

    /**
     * @fn virtual ~TCP()
     * @brief Destructor of the TCP class
     */
    virtual ~TCP(){}

    // === Getters & Setters ===
    /**
     * @fn static TCP* getInstance()
     * @brief getter for the singleton instance
     * @return TCP*
     */
    inline static TCP* getInstance(){
      if(instance == nullptr)
        instance = new TCP();

      if(instance == nullptr)
        throw Error("TCP::getInstance::instance is null");

      return instance;
    }

    // === Functions ===
    /**
     * @fn void create_socket()
     * @brief create the socket to communicate with the server
     */
    void create_socket();

    /**
     * @fn void connect_to_server()
     * @brief connect the socket to the server
     */
    void connect_to_server();

    /**
     * @fn void connect_to_server()
     * @brief send a message to the server
     * @param msg the message to send to the server
     */
    void send_to_server(std::string msg);

    /**
     * @fn void disconnect_from_server()
     * @brief disconnect the socket from the server
     */
    void disconnect_from_server();
};

#endif
