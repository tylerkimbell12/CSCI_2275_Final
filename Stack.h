#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node *prev;
    Node(string toQ) {
        data = toQ;
        prev = NULL;
    }
};

class Stack {
    private: 
        Node *top;
    public:
        Stack() {
            top = NULL;
        }
        bool isEmpty();
        void push(string val); 
        Node *peek();        
        Node *pop();
        void printStack();
        void clearStack();

};