#include "Stack.h"
#include <string>
using namespace std;

void Stack::push(string toPush) {
    Node* prevNode = NULL;
    if(top != NULL){
        prevNode = top->prev;
    }
    top = new Node(toPush);
    top->prev = prevNode;

}

Node* Stack::pop() {
   Node* topNode = top;
   Node* prevNode = top->prev;
    delete top;
    top = prevNode;
    return topNode;
}

Node*Stack::peek() {
    return top;
}

void Stack::printStack() {
   Node *crawler = top;
    cout << "\ntop" << endl;
    while (crawler != NULL) {
        cout << crawler->data << " | ";
        crawler = crawler->prev;
    }
    cout << endl;
}

void Stack::clearStack(){
    while(!isEmpty()){
        pop();
    }
}

bool Stack::isEmpty() {
    return top == NULL;
}