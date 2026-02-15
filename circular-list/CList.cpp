
#include "CList.h"
#include <iostream>

using namespace std;

CList::CList() {
    //TODO: something
    this->head = nullptr;
}

bool CList::isEmpty() {
    return this->head == nullptr;
}

int CList::getSize() {
    if (this->isEmpty()) return 0;

    int size = 1;
    Node* currentNode = this->head;

    while (currentNode->getNext() != this->head) {
        currentNode = currentNode->getNext();
        size++;
    }

    return size;
}

Node *CList::getTail() {
    if (this->isEmpty()) return nullptr;

    Node* currentNode = this->head;

    while (currentNode->getNext() != this->head) {
        currentNode = currentNode->getNext();
    }

    return currentNode;
}

void CList::insertFirst(int value) {

    Node* newNode = new Node();
    newNode->setValue(value);

    if (this->isEmpty()) {
        this->head = newNode;
        this->head->setNext(this->head);
        return;
    }

    Node* tail = this->getTail();

    newNode->setNext(this->head);
    this->head = newNode;
    tail->setNext(newNode);
}

void CList::insertAt(int value, int position) {
    if (this->isEmpty() || position == 0 || position == 1) {
        this->insertFirst(value);
        return;
    }

    Node* prevNode = this->getAt(position - 1);

    Node* newNode = new Node();
    newNode->setValue(value);
    newNode->setNext(prevNode->getNext());
    prevNode->setNext(newNode);
}

void CList::insertLast(int value) {
    if (this->isEmpty()) {
        this->insertFirst(value);
        return;
    }

    Node* tail = this->getTail();

    if (tail == nullptr) {
        cout << "tail not found" << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->setValue(value);
    tail->setNext(newNode);
    newNode->setNext(this->head);

}

Node *CList::getAt(int position) {
    if (this->isEmpty()) return nullptr;

    if (this->getSize() < position) return nullptr;

    Node* currentNode = this->head;
    int currentPosition = 1;

    while (currentPosition < position) {
        currentPosition++;
        currentNode = currentNode->getNext();
    }

    return currentNode;
}

void CList::print(int turns) {
    if (this->isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }

    Node* currentNode = this->head;
    int currentTurn = 0;

    while (currentTurn < turns) {
        cout << currentNode->getValue() << " -> ";

        if (currentNode->getNext() == this->head) {
            currentTurn++;
            cout << " <- ";
        }

        currentNode = currentNode->getNext();
    }

    cout << endl;
}

//Eliminar al inicio

void CList::deleteFirst() {
    if (this->isEmpty()) return; 

    if(this->head->getNext() == this->head) {
        delete this->head; 
        this->head = nullptr;
        return; 
        } 

        Node* tail = this->getTail(); 
        Node* temp = this->head; 

this->head = this->head->getNext();
tail->setNext(this->head);

delete temp; 
} 

//Eliminar al final
void CList::deleteLast() {
    if (this->isEmpty()) return; 

    if(this->head->getNext() == this->head) {
        delete this->head; 
        this->head = nullptr;
        return; 
        } 

        Node* current = this->head; 
        
        //Buscar el nodo antes del tail 
        while (current->getNext()->getNext() != this->head) {
            current = current->getNext(); 
 }

 Node* tail = current->getNext();
 current->setNext(this->head);
 
 delete tail; 
}

//Eliminar al medio
void CList::deleteAt(int position) {

    if(position <= 0  || position > this->getSize()) return;

    if (position == 1) {
        this->deleteFirst();
        return;
    }

        Node* prevNode = this->getAt(position -1); 

        if (prevNode == nullptr) return; 

 Node* nodeToDelete = prevNode->getNext();

 prevNode->setNext(nodeToDelete->getNext()); 

 delete nodeToDelete; 
}
