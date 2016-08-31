#include "visitor.h"
#include <sstream>

void PrintVisitor::rootNode() {}
void PrintVisitor::sqrNode() {
    output = output + "^2\n";
}
void PrintVisitor::multNode() {
    output += " *\n"; 
} 	
void PrintVisitor::subNode() {
    output = output + "-\n";
} 
void PrintVisitor::addNode() {
    output += "+\n"; 
} 
void PrintVisitor::opNode(Op* op) {
    //output += op->evaluate(); //doesn't show the opnodes 
    //implement 

    //creating stringstream, buffer to hold op nodes as they are created
        //outputs op nodes to temp  
    stringstream temp; 
    temp << op->evaluate(); 
    
    //after op nodes are outputted into buffer, it uses str() 
        //to access the sequence of characters inserted in temp
   // output += temp.str();
   output = output + temp.str();
     output = output + "\n";
   // output += "\n"; 

} 
void PrintVisitor::execute() {
    std::cout << output; 
}
