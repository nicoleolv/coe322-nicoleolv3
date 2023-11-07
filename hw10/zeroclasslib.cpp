// Nicole Olvera
// username: nicoleolv
// uteid: no4342

#include <cmath>
#include <vector>
#include "zeroclasslib.hpp"

polynomial::polynomial( std::vector<double> c ){  // object that handles the coefficients of a polynomial in a vector
  if (c.at(0) == 0)  // if the first element of the vector is 0 then
      throw(29);  // if it is equal to 0, throw 29
  }
 coefficients = c;  // renames c to coefficients as used zeroclasstest.cpp
};

bool polynomial::is_odd() const{  // function rejects even degree polynomials
  return coefficients.size() % 2 == 0;  // returns true if the size of the vector is even because the last number in the array has 0th degree
  };

double polynomial::evaluate_at( double x ) const{  // function evaluates the polynomial with an input x
  double result = coefficients[0];  // declares and defines 'result' as the first element in the vector which is the highest degree coefficient
   // uses horner's method by looping through the coefficients vector
   for (int i = 1; i < coefficients.size() - 1; i++){  // iterates from 1 until our 1st degree (from our highest to lowest degree), we subtract one  to take into account our constant term
       result = result*x + coefficients[i];  // multiplies result (which at first is our coefficient of our highest degree) with x and adds the next coefficient to result and keeps doing that for each degree
						  }
return result;  // gives us the final result after it is done evaluating at all degrees
};

// double polynomial::operator()(double x) const{  // already defined in the header file
//  return evaluate_at(x);
// };
void find_initial_bounds( const polynomial& poly, double& left, double &right) {
  // starts with an interval that contains 0
  left = -1.0;  // defines the first left bound as -1
  right = 1.0;  // defines the first right bound as +1

  while( poly(left) * poly(right) > 0 ){  // if they are not enclosing 0
    left -= 1.0;  // then keep expanding the interval (this case I used a step size of 1)
    right += 1.0;
}
};

void move_bounds_closer( const polynomial& poly, double& left, double& right){
  if( poly(left) * poly(right) > 0){  //  if they are not enclosing zero then they are invalid bounds
    throw("Invalid bounds");
  }
  double midpoint;  // initializes midpoint
  double prec;  // initializes precision
  while(right - left > prec){  // starts a while loop that runs as long as the evaluation does not meet the given precision
  midpoint = (right + left)/2;  // midpoint formula
  if(poly(midpoint) == 0.0){  // if the value of our polynomial at our midpoint is 0 (is a root) then WOOO WE FOUND THE ROOT
    break;
  } else if (poly(midpoint) * poly(left) < 0){  // if our midpoint and left\enclose 0 the our midpoint becomes our new right bound
    right = midpoint;
  } else {  // but if our midpoint and left do not enclose zero, then our m\idpoint and right bound HAVE to enclose zero so our midpoint becomes our left bound
    left = midpoint;
  }
  
  }
};

double find_zero( const polynomial& poly, double prec){
  // combined my move_bounds_closer and find_initial_bounds fucntions
  double left = -1.0;
  double right = 1.0;
  
  
  if( poly(left) * poly(right) > 0){
    throw("Invalid bounds");
  }
  
  while( right - left > prec ){
    double midpoint = (right + left)/2;
    if(poly(midpoint) == 0.0){
      break;
    } else if (poly(midpoint) * poly(left) < 0){
      right = midpoint;
    } else {
      left = midpoint;
    }
  }

  return (left + right) / 2;  // finally return the midpoint when we find o\ur zero
};
