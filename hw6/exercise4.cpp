// username: nicoleolv
// uteid: no4342

#include <iostream>
#include <cmath>
#include <functional>
#include <vector>

using namespace std;


double newton_root( function < double(double) > f, function <double(double) > fprime ){ double x{1.}; // created the newton_root function that takes two inputs, f and fprime, and outputs a double 
  while (true){                                        // while loop until our estimated value is 1e-10 from our actual value 
    auto fx = f(x);
    cout << "f( " << x << " ) = " << fx << '\n';
    if( abs(fx)<1.e-10 ) break;                        
    x = x - fx/fprime(x);                             // re defines our new x value with our newton method formula
  }
  return x;
};


int main(){

  for (int n = 2; n <= 8; n++){                        // runs a for loop to find the squared root of 2, 3, 4, 5, 6, 7, and 8   
    auto f = [n] ( double x ) { return x*x-n; };
    auto fprime = [n] ( double x ) { return 2*x; };   // use lambda fucntions to capture our n, for each x found previously, using analytical formulas to approximate the square root of a given 'n'
    cout << "sqrt(" << n << ") = " << newton_root( f, fprime)  // prints out our converging approximation of the square root of 'n' by calling our newton_root function 
	 << '\n';
  }

return 0;
}
