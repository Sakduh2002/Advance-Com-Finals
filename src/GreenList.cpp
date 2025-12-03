#include "GreenList.h"
#include "GreenStack.h" // Needed to use the trash bin!
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

void GreenList::addFront(const std::string& name, const std::string& loc, int year) {
    GreenNode* newNode = new GreenNode(name, loc, year);
    newNode->next = head;
    head = newNode;
}

void GreenList::addBack(const std::string& name, const std::string& loc, int year) {
    GreenNode* newNode = new GreenNode(name, loc, year);

    if (head == nullptr) {
        head = newNode;
        return;
    }
    GreenNode* cur = head;
    while (cur->next != nullptr)
        cur = cur->next;

    cur->next = newNode;
}

// FIXED LOGIC: Now we actually use 'trash' to save data before deleting!
bool GreenList::removeByName(const std::string name, GreenStack& trash) {
    if (head == nullptr) return false;

    // Case 1: Head is the target
    if (head->getName() == name) {
        GreenNode* temp = head;
        
        // SAVE TO TRASH BEFORE DELETING
        trash.push(temp->getName(), temp->getLoc(), temp->getYear());
        
        head = head->next; 
        delete temp;       
        return true;
    }

    // Case 2: Middle/End
    GreenNode* prev = head;
    GreenNode* cur = head->next;

    while (cur != nullptr) {
        if (cur->getName() == name) {
            // SAVE TO TRASH BEFORE DELETING
            trash.push(cur->getName(), cur->getLoc(), cur->getYear());
            
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
        std::cout << "Project: " << cur->getName() << "\n"; // Updated to use getName()
        std::cout << "Location: " << cur->getLoc() << "\n";
        std::cout << "Start Year: " << cur->getYear() << "\n";
        std::cout << "-----------------------------\n";
        cur = cur->next;
    }
}

void GreenList::insertSorted(const std::string& name, const std::string& loc, int year) {
    GreenNode* newNode = new GreenNode(name, loc, year);

    // Note: Used getYear() accessor here
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
