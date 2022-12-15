#include "Server/server.h"
#include <iostream>







int main() {
  const int SERVER_PORT = 5000 ;  
  MUD::Server::Server server(SERVER_PORT);
  server.run();

  return 0;
}
