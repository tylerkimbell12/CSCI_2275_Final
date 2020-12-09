#include <iostream>
#include <string>
#include "Nodes.h"
using namespace std;


//skeleton for a linked list implementation of a stack
class LLStack {
    private: 
        LLNode *top;
    public:
        LLStack() {
            top = NULL;
        }
        // bool isFull();
        bool isEmpty();
        void push(vertex* val); //optional
        LLNode *peek();        //optional
        LLNode *pop();
        void printStack();
};