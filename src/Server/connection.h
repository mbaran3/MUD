#ifndef CONNECTION_H
#define CONNECTION_H
#include <boost/asio.hpp>
#include <iostream>
#include <mutex>
#include <queue>
#include <utility>

namespace MUD {
namespace Server {
class Connection {

  typedef boost::asio::ip::tcp::socket SocketType; 

public:
  // Constructor
  explicit Connection(boost::asio::io_service &io)
      : _socket(io), _outstream(&_buffer) {}

  // Public Functions
  void write(const std::string &message) { //Writes a message to the socket
    _outstream << message;
    async_write(_socket, _buffer,
                [this](boost::system::error_code error, std::size_t bytes) { 
                  
                  if (!error)
                    std::cout << "Write completed successfully!" << std::endl;
                  
                  else
                    std::cout << error.message();
                });
  }

  SocketType &socket() { return _socket; }
  void start() { write("Connection made.\n"); }


private:
  SocketType _socket;
  boost::asio::streambuf _buffer;
  std::ostream _outstream;
};
} // namespace Server
} // namespace MUD
#endif
