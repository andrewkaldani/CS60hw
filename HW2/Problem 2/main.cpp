#include "Atm.h"
#include "bankaccount.h"
using namespace std;


#include <iostream>
int main()
{
  Atm c(5,20);

  BankAccount a(1,250,1,"Andrew");

  a=c.get_cash(120,a);
  cout<<c<<endl;
  Atm d(5,20);
  c+=d;

  cout<<c<<endl;
  cout<<a<<endl;
  if(c==d)
  {
    cout<<"Atm have same amount of cash!"<<endl;
  }
  else{
    cout<<"Atm doesnt have the same amount of cash!"<<endl;
  }

}
