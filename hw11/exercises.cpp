// Nicole Olvera
// username: nicoleolv
// uteid: no4342

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
#include <string>

template <typename T>  // template namedvector using variable T
class namedvector
  : public std::vector<T> {  // inherits from standard vector but instead of taking int's, it takes a templated variable T 
private:
  std::string _name;  // initializes a string variable, _name
public:
  namedvector
  ( std::string n,int s )  // the constructor takes a string, n, and an int,s for size
    : _name(n)
    ,std::vector<T>(s) {};  // initializes sub class that takes T variable type with size s  
  auto name() {  // member function name that returns a string, _name
    return _name; };
};


namespace geo{  // defines a namespace geo
  template <typename T>  // templates vector, T, inside the namespace 
  class vector : public std::vector<T> {  // inherits from standard vector just like namedvector
  private:
    std::string _name;  // does the same thing as namedvector
  public:
    vector(std::string n, int s) : _name(n), std::vector<T>(s){};
    auto name() { return _name; };
  };
}

int main() {

  namedvector<float> fivetemp("five",5);
  fivetemp.at(0) = 3.14;
  cout << fivetemp.name()
       << ": "
       << fivetemp.size() << '\n';
  cout << "at zero: "
       << fivetemp.at(0) << '\n';

  using namespace geo;
  geo::vector<float> float4("four",4);
  cout << float4.name() << '\n';
  float4[1] = 3.14;
  cout << float4.at(1) << '\n';
  geo::vector<std::string> string3("three",3);
  string3.at(2) = "abc";
  cout << string3[2] << '\n';

  return 0;
}
