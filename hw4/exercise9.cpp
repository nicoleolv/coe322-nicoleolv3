#include <iostream>

using namespace std;

bool isprime(int num){ // checks to see if our input 'num' is a prime number
  bool isprime = true;

 if (num <= 1) {
   isprime = false;
   cout << num << " is not a prime number" << endl;
 } else
   {
     for(int divisor = 2; divisor <= num/2; divisor++){  // for loop goes through numbers to check divisibility
       if(num % divisor == 0){
	 isprime = false;
	 break; // exiting the loop once a divisor is found
       }
     }
     if (isprime){
       cout << num << " is a prime number" << endl;
     } else{
       cout << num << " is not a prime number" << endl;
     }

   }

 return isprime;
}

class primegenerator{

public:
  int num_primes = 0; // initialze number_of_primes_found which stores the amount of prime numbers found
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
  int nprimes;
  cin >> nprimes;

  primegenerator sequence;

  while (sequence.number_of_primes_found() < nprimes){
    int number = sequence.nextprime();
    cout << "Number " << number << " is prime"<< '\n';
 }

  return 0;
}
