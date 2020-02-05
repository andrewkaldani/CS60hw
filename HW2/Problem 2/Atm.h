#ifndef ATM_H
#define ATM_H

//ADT Style:  no using namespace std;
#include <iostream>
#include "bankaccount.h"
class Atm{
private:
  int tens_;
  int twenties_;

public:
  Atm(int t, int ten);
  Atm();
  int twenties(){ return twenties_;}
  int tens(){ return tens_;}
  //pre: b and amount  == acount number
  //post prints the amount of bills each returns a modified version of b
  // prints amount of twenties and tens
  BankAccount get_cash(int amount, BankAccount b);
  //pre none
  //post transfers bill to the atm called on to rhs
  void operator +=(Atm& rhs);
  //pre none
  //post adds new bills to the atm machine adds new bills to twenties and tens
  void restock(int new20s, int new10s);
};
 //pre two atm contain same amount of bills
 // returns true if the pre condition is true if both ATM have the same amount
 // of each bill
 bool operator ==(Atm lhs, Atm rhs);
 std::ostream& operator <<(std::ostream& out, Atm a);
