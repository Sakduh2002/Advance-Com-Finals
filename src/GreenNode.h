#ifndef GREENNODE_H
#define GREENNODE_H

using namespace std;

#include <string>

class GreenNode{
private:
    string projectName;
    string location;
    int startYear;
    GreenNode* next;

public:
    GreenNode(std::string name, std::string loc, int year);
    ~GreenNode();

    // 1. Allow the List AND the Stack to touch private data
    friend class GreenList;
    friend class GreenStack;

    // 2. Add "Getters" so main.cpp can read the data safely
    string getName() { return projectName; }
    string getLoc() { return location; }
    int getYear() { return startYear; }
};

#endif
