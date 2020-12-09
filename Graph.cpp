#include "Graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>


using namespace std;

Graph::Graph(){}

Graph::~Graph(){}

void Graph::addEdge(string v1, string v2, int weight){
    vertex *startNode = search(v1);
    vertex *endNode = search(v2);
    //Check for duplicate edges
    for(int i = 0; i < startNode->adj.size(); i++){
        if(startNode->adj[i].v == endNode){
            return;
        }
    }
    //Add Edge
    adjVertex start(startNode, weight);
    adjVertex end(endNode, weight);
    startNode->adj.push_back(end);
    endNode->adj.push_back(start);
    
}
void Graph::addVertex(string n, double latitude, double longitude){ 
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);
    }
}

bool Graph::vertexExists(string s){
    for (int i = 0; i < vertices.size(); i++){
        if(s == vertices[i].name){
            return true;
        }
    }
    return false;
}

void Graph::addVertexObject(vertex v){ //Second addVertex function when we just want to pass a vertex
    if(search(v.name)){
        return;
    }
    vertices.push_back(v);
}

void Graph::displayEdges() { //Graph Print Function
    for(int i = 0; i < vertices.size(); i++){
        cout<<"[" << vertices[i].name<<"]" << "-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<"[" << vertices[i].adj[j ].v->name << " " << vertices[i].adj[j ].weight <<"]";
            if (j != vertices[i].adj.size()-1)
                cout<<"***";
        }
        cout<<endl;
    }
}

vertex* Graph::search(string v){ //Search for Node
    for(int x = 0; x < vertices.size(); x++){
        if (vertices[x].name == v){
            return &vertices[x];
        }
    }
    return NULL;
}



int Graph::distanceBetweenWords(std::string word1, std::string word2){
    int result = search(word2)->distance;
    return result;
}

bool Graph::allVisited(){ //Checks if all nodes have been visisted
    for (int i = 0; i < vertices.size(); i++){
        if (vertices[i].visited != true){
            return false;
        }
    }
    return true;
}

vertex* Graph::getMinNode(){ 
    int min = INT32_MAX;
    vertex *result;
    for(int i = 0; i < vertices.size(); i++){
        if(!vertices[i].visited && vertices[i].distance < min){
            min = vertices[i].distance;
            result = &vertices[i];
        }
    }
    return result;

} 

void Graph::addLocationstoQueue(string s, string d, stack<vertex*>& stack){
    vertex* des = search(d);
    while(des->name != s){
        stack.push(des);
        des = des->parent;
    }
}

//Dikjstras
void Graph::assignDistance(string s){
    vertex* source = search(s);
    //source->visited = true;
    source->distance = 0;

    while(!allVisited()){
        vertex* minNode = getMinNode();
        minNode->visited = true;
        for(int i = 0; i < minNode->adj.size(); i++){
            if(minNode->adj[i].v->distance > minNode->distance + minNode->adj[i].weight){
                minNode->adj[i].v->distance = minNode->distance + minNode->adj[i].weight;
                minNode->adj[i].v->parent = minNode;
            }
        }
    }
}

void Graph::unassignDistance(){ //Sets all to univisted, and distance to max
    for(int i = 0; i < vertices.size(); i++){
        vertices[i].visited = false;
        vertices[i].distance = INT32_MAX;
    }
}

void Graph::BellmanFord(string src){ //Gets distance to all Nodes, checks for negative weight
    unassignDistance(); //Sets visited to false and distance to max/infinite
    vertex *source = search(src);
    source->distance = 0; 
    //Loop through all edges and check for shrotest path
    for(int k = 0; k < vertices.size(); k++){
        for(int i = 0; i < vertices.size(); i++){
            for(int j = 0; j < vertices[i].adj.size(); j++){
                if(vertices[i].distance != INT32_MAX && vertices[i].distance + vertices[i].adj[j].weight < vertices[i].adj[j].v->distance) {
                    vertices[i].adj[j].v->distance = vertices[i].distance + vertices[i].adj[j].weight;
                }
            }
        }
    }

    //Check for Negative weight
    for(int i = 0; i < vertices.size() - 1; i++){
        for(int j = 0; j < vertices[i].adj.size(); j++){
            if(vertices[i].distance != INT32_MAX && vertices[i].distance + vertices[i].adj[j].weight < vertices[i].adj[j].v->distance) {
                cout << "Graph contains negative edge weight" << endl;
                return;
            }
        }
    }

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].distance == 0){
            continue;
        }
        cout << "Distance from " << src << " to " << vertices[i].name << " is " << vertices[i].distance << endl; 
    }

    unassignDistance();

}