// Nicole Olvera
// usernmae: nicoleolv
// uteid: no4342

#include <iostream>  // allows access to cin and cout 
#include "linkheader.hpp"  // allows access to our header and implement files

using namespace std;

int main() {
  
  List mylist;  // creates an instance of List and names it 'mylist'
  cout << "Empty list has length: "
       << mylist.length() << '\n';
  cout << '\n';

  mylist.insert(3);
  cout << "After inserting 3 the length is: "
       << mylist.length() << '\n';
  if (mylist.contains_value(3))
    cout << "Indeed: contains 3" << '\n';
  else
    cout << "Hm. Should contain 3" << '\n';
  if (mylist.contains_value(4))
    cout << "Hm. Should not contain 4" << '\n';
  else
    cout << "Indeed: does not contain 4" << '\n';
  cout << '\n';

  mylist.insert(3);
  cout << "Inserting the same item gives length: "
       << mylist.length() << '\n';
  if (mylist.contains_value(3)) {
    cout << "Indeed: contains 3" << '\n';
    auto headnode = mylist.headnode();
    cout << "head node has value " << headnode->value()
         << " and count " << headnode->count() << '\n';
  } else
    cout << "Hm. Should contain 3" << '\n';
  cout << '\n';

  // #if 0
  mylist.insert(2);
  cout << "Inserting 2 goes at the head;\nnow the length is: "
       << mylist.length() << '\n';
  if (mylist.contains_value(2))
    cout << "Indeed: contains 2" << '\n';
  else
    cout << "Hm. Should contain 2" << '\n';
  if (mylist.contains_value(3))
    cout << "Indeed: contains 3" << '\n';
  else
    cout << "Hm. Should contain 3" << '\n';
  cout << '\n';

  mylist.insert(6);
  cout << "Inserting 6 goes at the tail;\nnow the length is: "
       << mylist.length()
       << '\n';
  if (mylist.contains_value(6))
    cout << "Indeed: contains 6" << '\n';
  else
    cout << "Hm. Should contain 6" << '\n';
  if (mylist.contains_value(3))
    cout << "Indeed: contains 3" << '\n';
  else
    cout << "Hm. Should contain 3" << '\n';
  cout << '\n';

  mylist.insert(4);
  cout << "Inserting 4 goes in the middle;\nnow the length is: "
       << mylist.length()
       << '\n';
  if (mylist.contains_value(4))
    cout << "Indeed: contains 4" << '\n';
  else
    cout << "Hm. Should contain 4" << '\n';
  if (mylist.contains_value(3))
    cout << "Indeed: contains 3" << '\n';
  else
    cout << "Hm. Should contain 3" << '\n';
  cout << '\n';

  cout << "List has length: " << mylist.length() << '\n';
  cout << '\n';
  
  {
    cout << "Another check.\n";
    List mylist; 
    for ( auto i : { 15,23,11,75,11,65,3} ) {  // checks through an array of numbers
      cout << "insert: " << i << '\n';
      mylist.insert(i);  // calls the insert method and inserts all the values
    }
  
    mylist.print();  // calls the print method and prints them out 
}
  // interactive input 
  int value;
  while(true){
    cin >> value;

    if (value == 0){
      break;
    }
    mylist.insert(value);  // inserts the values given by the user
    mylist.print();  // prints out the values
    
  }
// #endif

return 0;
}
