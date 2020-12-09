#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>
#include"Queue.h"
#include"Nodes.h"
#include "Stack.h"
#include <stack>

using namespace std;

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name, double latitude, double longitude);
        void addVertexObject(vertex v);
        void displayEdges();
        int distanceBetweenWords(std::string word1, std::string word2);
        void assignDistance(string s);
        bool vertexExists(string s);
        std::vector<vertex> vertices;
        void unassignDistance();
        void addLocationstoQueue(string,string, stack<vertex*>&);
    protected:
    private:
        //vector<edge> edges;
        vertex* search(std::string v);
        vertex* BFS(std::string v1, std::string v2);
        bool allVisited();
        vertex* getMinNode();
        

};

#endif // GRAPH_H
