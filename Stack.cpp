#include "Stack.h"
#include <string>
using namespace std;


//linked list stack implementations

void LLStack::push(vertex* toPush) {
    LLNode* prevNode = NULL;
    LLNode* newTop = new LLNode(toPush);
    if(top != NULL){
        prevNode = top->prev;
    }
    top = newTop;
    top->prev = prevNode;
}

LLNode* LLStack::pop() {
    LLNode* topNode = top;
    LLNode* prevNode = top->prev;
    top = prevNode;
    return topNode;
}

LLNode* LLStack::peek() {
    return top;
}

void LLStack::printStack() {
    LLNode *crawler = top;
    cout << "\ntop" << endl;
    while (crawler != NULL) {
        cout << crawler->data << " | ";
        crawler = crawler->prev;
    }
    cout << endl;
}

bool LLStack::isEmpty() {
    return top == NULL;
}
