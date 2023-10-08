// Nicole Olvera
// username: nicoleolv
// uteid: no4342

#include <iostream>
#include <vector>

using namespace std;

void sorter( const vector<int> &initialvec, vector<int> &oddvec, vector<int> &evenvec ){
  for (int num : initialvec){
    if (num % 2 == 0){
      evenvec.push_back(num);
    } else {
      oddvec.push_back(num);
    }
  }
}


int main(){
  vector<int> initialvec = {5, 6, 2, 4, 5};
  vector<int> oddvec;
  vector<int> evenvec;

  sorter(initialvec, oddvec, evenvec);

  cout << "Odd vector: " << endl;
  for (int num : oddvec){
    cout << num << " " << '\n';
  }
 
  cout << "Even vector: " << endl;
  for (int num : evenvec){
    cout << num << " " << '\n';
  }

  return 0;

}
