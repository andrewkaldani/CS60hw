#include "Atm.h"
Atm::Atm(int t, int ten){
  twenties_=t;
  tens_=ten;
}
Atm::Atm(){
  twenties_= 0;
  tens_= 0;
}
 BankAccount Atm::get_cash(int amount, BankAccount b)
{
  if((amount%10!=0) && !(amount>(twenties_ * 20 + tens_ * 10)))
  {
    std::cout<<"Inavlid amount!!"<<std::endl;
    return b;
  }

  int n1,n2;
  if(amount<=twenties_*20)
  {
    n1 = (amount%20)/10;
    n2 = amount/20;
  }
  else{
    n1 = (amount -(twenties_*20))/10;
    n2 = twenties_;
  }
  twenties_-=n2;
  tens_-=n1;

  std::cout<<"Twenties you will receive: "<<n2<<std::endl;
  std::cout<<"Tens you will recieve: "<<n1<<std::endl;
  b.withdraw(amount);
  return b;

}


void Atm::operator +=(Atm& rhs)
{
  tens_+=rhs.tens_;
  twenties_+=rhs.twenties_;
  rhs.tens_=0;
  rhs.twenties_=0;
}
void Atm::restock(int new20s, int new10s)
{
  twenties_+=new20s;
  tens_+=new10s;
}
bool operator ==(Atm lhs, Atm rhs)
{
  if(lhs.tens()==rhs.tens()&&lhs.twenties()==rhs.twenties())
  {
    return true;
  }
  else{
    return false;
  }
}
std::ostream& operator <<(std::ostream& out, Atm a) {
out<<"Twenties left in ATM: "<<a.twenties()<<std::endl;
out<<"Tens left in ATM: "<<a.tens()<<std::endl;
return out;
}
