// Nicole Olvera
// username: nicoleolv
// uteid: no4342

#include <memory>
using std::make_shared;
using std::shared_ptr;

class Node; // forward definition
class List {  // declares our class list
private:
  shared_ptr<Node> head{nullptr};  // declares a shared pointer and calls it 'head'
public:
  List() {};
  auto headnode() { return head; };  // declares all of the different methods
  void insert(int value);
  int length();
  int length_iterative();
  bool contains_value(int v);
  void print();
};

class Node {  // defines our class node
private:
  int datavalue{0},datacount{0};  // defines two integers, datacount which stores the amount of data and datavalue which stores the actual value of the data
  shared_ptr<Node> next{nullptr};  // declares a shared pointer and calls it 'next'
public:
  Node() {};
  Node(int value,shared_ptr<Node> next=nullptr)  
    : datavalue(value), datacount(1), next(next) {};  // our Node class contains two integers values and a pointer to the next node
  int value();  // declares all of the different methods
  auto nextnode(){ return next; };
  int length();
  bool contains_value(int v);
  int count();
  bool has_next();
  void insert(int value);
  void print();
};
