#include <stack>
#include "iterator.h"

//***************************OPERATOR_ITERATOR***********************
//operatoriterator iterators over composite nodes with two children
    //first will initialize to the left child to start 
    //next will cycle from left child to right child to NULL 

//initialize the root's left child to be the current_ptr
void OperatorIterator::first() {
    current_ptr = self_ptr->get_left(); 
    // current_ptr = self_ptr;
    //current_ptr = self_ptr->get_right(); 
    
}

//cycles from left child to right child to NULL 
void OperatorIterator::next() {
    // if (current_ptr == self_ptr)
    // {
    //     current_ptr = self_ptr->get_left(); 
    // }
    
    if (current_ptr == self_ptr->get_left()) {
        current_ptr = self_ptr->get_right();
    }
    
    else if (current_ptr == self_ptr->get_right()){
        current_ptr = NULL; 
    } 
    
   

}

bool OperatorIterator::is_done() {
    // if (current_ptr == NULL) {
    //     return true; 
    // }
    // return false;
    
    return (current_ptr == NULL); 
}

Base* OperatorIterator::current() {
    return current_ptr; 
}


//***************************UnaryIterator**************************************
//unaryiterator used iterator over composite nodes with one child 

//set current_ptr as self_ptr(root) 
void UnaryIterator::first() {
    // if (self_ptr->get_left() != NULL) {
    //     current_ptr = current_ptr->get_left();
    // }
    //current_ptr = self_ptr->get_left(); //CHANGED TO GET_LEFT
    current_ptr = self_ptr->get_left();
}

//if the current_ptr already equals the head, then traverse to the left 
    //else, current_ptr will equal NULL
void UnaryIterator::next() {
    // if (current_ptr == self_ptr) {
    //   current_ptr = self_ptr->get_left(); 
    // }

    // else {
        current_ptr = NULL; 
    // }

}

bool UnaryIterator::is_done() {
    return (current_ptr == NULL); 
}

Base* UnaryIterator::current() {
    return current_ptr; 
}

//****************************NullIterator**************************************
//ALL WORKS 
//nulliterator is used to iterate over leaf nodes 

//sets current_ptr as self_ptr(root) 
void NullIterator::first() {
    current_ptr = NULL;
    //current_ptr = NULL; //TEST TEST TESTING TEST
}

//since it's a leaf node, next would be NULL
void NullIterator::next() {
    if (current_ptr == self_ptr) {
    current_ptr = NULL; 
    }
    
}

//since leaf nodes do not have children, is_done() will always be true 
bool NullIterator::is_done()
{
    if (current_ptr == NULL) {
        return true;
    }
    return false; 
    
    //return (current_ptr == NULL); 
}

Base* NullIterator::current()
{
    return current_ptr;
}

//****************************PreorderIterator**********************************
void PreorderIterator::first() //works 
{
    //cout << "goes inside the first function\n"; 
    // Empty the stack (just in case we had something leftover from another run)  
    while (!iterators.empty()) {
        this->iterators.pop(); 
        //iterators.pop();
    }
    
    //Create an iterator for the Base* that we built the iterator for
    Iterator* iter = this->self_ptr->create_iterator();

    // // Initialize that iterator and push it onto the stack
//    if (iter)
//    {
        //cout << "inside iter if statement\n"; 
        iter->first();
        // while (!iterators.empty()) {
        //     this->iterators.pop(); 
        // }
        //cout << "after recursive call\n"; 
        this->iterators.push(iter);
//    }
}


void PreorderIterator::next() //works 
{
    //iterators.top()->next(); 
    //Iterator* iter = this->iterators.top()->current()->create_iterator();    
    
    //If the top of the stack has not been iterated yet, 
    // Create an iterator for the item on the top of the stack
        //Initialize the iterator and push it onto the stack
    //if (!(iterators.top()->is_done())) {
    if(iterators.size() >0){
      
      Iterator* iter = iterators.top()->current()->create_iterator();
      iter->first(); 
      iterators.push(iter); 
    } 
    
    //As long as the top iterator on the stack is_done(), pop it off the stack 
        //and then advance whatever iterator is now on top of the stack
    while(iterators.size() > 0 && iterators.top()->is_done())
    //while (this->iterators.top()->is_done()) //testing 
    {
        iterators.pop(); 
        
        //if iterator size is 0, cannot move to next iterator 
        //if (iterators.size() == 0) { 
          //  break; 
        //}
        
        if(iterators.size()>0){
           iterators.top()->next();
        }
        
        //iterators.top()->next();
        
       /* if (!(iterators.top()->is_done())) 
        {
          //  Iterator* iter = iterators.top()->current()->create_iterator();
            //iterators.top()->next();
            iterators.top()->next();
          //  iter->first();
        //    iterators.push(iter);
        }
        */
    }
    
    
}

bool PreorderIterator::is_done() //works 
{
    // Return true if there are no more elements on the stack to iterate
    //checks if the stack is empty or top current points to NULL 
    if (iterators.empty() || iterators.top()->current() == NULL || iterators.top() == NULL) {
        return true; 
    }
    return false; //if not empty, returns false 
}

Base* PreorderIterator::current() //works 
{
    // Return the current for the top iterator in the stack
    //cout << "goes inside the current function" << endl;
    //if (iterators.empty()) {
//    if (this->iterators.size() > 0) {
        return iterators.top()->current(); 
//    }
    
//    else 
//    {
//        return NULL; 
 //   }
}





