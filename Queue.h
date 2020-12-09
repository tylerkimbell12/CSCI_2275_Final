#ifndef Queue_H
#define Queue_H
#include <iostream>
#include <string>
#include"Nodes.h"
using namespace std;


class LLQueue {
    private:
        QNode *head, *tail;

    public:
        LLQueue() {
            head = NULL;
            tail = NULL;
        };
        bool isEmpty();
        void enqueue(vertex*);  //optional
        QNode* dequeue();      //optional
        QNode* peek();
        void printQueue();
};

#endif