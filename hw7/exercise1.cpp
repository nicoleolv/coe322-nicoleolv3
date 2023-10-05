// username: nicoleolv
// uteid: no4342

#include <iostream>
#include <fmt/format.h>  // allows access to the 'fmt' library

using namespace std;

int main(){
  for (int i = 0; i < 16; i++){  // loop to create our 16 rows (from 0 to 15)
    for (int j = 0; j < 16; j++){  // loop to create our 16 columns (from 0 to 15)
      fmt::print("{0:0>2x} ", i*16 + j);  // the fmt library is accessed and specifies that the first argument is 0 and uses padding to pad values with a 0 if the number is not two digits (with right alignment)
      // and prints a hexadecimal value  
    }
    fmt::print("\n");  // a new row is added after one row of 16 'columns' has been created
  }

  return 0;

}
