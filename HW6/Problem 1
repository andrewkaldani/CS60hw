#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template <typename T>
T abs(T a, T b);

int main()
{
  int a = 5;
  int b = 2;
  int result=abs(a,b);
  cout<<"result is: "<<result<<endl;
  a = 100;
  b = 20;
  int test = abs(a,b);
  cout<<test<<endl;
}
template <typename T>
// support subtraction and greater than operators
T abs(T a, T b)
{
  T aB = a-b;
  T bA = b-a;
  if(aB>bA){
    return aB;
  }
  else{
    return bA;
  }
}
