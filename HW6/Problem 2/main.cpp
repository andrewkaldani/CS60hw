#include <iostream>
#include <cstdlib>
#include <string>
#include<cmath>
#include "nPoint.h"

int main (){
  int arr[2] = {3,4};
  nPoint<int> npoint(2,arr);
  cout<<npoint.ith(1) << npoint.size() << endl;
  nPoint<int> test;
  test  = npoint;

  cout<<test.ith(1) << test.size() << endl;

  string str[2] = {"hi","hi",};
  string lol[3]={"lol","pop","mom"};
  string same[2] = {"hi","hi"};
  nPoint<string> p1(2, str);
  nPoint<string> p2(3,lol);
  nPoint<string> point(2,same);

  //p2=p1;
  cout<<"p1==point is "<<(p1==point)<<endl;
  cout<<"Testing + "<<(p1.ith(0)+p2.ith(0))<<" "<<(p1.ith(1)+p2.ith(1))<<" "<<(p1.ith(2)+p2.ith(2))<<endl;
  p1+=p2;
  cout<<"Testing += "<<p1.ith(0)<<" "<<p1.ith(1)<<" "<<p1.ith(2)<<endl;
  int test1[4] ={ 1,2,3,4};
  int test2[4] = {2,3,4,5};
  cout<<distance(p1,p2)<<endl;
  cout<<distance(p2,point)<<endl;
  nPoint<int> p3(4,test1);
  nPoint<int> p4(4,test2);
  cout<<"Testing + with ints "<<(p3.ith(0)+p4.ith(0))<<" "<<(p3.ith(1)+p4.ith(1))<<" "<<(p3.ith(2)+p4.ith(2))<<" "<<(p3.ith(3)+p4.ith(3))<<endl;
  cout<<distance(p3,p4)<<endl;
  p3+=p4;
  cout<<"p3==p4 is "<<(p3==p4)<<endl;
  cout<<"Testing += int's "<<p3.ith(0)<<" "<<p3.ith(1)<<" "<<p3.ith(2)<<" "<<p3.ith(3)<<endl;
 return 0;
}
