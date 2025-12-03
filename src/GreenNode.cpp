#include "GreenNode.h"

GreenNode::GreenNode(std::string name, std::string loc, int year)
    : projectName(name), location(loc), startYear(year), next(nullptr) {}

GreenNode::~GreenNode() {
    
}
