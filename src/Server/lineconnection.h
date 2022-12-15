#ifndef LINE_CONNECTION_H
#define LINE_CONNECTION_H
#include "connection.h"
#include "../Game/GameInfo.h"
namespace MUD {
namespace Server {
class LineInputConnectoin : public Connection {

public:
  LineInputConnectoin(boost::asio::io_service &ioService)
      : Connection(ioService), _inStream(&_buffer) {}

  void start() { getLine(); } // Start reading lines from the user



private:
  void getLine();
  MUD::Game::GameInfo _game;
  

  boost::asio::streambuf _buffer;
  std::istream _inStream;
};
} // namespace Server
} // namespace MUD

#endif
