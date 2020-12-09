#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;


//linked list queue implementations 

bool LLQueue::isEmpty() {
    return head == NULL && tail == NULL;
}

void LLQueue::enqueue(vertex *toQ) {
    QNode* prevTail = tail;
    tail = new QNode(toQ);
    prevTail->next = tail;
}

QNode* LLQueue::dequeue() {
    return head;
    delete head;
}

QNode* LLQueue::peek() {
    return head;
}

void LLQueue::printQueue() {
    if (!isEmpty()) {
        QNode *crawler = head;
        cout << "\nHead" << endl;
        while(crawler != NULL) {
            cout << crawler->data << " | ";
            crawler = crawler->next;
        }
        cout << endl;
    } else {
        cout << "q empty, can't print" << endl;
    }
}