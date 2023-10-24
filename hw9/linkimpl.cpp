// Nicole Olvera
// username: nicoleolv
// uteid: no4342

#include <iostream>  // allows access the cout and cin 
using std::cin;
using std::cout;
#include <cmath>  // allows access to mathematical operations
#include <memory>  // allows access to shared pointers 
using std::make_shared;
using std::shared_ptr;
#include "linkheader.hpp"  // accesses our header function

int List::length() {  // computes the length of the whole linked list 
  int count = 0;  // starts at 0
  if (head==nullptr)  // if no value exists then still 0
     return 0;  
   else
     return head->length();  // if a value does exist then return it
  };

int Node::length() {  // computes the length of the sublist
  if (!has_next())  // if we don't have a value in our next node
    return 1;  // then return 1 (the on we're on right now)
  else
    return 1+next->length();  // if we do have a value then add one to our length
};

/*
 * Iterative alternative
 * to recursive computation
 */
int List::length_iterative() {
  int count = 0;
  if (head!=nullptr) {
    auto current_node = head;
    while (current_node->has_next()) {
      current_node = current_node->nextnode(); count += 1;
    }
  }
  return count;
};
/*
 * Auxiliary functions
 */
void Node::print() {  // prints out the value of the current node and the count of the node 
  cout << datavalue << ":" << datacount;
  if (has_next()) {
    cout << ", "; next->print();
  }
};

void List::print() {  // prints out the entire linked list
  cout << "List:";
  if (head!=nullptr)  // as long as our list does not reach the end, then print out the value 
    cout << " => "; head->print();
  cout << '\n';
};

/*
 * The homework stuff
 */

void List::insert( int value ) {  // inserts values
  if (head==nullptr) {  // when we begin our linked list
    head = make_shared<Node>(value);  // we insert a new node with a value
  }
};

void Node::insert(int value){  // inserts a new node with a value into our sublist
  if (datavalue == value){  // if our data has a value
    datacount++;  // then increase our datacount by one
  } else{
    if (next != nullptr){  // if it doesn't but our next has a value
      next->insert(value);  // then insert this value in our next
    } else{
      next = make_shared<Node>(value);  // if our next does, then make a new node with a value 
    }
  }
};

bool List::contains_value( int value ) {  // checks to see if our list contains this value
  if (head==nullptr)  // if there is not a value at all then its false
    return false;
  else
    return head->contains_value(value);  // but if it does contain this value then return it
};

bool Node::contains_value( int value) {
  if (datavalue==value)
    // if I contain this value, true
    return true;
  else if (next==nullptr)
    // else, 1. if not tail: false
    return false;
  else
    //       2. return: my tail contains this value
    return next->contains_value(value);
};

int Node::value(){ return datavalue; }  // returns our actual data value calculated earlier

int Node::count(){ return datacount; }  // returns the count of the data value

bool Node::has_next(){ return next != nullptr; }  // our node knows the next value (and it exists)


