#ifndef SERVER_H
#define SERVER_H
#include "lineconnection.h"
#include <boost/asio.hpp>
#include <iostream>
#include <list>

namespace MUD {
namespace Server {
class Server {

public:
  explicit Server(int port)
      : _acceptor(_service, boost::asio::ip::tcp::endpoint(
                                boost::asio::ip::tcp::v6(), port)),
        _signalSet(_service, SIGINT, SIGTERM) {
    _signalSet.async_wait([this](boost::system::error_code error, int signal) { // Prints something when we exit the server
      
      std::cout << "Server received single (" << signal;
      std::cout << ") Shutting down" << std::endl;
      
      _acceptor.cancel();
    });
  }

  void run() {
    accept();
    
    std::cout << "The server is running!" << std::endl;
    
    _service.run();
  };

private:
  void accept() {

    _connections.emplace_back(_service);
    auto &connection = _connections.back();

    _acceptor.async_accept(connection.socket(),
        [this, &connection](boost::system::error_code error) {
          if (!error) {
            connection.start(); // This calls lineInputConnection start function which starts the server reading lines
            std::cout << "Someone has connected" << std::endl;
            accept();
          }
        });
  }
  boost::asio::io_service _service;
  boost::asio::signal_set _signalSet;
  boost::asio::ip::tcp::acceptor _acceptor;
  std::list<LineInputConnectoin> _connections;
};
} // namespace Server
} // namespace MUD
#endif
