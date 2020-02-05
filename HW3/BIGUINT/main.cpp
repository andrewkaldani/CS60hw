#include "biguint.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  biguint one("210");
  cout<<one<<endl;
  biguint two("200");
  cout<<two<<endl;
  cout<<(one == two)<<endl;

  cout<<(one!=two)<<endl;
  cout<<(one>two)<<endl;
  cout<<(one<two)<<endl;
  cout<<(one<=two)<<endl;
  cout<<(one>=two)<<endl;
  cout<<(one==one)<<endl;
  cout<<one.toStdString()<<endl;

  cout<<(one-two)<<endl;
  cout<<(one+one)<<endl;
  cout<<(one-one)<<endl;

  one-=two;
  cout<<one<<endl;
  cout<<two<<endl;
  cout<<(two<one)<<endl;
 cout<<(one<two)<<endl;
 cout<<(two>one)<<endl;
  cout<<(one!=two)<<endl;
  cout<<(one+two)<<endl;
  one+=two;
  cout<<one<<endl;
  int i = two[1];
  std::cout << i << '\n';

}
