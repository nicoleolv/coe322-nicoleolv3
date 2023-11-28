// Nicole Olvera
// username: nicoleolv
// uteid: no4342

/*
 * NOTE
 * first "module load gcc/11"
 * and   "module load rangev3"
 * then compile this with
 * g++ -I${TACC_RANGEV3_INC} filter.cpp
 */

#include <iostream>
using std::boolalpha;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
using std::any_of;
// #include <ranges>
// NOTE
#include <range/v3/all.hpp>

// Function to check if a number is perfect
bool is_perfect (int number){  
  auto divisors_sum = ranges::accumulate  // used to sum divisors
    (ranges::views::iota(1, number)   // increments by 1 from 1 to input number - 1
     | ranges::views::filter( [number] (int i) {  // filters out divisors 
	 return number % i == 0;  // returns the numbers, i, that are divisible by input 'number'  
       })     
     );

  // --- OR ---
  //bool isPerfect(int num) {
  //  return std::any_of(
  //		       std::begin(std::divisors(num)),
  //		       std::end(std::divisors(num)),
  //		       [num](int divisor) { return divisor != num; }
  //		       ); 
  
  return divisors_sum == number;
}

int main() {

#if 0
  cout << "Filter\n";
  vector<float> numbers
  {1,-2.2,3.3,-5,7.7,-10};
  auto pos_view =
    numbers
    // NOTE: not std::ranges but just `ranges'
    | ranges::views::filter
    ( [] (int i) -> bool {
      return i>0; }
      );
  for ( auto n : pos_view )
    cout << n << " ";
  cout << '\n';
  cout << " .. filter\n";

  cout << "Count\n";
  cout << " .. count\n";
#endif

  cout << "Perfect Numbers:\n";

  vector<int> possible_nums = ranges::views::iota(1,10000)  // generates numbers 1-9999 as possible perfect numbers
    | ranges::to<vector<int>>;  // converts the range into a vector of ints

  auto perfect_numbers = possible_nums | ranges::views::filter(is_perfect);  // filters possible numbers by using the is_perfect function

  for (auto n : perfect_numbers)  // printing perfect numbers
    cout << n << ", \n";

  return 0;
}
