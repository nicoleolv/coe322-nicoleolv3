// Nicole Olvera
// username: nicoleolv
// uteid: no4342

#include <iostream>
using std::cin, std::cout;
#include <cmath>

double f(int n) { return abs(n) + 1; }

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

TEST_CASE( "test that f always returns positive" ) {
  int n = 5;
  REQUIRE( f(n) > 0 );
  int p=-1;
  REQUIRE( f(p) > 0 );
}
