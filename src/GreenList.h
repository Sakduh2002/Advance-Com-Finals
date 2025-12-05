#ifndef GREENLIST_H
#define GREENLIST_H

#include "GreenNode.h"
#include <string>

class GreenStack; 

class GreenList {
private:
    GreenNode* head;

public:
    GreenList();
    ~GreenList();


    void addFront(const std::string& name, const std::string& loc, int year, int sdg);
    void addBack(const std::string& name, const std::string& loc, int year, int sdg);
    void insertSorted(const std::string& name, const std::string& loc, int year, int sdg);

    bool removeByName(const std::string name, GreenStack& trash);
    
    void printAll() const;
};

#endif