#include "Node.hpp"

void Node::print(ostream& out){
    out << c << ": " << freq << ": " << left;
}