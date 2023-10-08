// Nicole Olvera
// username: nicoleolv
// uteid: no4342

#include <iostream>

using namespace std;


int cc(int n){  //created a collatz conjecture function
  int sequence = 0;  // initialized the int that will store the amount numbers in the sequence

  while (n != 1){  // as long as we don't terminate to one we continue
    if (n % 2 == 0){  // if our number n is even, divide it by two
      n = n / 2;
    } else{
      n = 3 * n + 1;  // if our number is not even (odd), multiply by 3 and add one
    }
    sequence++;  // add one to our sequence when we're done going through a number
  }
  return sequence;
}

int main(){

  int maxlength = 0;  // initialzed the int that will store our maxlength of a sequence
  int startingnum = 0;  // stores our starting number of a sequence

  for (int i = 1; i <= 1000; i++){  // loops through starting numbers 1-1000 
    int sequence = cc(i);  // calls the collatz conjecture function
    if (sequence > maxlength){  // if our new sequence is longer than our previous 'maxlength' then our maxlength is now our sequence  
      maxlength = sequence;
      startingnum = i;  
    }
  }

  cout << "The starting number of the longest produced sequence is " << startingnum << endl;

  return 0;

}
