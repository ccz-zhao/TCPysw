#pragma once

#include <arpa/inet.h>
#include <sys/socket.h>

class Socket {
    
};

class Tcp_socket {
public: 
    Tcp_socket();
    ~Tcp_socket();
    Tcp_socket& operator=(const Tcp_socket&) = delete;
    Tcp_socket& operator=(Tcp_socket&&) = delete;
    Tcp_socket(const Tcp_socket&) = delete;
    Tcp_socket(Tcp_socket&&) = delete;
private:
    int Tcp_sock{};
};