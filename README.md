# CSCI_2275_Final
Final project for CSCI 2275 

Our plan is to use a graph to model the CU campus, making notible locations nodes and the distance between them weights. With the graph, we plan on making a pathfinding application capable of guiding the user from one location to the other in the shortest distance. We plan on using multiple path finding algorithms, including ones that involve visiting certain node types to find paths for the user to follow. Along with the graph we also plan on using a stack to store directions/nodes, tracing the path back to the starting node, so the user can click through/pop the stack to get the next direction, similar to the google maps assistant be it a little more manual.

----------------------------------------

**How to Run:**

Download the zip file from github, and extract the files into VScode.

Compile with: g++ Graph.cpp Stack.cpp final.cpp Queue.cpp Nodes.h -std=c++11 -o final 

For Windows: Run with: ./final graphVertexes.csv graphdataWindows.csv

For Mac: Run with: ./final graphVertexes.csv graphdataMac.csv
	
----------------------------------------
  
**Dependencies:**

No third party libraries are required,  only the mingw compiler. 
  
----------------------------------------
**System Requirements:**

Tested on both macOS and Windows, althgouh some modification is needed to run on specific platforms, see known bugs. 

----------------------------------------
**Team Members:**

Marc Roy, Tyler Kimbell

----------------------------------------
**Known Bugs:**


