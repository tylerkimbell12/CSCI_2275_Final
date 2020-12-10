# CSCI_2275_Final
Final project for CSCI 2275 

Our plan is to use a graph to model the CU campus, making notible locations nodes and the distance between them weights. With the graph, we plan on making a pathfinding application capable of guiding the user from one location to the other in the shortest distance. We plan on using multiple path finding algorithms, including ones that involve visiting certain node types to find paths for the user to follow. Along with the graph we also plan on using a stack to store directions/nodes, tracing the path back to the starting node, so the user can click through/pop the stack to get the next direction, similar to the google maps assistant be it a little more manual.

----------------------------------------

**How to Run:**

Download the zip file from github, and extract the files into VScode.

Compile with: g++ -std=c++11 final.cpp Queue.cpp Stack.cpp Graph.cpp -o final

Try Running with:

For Mac: Run with: ./final graphVertexes.csv graphdataMac.txt

If that doesnt work... Run with this:

For Windows: Run with: ./final graphVertexes.csv graphdataWindows.csv

	
----------------------------------------
  
**Dependencies:**

No third party libraries are required,  only the mingw compiler. 
  
----------------------------------------
**System Requirements:**

Tested on both macOS and Windows

----------------------------------------
**Team Members:**

Marc Roy, Tyler Kimbell

----------------------------------------
**Known Bugs:**

There is a comma at the end of line 19 in the graphdataWindows.csv that if either added or removed, 
causes the program to seg fault. We beleive it is an error with regex.

