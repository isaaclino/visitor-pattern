#ifndef VISITOR_H
#define VISITOR_H
#include "composite.h"

class Op; 
class Visitor { 
	public: 
		Visitor() {}; 
		virtual void rootNode() = 0;
		virtual void sqrNode() = 0; 
		virtual void multNode() = 0; 
		virtual void subNode() = 0; 
		virtual void addNode() = 0; 
		virtual void opNode(Op* op) = 0; 
		virtual void execute() = 0; 
};


class PrintVisitor : public Visitor {
	private:
		std::string output;

	public:
		PrintVisitor() : Visitor() {};
		
		//For visiting a root node (do nothing)
		void rootNode(); 
		
		//For visiting a square node
		void sqrNode();	
		
		//For visiting a multiple node
		void multNode();	

		//For visiting a subtraction node
		void subNode();	
		
		//For visiting an add node
		void addNode();	
		
		//For visiting a leaf node
		void opNode(Op* op);	
		
		//Prints all visited nodes
		void execute();		
		
};

#endif
