#ifndef GREENNODE_H
#define GREENNODE_H

using namespace std;

#include <string>

class GreenNode{
private:
    string projectName;
    string location;
    int startYear;
    int sdg; 
    GreenNode* next;

public:
    GreenNode(std::string name, std::string loc, int year, int sdgVal);
    ~GreenNode();

    friend class GreenList;
    friend class GreenStack;

    string getName() { return projectName; }
    string getLoc() { return location; }
    int getYear() { return startYear; }
    int getSDG() { return sdg; } // <--- NEW Getter
};

#endif