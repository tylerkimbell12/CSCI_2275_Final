#ifndef Nodes_H
#define Nodes_H
#include<vector>
#include<iostream>
using namespace std;

struct vertex;

//item in a linked list tack
struct LLNode {
    vertex* data;
    LLNode *prev;
    LLNode(vertex* toQ) {
        data = toQ;
        prev = NULL;
    }
};

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

struct QNode {
    vertex* data;
    QNode *next;
    
    QNode() {
        data = NULL;
        next = NULL;
    }
    
    QNode(vertex *toQ) {
        data = toQ;
        next = NULL;
    }
};
#endif
