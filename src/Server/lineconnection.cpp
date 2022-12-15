#include "lineconnection.h"
#include <iostream>
#include <string>

using namespace MUD::Server;

void LineInputConnectoin::getLine() {
  async_read_until(socket(), _buffer, '\n',
                   [this](boost::system::error_code error, std::size_t bytes) {
                     
                     if (error)
                       std::cout << "There was an error in async read" 
                                 << std::endl;

                     else {
                       std::string line;
                       std::getline(_inStream, line);
                       write(_game.parseInput(line)+"\n"); //Calls write, which could be a problem
                       getLine();
                     }
                   });
}
