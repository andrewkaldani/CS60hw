#include "biguint.h"
#include <string>
#include <cstdlib>
#include <iostream>
biguint::biguint()
{
  for(size_t i = 0; i < CAPACITY; i++){
    data_[i]=0;
  }
}

biguint::biguint(const std::string &s){
  int templeng = s.length();
  for(size_t i = 0; i < templeng; i++){
    data_[i] = s[templeng -i - 1] -'0';
  }
  for(size_t i = templeng; i < CAPACITY; i++){
    data_[i]=0;
  }
}

unsigned short biguint::operator [](std::size_t pos) const{
  unsigned short i = 0;
  if(pos >= 0 && pos < CAPACITY){
    i = data_[pos];
  }
  return i;
}
std::ostream& operator <<(std::ostream& out, const biguint& b)
{
  for (int i = biguint::CAPACITY; i > 0; i--) {
    out<<b[i-1];
  }
  return out;
}
void biguint::operator += (const biguint & b){
  int k = 0;
  int temp = 0;
  for (size_t i = 0; i < CAPACITY; i++) {
    temp = data_[i]+b.data_[i];
    if(temp >= 10){
      data_[i] = temp-10;
      data_[i+1]+=1;
    }
    else{
      data_[i]=temp;
    }
  }
}
//+ operator problem Number 2
biguint operator + (const biguint & lhs, const biguint & rhs)
{
  biguint result(lhs);
  result += rhs;
  return result;
}
// problem 3 ==, <, >, <=, >=, and != and compare function
int biguint::compare(const biguint & b) const
{
  return this->toStdString().compare(b.toStdString());
}
// == operator problem number 3
bool operator == (const biguint & lhs,const biguint & rhs)
{
 return lhs.compare(rhs) == 0;
}
//!= operator
bool operator != (const biguint & lhs,const biguint & rhs)
{
  return !(lhs == rhs);
}
// > operator
bool operator > (const biguint & lhs,const biguint & rhs)
{
  return lhs.compare(rhs) > 0;
}
// < exan
bool operator < (const biguint & lhs,const biguint & rhs)
{
  return lhs.compare(rhs) < 0;
}
// <= operator
bool operator <= (const biguint & lhs, const biguint & rhs)
{
    return lhs.compare(rhs) <= 0;
}
// >= operator
bool operator >= (const biguint & lhs, const biguint & rhs)
{
  return lhs.compare(rhs) >= 0;

}
// end of problem 3
// start of problem 4-= and -operator
void biguint::operator -= (const biguint & b)
{
  int temp = 0;
  for (size_t i = 0; i < CAPACITY; i++) {
    temp = data_[i]-b.data_[i];
    if(temp < 0){
      data_[i] = temp -10;
      data_[i+1]-=1;
    }
    else{
      data_[i]=temp;
    }
  }
}
// - operator
biguint operator - (const biguint & lhs, const biguint & rhs)
{
  biguint result(lhs);
  result -= rhs;
  return result;
}
// end of problem 4
// start of last problem
std::string biguint::toStdString() const
 {
    bool first = false;
    std::string result = "";

    for (int i = (int) this->CAPACITY - 1; i >= 0; i--) {
        if (this->data_[i] == 0 && !first) {
            if (this->CAPACITY == 1)
                result += std::to_string(this->data_[i]);
            continue;
        }

        else {
            first = true;
            result += std::to_string(this->data_[i]);
        }
    }

    return result;
}
