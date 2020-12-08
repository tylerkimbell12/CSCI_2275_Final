#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

using namespace std;

struct vertex;

struct adjVertex{
    vertex *v = NULL;
    int weight = 0;
    adjVertex(vertex *x, int wght){
        v = x;
        weight = wght;
    }
};

struct vertex{
    std::string name = "booga wooga";
    std::vector<adjVertex> adj;
    bool visited = false;
    int distance = 0;
    double latitude = 0;
    double longitude = 0;
    vertex *parent = NULL;
    vertex(){};
};

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
    protected:
    private:
        //vector<edge> edges;
        std::vector<vertex> vertices;
        vertex* search(std::string v);
        vertex* BFS(std::string v1, std::string v2);
        bool allVisited();
        vertex* getMinNode();
        void unassignDistance();

};

#endif // GRAPH_H
