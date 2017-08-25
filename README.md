# Lem_in

 The goal of this project is to create a pathfinder moving ants in an anthill from room start to room end with a minimum of moves.
 The program receive the anthill in a file, described as follow:
 - the number of ants on first parameter
 - the rooms, described by names and position: <name> <pos x> <pos y>
 - special rooms, like start and end, prefixed with ##start or ##end
 - pipes between rooms, thats the path ants will use to move: <room a>-<room b>
  
  For example, a basic anthill will be:


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
