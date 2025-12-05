#ifndef GREENSTACK_H
#define GREENSTACK_H

#include "GreenNode.h" 
#include <iostream>

class GreenStack {
private:
    GreenNode* top; 

public:
    GreenStack() : top(nullptr) {}

    ~GreenStack() {
        while (!isEmpty()) {
            pop(); 
        }
    }

    void push(std::string name, std::string loc, int year, int sdg) {
        GreenNode* newNode = new GreenNode(name, loc, year, sdg);
        newNode->next = top;
        top = newNode;
    }

    GreenNode* pop() {
        if (isEmpty()) return nullptr;
        
        GreenNode* temp = top;
        top = top->next;
        temp->next = nullptr; 
        return temp;
    }

    bool isEmpty() { return top == nullptr; }

    void printStack() {
        if (isEmpty()) {
            std::cout << "[Trash Bin is Empty]\n";
            return;
        }
        GreenNode* cur = top;
        std::cout << "--- TRASH BIN (Recent on top) ---\n";
        while (cur != nullptr) {
            std::cout << "[Deleted] " << cur->projectName 
                      << " (SDG " << cur->sdg << ")\n"; 
            cur = cur->next;
        }
        std::cout << "---------------------------------\n";
    }
};

#endif