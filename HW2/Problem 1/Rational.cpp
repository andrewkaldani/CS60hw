Enable desktop notifications for Santa Clara University Mail.
   OK  No thanks

11 of 61
HW2 Problem 1 Kaldani 00001580471

Andrew Kaldani <akaldani@scu.edu>
Attachments
Jan 22, 2020, 3:56 PM (13 days ago)
to cs60scu


3 Attachments

#include "Rational.h"

Rational::Rational(int n, int d){//We need the Rational:: because it looks like we're defining this at the global scope, but it BELONGS in Rational's scope.
  numer_ = n;
  denom_ = d;
}
Rational::Rational(){
  numer_ = 0;
  denom_ = 1;
}

Rational operator *(Rational a, Rational b){
    Rational ans(a.numer()*b.numer(), a.denom()*b.denom());
    return ans;
}

void Rational::operator *=(Rational b){
    numer_ = (numer_*b.numer_);
    denom_ = (denom_*b.denom_);
}
Rational operator +(Rational a, Rational b){
  Rational ans((a.numer()*b.denom()+b.numer()*a.denom()), (a.denom()*b.denom()));
  return ans;
}

std::ostream& operator <<(std::ostream& out, Rational a){
  out<<a.numer()<<"/"<<a.denom()<<std::endl;
  return out;
}

void Rational:: operator +=(Rational rhs)
{
  numer_ = (rhs.numer()*denom_)+(rhs.denom()*numer_);

  denom_ = denom_*rhs.denom();
//  numer_ = (numer_*rhs.denom())+(rhs.numer()*denom_);
  reduce();
  reduce();
}

void Rational::reduce()
{

  int r;
  if(denom_%numer_==0)
  {
    denom_=denom_/numer_;
    numer_=numer_/numer_;
  }

  else {

    r = denom_%numer_;

    if(denom_%r==0 && numer_%r==0)
    {

      denom_=denom_/r;
      numer_ = numer_/r;
    }
      else{
        for(int i =1; i<denom_/2; i++)
        {


        if((numer_%i==0) && (denom_%i==0)){
            r=i;
          }

        }

        numer_=numer_/r;
        denom_=denom_/r;

    // else{
    //   r=r/2;
    //   numer_= numer_/r;
    //   denom_ = denom_/r;
    // }

    }
  }
}
bool operator ==(Rational a, Rational b){

 return (a.numer()*b.denom() == b.numer()*a.denom());
}
