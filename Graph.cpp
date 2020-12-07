#include "Graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>

using namespace std;

Graph::Graph()
{
}

Graph::~Graph()
{
}
void Graph::addEdge(string v1, string v2, int weight){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}
void Graph::addVertex(string n, double latitude, double longitude){ 
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
            if(vertices[i].latitude == 0){ //Check to see if the added node also contains location data, if it doesn't, add it
                vertices[i].latitude = latitude;
                vertices[i].longitude = longitude;
            }
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);
    }
}

void Graph::addVertex(vertex v){ //Second addVertex function when we just want to pass a vertex
    if(search(v.name)){
        cout << "Already in Graph" << endl;
        return;
    }
    vertices.push_back(v);
}

void Graph::displayEdges()
{
    for(int i = 0; i < vertices.size(); i++){
        cout<<"[" << vertices[i].name<<"]" << "-->";
        // for(int j = 0; j < vertices[i].adj.size(); j++){
        //     cout<<"[" << vertices[i].adj[j].v->name << " " << vertices[i].adj[j].weight <<"]";
        //     if (j != vertices[i].adj.size()-1)
        //         cout<<"***";
        // }
        cout<<endl;
    }
}

vertex* Graph::search(string v){
    for(int x = 0; x < vertices.size(); x++){
        if (vertices[x].name == v){
            return &vertices[x];
        }
    }
    return nullptr;
}


vertex* Graph::BFS(string startVal, string endVal){
    for(int x = 0; x < vertices.size(); x++){
        vertices[x].visited = false;
        vertices[x].distance = 0;
        vertices[x].parent = nullptr;
    }
    //search for startVal
    vertex *v = search(startVal);
    v->visited = true;
    v->distance = 0;
    v->parent = nullptr;
    //add v to a queue
    queue<vertex*> q;
    q.push(v);
    while(!q.empty()){
        vertex *n = q.front(); //front returns a value
        q.pop(); //pop removes from queue
        for(int x = 0; x < n->adj.size(); x++){
            if(n->adj[x].v->visited == false){
                n->adj[x].v->distance = n->distance + 1; //parent distance + 1
                n->adj[x].v->parent = n;
                //check if it's what we're looking for
                if(n->adj[x].v->name == endVal){
                    return n->adj[x].v; 

                }else{
                    n->adj[x].v->visited = true;
                    q.push(n->adj[x].v);
                }
            }
        }
    }
    return nullptr;
}


int Graph::distanceBetweenWords(std::string word1, std::string word2){
    unassignDistance();
    assignDistance(word1);
    int result = search(word2)->distance;
    unassignDistance();

    return result;
}

bool Graph::allVisited(){
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

void Graph::unassignDistance(){
    for(int i = 0; i < vertices.size(); i++){
        vertices[i].visited = false;
        vertices[i].distance = INT32_MAX;
    }
}
