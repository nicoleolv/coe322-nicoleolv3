// username: nicoleolv
// uteid: no4342

#include <iostream>
#include <fmt/format.h>

using namespace std;

int main(){
  for (int i = 0; i < 16; i++){
    for(int j = 0; j < 16; j++){
      int x = i*16 + j;
      fmt::print("{0:0>2}\n", x );
    }
    fmt::print("\n");
  }
  return 0;

}
