// Nicole Olvera
// username: nicoleolv
// uteid: no4342

#include <iostream>

using namespace std;


int cc(int n){
  int sequence = 0;

  while (n != 1){
    if (n % 2 == 0){
      n = n / 2;
    } else{
      n = 3 * n + 1;
    }
    sequence++;
  }
  return sequence;
}

int main(){

  int maxlength = 0;
  int startingnum = 0;

  for (int i = 1; i <= 1000; i++){
    int sequence = cc(i);
    if (sequence > maxlength){
      maxlength = sequence;
      startingnum = i;
    }
  }

  cout << "The starting number of the longest produced sequence is " << startingnum << endl;

  return 0;

}
