//
// Created by Macilaci on 12/21/2023.
//

#include <iostream>
#include "List.h"

using namespace std;

List::List() {
    first = nullptr;
    nodeCounter = 0;
}

List::~List() {
    Node *current = first;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

bool List::exists(int d) const {
    Node *current = first;
    while (current != nullptr) {
        if (current->value == d) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int List::size() const {
    return nodeCounter;
}

bool List::empty() const {
    return nodeCounter == 0;
}

void List::insertFirst(int d) {
    Node *newNode = new Node(d, first);
    first = newNode;
    nodeCounter++;
}

int List::removeFirst() {
    if (first == nullptr) {
        cout << "List is empty";
    }
    int value = first->value;
    Node *next = first->next;
    delete first;
    first = next;
    nodeCounter--;
    return value;
}

void List::remove(int d, DeleteFlag df) {
    Node *current = first;
    Node *prev = nullptr;
    while (current != nullptr) {
        if ((df == DeleteFlag::LESS && current->value < d) ||
            (df == DeleteFlag::EQUAL && current->value == d) ||
            (df == DeleteFlag::GREATER && current->value > d)) {
            if (prev == nullptr) {
                removeFirst();
                current = first;
            } else {
                prev->next = current->next;
                delete current;
                current = prev->next;
                nodeCounter--;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void List::print() const {
    Node *current = first;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

