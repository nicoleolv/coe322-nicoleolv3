// Nicole Olvera
// username: nicoleolv
// uteid: no4342

#include <iostream>
#include <vector>

using namespace std;

void sorter( const vector<int> &initialvec, vector<int> &oddvec, vector<int> &evenvec ){  // function that sorts our given vector into two vectors
  for (int num : initialvec){
    if (num % 2 == 0){  // if our number is even then we add it to the even vector
      evenvec.push_back(num);
    } else {  // if it is not even, we add it to our odd vector
      oddvec.push_back(num);
    }
  }
}


int main(){
  vector<int> initialvec = {5, 6, 2, 4, 5};  // we define our vector
  vector<int> oddvec;
  vector<int> evenvec;

  sorter(initialvec, oddvec, evenvec);  // call our sorter function

  cout << "Odd vector: " << endl;
  for (int num : oddvec){  // loops through the whole odd vector and prints out each number
    cout << num << " " << '\n';
  }
 
  cout << "Even vector: " << endl;
  for (int num : evenvec){  // loops through the whole even vector and prints out each number
    cout << num << " " << '\n';
  }

  return 0;

}
