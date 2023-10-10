// Nicole Olvera
// username: nicoleolv
// uteid: no4342

#include <iostream>
#include <vector>

using namespace std;

bool isprime(int num){  // checks to see if our input 'num' is a prime number
  bool isprime = true;  // starts off as true
 if (num <= 1) {
   isprime = false;
 } else {
   for(int divisor = 2; divisor <= num/2; divisor++){  // for loop goes through numbers to check divisibility
     if(num % divisor == 0){
       isprime = false;
       break; // exiting the loop once a divisor is found
     }
   }

 }

 return isprime;
}

class primegenerator{

public:
  int num_primes = 0; // stores the amount of prime numbers found
  int current = 2; // stores the current prime number which begins at 2

  int number_of_primes_found() const{
  return num_primes;
  }

  int nextprime(){ // method counts the next prime number
    while (true) {
      if (isprime(current)){
        num_primes++;
        return current++;
      }
      current++;

    }
  }

};


int main(){
  int bound;  // stores our upper bound of even numbers entered by the user
  cout << "Enter a bound ";
  cin >> bound;
  
  primegenerator sequence;  // begins an instance of the primegenerator called sequence
  vector<int> primes;  // will store the generated primes for the given even number 

  while (sequence.nextprime() <= bound){  // while loop adds primes to our vector 'primes' until a prime that is greater than the bound is generated
    primes.push_back(sequence.current - 1);  // subtract by one to get our last prime number that is less than or equal to our bound
  }

  for (int e = 4; e <= bound; e += 2){  // loops through even numbers (starting at 4) up to the given bound 
    cout << "The number " << e << " is ";
    for (int p : primes){  // loops through the vector 'primes' 
      if (isprime(e - p)){  // and checks to see if our bound, e, minus our prime, p, is a prime number, q
	cout << p << "+" << (e - p) << '\n';
	break;
      }
    }
  }

  return 0;
}


  
