#ifndef GREENLIST_H
#define GREENLIST_H

#include "GreenNode.h"
#include <string>

class GreenStack; // <--- FIX 1: Tell the compiler GreenStack exists

class GreenList {
private:
    GreenNode* head;

public:
    GreenList();
    ~GreenList();

    void addFront(const std::string& name, const std::string& loc, int year);
    void addBack(const std::string& name, const std::string& loc, int year);
    
    // <--- FIX 2: Add "GreenStack& trash" so we can save deleted items
    bool removeByName(const std::string name, GreenStack& trash);
    
    void printAll() const;
    void insertSorted(const std::string& name, const std::string& loc, int year);
};

#endif
