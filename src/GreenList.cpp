#include "GreenList.h"
#include "GreenStack.h" 
#include <iostream>

GreenList::GreenList() : head(nullptr) {}

GreenList::~GreenList() {
    GreenNode* current = head;
    while (current != nullptr) {
        GreenNode* temp = current;
        current = current->next;
        delete temp;
    }
}

void GreenList::addFront(const std::string& name, const std::string& loc, int year, int sdg) {
    GreenNode* newNode = new GreenNode(name, loc, year, sdg);
    newNode->next = head;
    head = newNode;
}

void GreenList::addBack(const std::string& name, const std::string& loc, int year, int sdg) {
    GreenNode* newNode = new GreenNode(name, loc, year, sdg);

    if (head == nullptr) {
        head = newNode;
        return;
    }
    GreenNode* cur = head;
    while (cur->next != nullptr)
        cur = cur->next;

    cur->next = newNode;
}

bool GreenList::removeByName(const std::string name, GreenStack& trash) {
    if (head == nullptr) return false;

 
    if (head->getName() == name) {
        GreenNode* temp = head;
        
        trash.push(temp->getName(), temp->getLoc(), temp->getYear(), temp->getSDG());
        
        head = head->next; 
        delete temp;       
        return true;
    }


    GreenNode* prev = head;
    GreenNode* cur = head->next;

    while (cur != nullptr) {
        if (cur->getName() == name) {
    
            trash.push(cur->getName(), cur->getLoc(), cur->getYear(), cur->getSDG());
            
            prev->next = cur->next;
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }

    return false;
}

void GreenList::printAll() const {
    GreenNode* cur = head;
    while (cur != nullptr) {
        std::cout << "Project: " << cur->getName() << "\n";
        std::cout << "Location: " << cur->getLoc() << "\n";
        std::cout << "Start Year: " << cur->getYear() << "\n";
        std::cout << "SDG Goal: " << cur->getSDG() << "\n";
        std::cout << "-----------------------------\n";
        cur = cur->next;
    }
}

void GreenList::insertSorted(const std::string& name, const std::string& loc, int year, int sdg) {
    GreenNode* newNode = new GreenNode(name, loc, year, sdg);

    if (head == nullptr || head->getYear() >= year) {
        newNode->next = head;
        head = newNode;
        return;
    }

    GreenNode* current = head;
    while (current->next != nullptr && current->next->getYear() < year) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}