#include "dbiguint.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  dbiguint one("900");
  dbiguint two("8000");
  dbiguint three("900");
  dbiguint four("900");
  dbiguint five("450");
  dbiguint six("60");
  dbiguint seven("950");
  dbiguint eight("950");
  dbiguint nine(one);
  dbiguint ten("235");
  dbiguint ele("75");
  dbiguint twe;
  twe = ele;
  cout<<"eleven = 75 two now equals "<<twe<<endl;
  cout<<"Copy constructor "<<nine<<endl;
  
  cout<<"900+8000 = "<<(one+two)<<endl;
  cout<<"900>8000  "<<(one>two)<<endl;
  cout<<"900>=900  "<<(three>=four)<<endl;
  cout<<"900<8000  "<<(one<two)<<endl;
  cout<<"450<=60   "<<(five<=six)<<endl;
  cout<<"950==950  "<<(seven==eight)<<endl;
  cout<<"950!= 950 "<<(seven!=eight)<<endl;
  cout<<"950+950 = "<<(seven+eight)<<endl;
  cout<<"900!= 450 "<<(three!=five)<<endl;
  
  one+=two;
  cout<<"900+8000 = "<<one<<endl;

  five -= six;
  cout<<"450-60 = "<<five<<endl;
  cout<<"235-75 = "<<(ten-ele)<<endl;

  return 0;
}
