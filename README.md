# Lem_in

 The goal of this project is to create a pathfinder moving ants in an anthill from room start to room end with a minimum of moves.
 The program receive the anthill in a file, described as follow:
 - the number of ants on first parameter
 - the rooms, described by names and position: <name> <pos x> <pos y>
 - special rooms, like start and end, prefixed with ##start or ##end
 - pipes between rooms, thats the path ants will use to move: <room a>-<room b>
 - comments prefixed with # character
  
  For example, a basic anthill will be:

   100

   ##start  
   start   0   0  

   ##end  
   end     10  10  

   rooma   3   3  
   roomb   7   7  

   start-rooma  
   start-roomb  
   rooma-end  
   roomb-end  

 Next the program write the moves as follow:
  - L<ant number>-<room>
 
 An important rule is also that there can only be one ant per room, except in start and end.
 
 A typical output is:  
 ![lem_in_2](https://user-images.githubusercontent.com/21102863/29680498-fff3f02c-8904-11e7-86ab-ee40c3b7c6c1.png)
