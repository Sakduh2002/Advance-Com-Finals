#include "GreenNode.h"

GreenNode::GreenNode(std::string name, std::string loc, int year, int sdgVal)
    : projectName(name), location(loc), startYear(year), sdg(sdgVal), next(nullptr) {}

GreenNode::~GreenNode() {
    
}