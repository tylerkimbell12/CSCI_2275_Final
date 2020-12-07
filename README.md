# CSCI_2275_Final
Final project for CSCI 2275 

Our plan is to use a graph to model the CU campus, making notible locations nodes and the distance between them weights. With the graph, we plan on making a pathfinding application capable of guiding the user from one location to the other in the shortest distance. We plan on using multiple path finding algorithms, including ones that involve visiting certain node types to find paths for the user to follow. Along with the graph we also plan on using a stack to store directions/nodes, tracing the path back to the starting node, so the user can click through/pop the stack to get the next direction, similar to the google maps assistant be it a little more manual.

----------------------------------------

Our project will:

  #Have a modeled graph of the CU campus
  
  #Give step by step directions from loction to location untill the destination is reached
  
  #Create an optimal path to the destination based on the data we have
	
	
	
----------------------------------------
  
Other interesting potential features:

  #Give cardinal directions between loctions (North, East, South, West), as we could add x anf y courdinates to the nodes
  
  #Give an eta based on mode of transportaion (walking, skateboarding, biking, ect.)
  
  #Give a description of the location, as a stored string in the node
  
  
----------------------------------------
Known Bugs
  #Graph builds in C++ 9.8 but not C++ 11 (Most important bug as of this moment)

