include <iostream>

using namespace std;
using std::cout;

int cc(int n){
  int sequence = 0;

  while (n != 1){
    if (n % 2 == 0){
      n = n / 2;
    } else{
      n = 3 * n + 1;
    }
    sequence++;
  }
  return sequence;
  return n;
}
int main(){
  int n;
  cout << "Enter a pocitive number between from 1 to 1000: ";
  cin >> n;

  int sequence = cc(n);
  cout << n << '\n';


  return 0;

}
