// username: nicoleolv
// uteid: no4342

#include <iostream>
#include <cmath>
#include <functional>
#include "cxxopts.hpp"

using namespace std;

double newton_root( function < double(double) > f ) { 
  double x = 1.0;

  double fprime( function<double(double)> f, double x, double h = 1e-6){    // my gradient/fprime function calculates fprime using the finite difference method 
    return (f(x + h) - f(x)) / h;
  };

    while (true){
      auto fx = f(x);
      cout << "f( " << x << " ) = " << fx << '\n';
      if( abs(fx)<1.e-10 ) break;
      x = x - fx/ fprime(x);       
    }
return x;

};



int main( int argc, char** argv){

  cxxopts::Options options
    ("cxxopts",
     "Commandline options demo");
  options.add_options()                  // adds the option to use -v or --num followed by a number (3.14)
    ("v,num","root", cxxopts:: value<int>() ->default_value("1"));
  
  auto result = options.parse(argc, argv); // parsed the command line arguments 
  auto root = result["num"].as<int>();  // receives the command line argument as an integer

  auto f = [num] (double x) { return x*x - num; }; // defines our f to use our newton_root function

  cout << "The root of this number is " << newton_root(f) << '\n';
 
  return 0;
}
