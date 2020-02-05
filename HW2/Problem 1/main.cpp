#include "Rational.h"
#include <iostream>
using namespace std;
//To compile the 3-file version, type: g++ main.cpp Rational.cpp
int main(){
  Rational r1 = Rational(3, 4);
  Rational r2(9,12);
  Rational r;
  Rational r3 = r1*r2;
  r3.reduce();
cout<<r1<<" x "<<r2<<" = "<<r3<<endl;//Must return cout to be able to chain <<
  Rational r4= r2+r1;
  r4.reduce();
  cout<<"The sum of the fractions = "<<r4;
  r1.reduce();
  r2.reduce();
  if(r1==r2)
  {
    cout<<"These fractions are equal"<<endl;
  }
  else{
    cout<<"Not equal: "<<endl;
  }
  r2+=r1;
  cout<<"Sum using += operator: "<<r2;
}
