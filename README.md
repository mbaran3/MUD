# MUD
The reason I wanted to do this project was beccause I 
learned about MUD fairly recently and it seemed like a fun idea.
during this project I leanred a lot about how to handle threads
and how that relates to server management.

This server uses Boost ASIO to handle the ports and all of the
threading required. While the server runs it doesn't do much
There is very little feedback to the player other than what 
room they currently are in. There is no combat, and no way to 
interact with another player on the server. This MUD is a single
player experience. 

The Game logic is all writen in ASM assembly. Each room is 
stored as an array of Strings, with which directinos you can 
and can't go. The game logic is parsed in C++, then passed
to an assembly function as a integer. This is a fairly basic
way to handle input from the player, but it works. Once the 
logic is complete the assemby function returns a pointer
to the first character in the string which using Boost ASIO
we print out to the player.




