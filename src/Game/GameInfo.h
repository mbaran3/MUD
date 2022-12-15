#ifndef GAME_INFO_H
#define GAME_INFO_H

#include <sstream>
extern "C" char* roomInfo(long, long*);


namespace MUD{
namespace Game{
class GameInfo{
    public:
        GameInfo():_currentRoom(0){}

        // Parses a string input giving ever input a number
        // 0 to repeat the discription of the room
        // 1 to go North, 2 to go East, 3 to Go south, 4 to West

        std::string parseInput(const std::string input){ 
            std::string word;                               // Using stringstream to parse the Input
            std::stringstream inStream(input);
            inStream >> word;

            std::cout << "Current : " << _currentRoom << " Memmory :" << p_currentRoom << std::endl;

            if(word == "go"){
                inStream >> word;                           // Find next word after go 
                if(word == "north")
                    return roomInfo(1, p_currentRoom);
                else if(word == "west")
                    return roomInfo(2, p_currentRoom);
                else if(word == "south")
                    return roomInfo(3, p_currentRoom);
                else if(word == "east")
                    return roomInfo(4, p_currentRoom);
                else{   // If the first word was go but it wasn't followed by a direction 
                    return "Is not a valid direction. Valid directions are north, west, south, and east"; 
                }

            }
            if(word == "inspect"){
                return roomInfo(0, p_currentRoom);
            }     
            return "Could not Parse Input";

        }

    private:
        long _currentRoom;
        long* p_currentRoom = &_currentRoom;

};
}
}




#endif