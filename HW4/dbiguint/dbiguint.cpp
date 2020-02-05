#include "dbiguint.h"
#include <string>
#include <cstdlib>
#include <iostream>
dbiguint::dbiguint()
{
    capacity_ = 1;
    data_=new unsigned short [capacity_];
    data_[0]=0;


}

dbiguint::dbiguint(const std::string &s){
  int templeng = s.length();
  capacity_ = templeng;
  data_=new unsigned short [capacity_];
  for(size_t i = 0; i < capacity_; i++){
    data_[i] = s[templeng -i - 1] -'0';
  }
}
  std::size_t dbiguint::size() const
  {
    return capacity_;
  }

unsigned short dbiguint::operator [](std::size_t pos) const{
  unsigned short i = 0;
  if(pos >= 0 && pos < capacity_){
    i = data_[pos];
  }
  return i;
}
 void dbiguint::operator = (const dbiguint & rhs)
 {
   delete [] data_;
   data_ = new unsigned short [rhs.size()];

   for(int i = 0; i< rhs.size(); i++)
   {
     data_[i] = rhs[i];
   }
   capacity_ = rhs.size();

 }


dbiguint::dbiguint(const dbiguint & rhs)
{
  data_ = new unsigned short [rhs.size()];

  for(int i = 0; i< rhs.size(); i++)
  {
    data_[i] = rhs[i];
  }
  capacity_ = rhs.size();
}



std::ostream& operator <<(std::ostream& out, const dbiguint& b)
{
  for (int i = b.size(); i > 0; i--) {
   out<<b[i-1];
 }
 return out;
}
std::istream & operator >> (std::istream& in, dbiguint &b )
{
  std::string s;
  in>>s;
  dbiguint temp(s);
  b  = temp;
  return in;
}


void dbiguint::reserve(std::size_t newcapacity_)
{
  if(newcapacity_<capacity_){
    return;
  }
  else{
    unsigned short *tempdata;
    tempdata = new unsigned short [newcapacity_];
    for (size_t q = 0; q < capacity_; q++) {
      tempdata[q]=data_[q];
    }
    for(size_t i = capacity_; i < newcapacity_; i++){
      tempdata[i]=0;
    }
    capacity_ = newcapacity_;
    delete [] data_;
    data_ = tempdata;
    tempdata = nullptr;
  }
}

void dbiguint::operator += (const dbiguint & b){
  int temp = 0;
  if(capacity_ < b.size()){
    reserve(b.size());
  }
  for (size_t i = 0; i < capacity_; i++) {
    temp = data_[i]+b[i];

    if(temp >= 10){
      if(i == (capacity_ - 1)){
        reserve((capacity_ +1));
      }
      data_[i] = temp-10;
      data_[i+1]++;
    }
    else{
      data_[i]=temp;
    }
  }
}
dbiguint operator + (const dbiguint & lhs, const dbiguint & rhs)
{
  dbiguint result(lhs);
  result += rhs;
  return result;
}
void dbiguint::operator -= (const dbiguint & b)
{
  int temp = 0;
  if(capacity_ < b.size()){
    reserve(b.size());
  }
  for (size_t i = 0; i < capacity_; i++) {
    temp = data_[i]-b[i];

    if(temp < 0){
      if(i == (capacity_ + 1)){
        reserve((capacity_ - 1));
      }
      data_[i] = temp+10;
      data_[i+1]--;
    }
    else{
      data_[i]=temp;
    }
  }
}
dbiguint operator -(const dbiguint & lhs, const dbiguint & rhs)
{
  dbiguint result(lhs);
  result -= rhs;
  return result;
}


int dbiguint::compare(const dbiguint & b) const
{
  return this->toStdString().compare(b.toStdString());
}

bool operator > ( dbiguint & lhs, dbiguint & rhs)
{
  if(lhs.size() > rhs.size())
  {
    return true;
  }
  else if(rhs.size()>lhs.size())
  {
    return false;
  }

  return  lhs.compare(rhs) > 0;

}
bool operator >= ( dbiguint & lhs, dbiguint & rhs)
{
  if(lhs.size() > rhs.size())
  {
    return true;
  }
  else if(rhs.size()>lhs.size())
  {
    return false;
  }

  return  lhs.compare(rhs) >= 0;

}
bool operator < ( dbiguint & lhs, dbiguint & rhs)
{
  if(lhs.size() < rhs.size())
  {
    return true;
  }
  else if(rhs.size()<lhs.size())
  {
    return false;
  }
  return lhs.compare(rhs) < 0;
}
bool operator <= ( dbiguint & lhs, dbiguint & rhs)
{
  if(lhs.size() < rhs.size())
  {
    return true;
  }
  else if(rhs.size()<lhs.size())
  {
    return false;
  }
  return lhs.compare(rhs) <= 0;
}
bool operator == ( dbiguint & lhs, dbiguint & rhs)
{
  return lhs.compare(rhs) == 0;
}
bool operator != ( dbiguint & lhs, dbiguint & rhs)
{

  return lhs.compare(rhs) != 0;
}
std::string dbiguint::toStdString() const
 {
    bool first = false;
    std::string result = "";

    for (int i = (int) this->capacity_ -1; i >= 0; i--) {
        if (this->data_[i] == 0 && !first) {
            if (this->capacity_ == 1)
                result += std::to_string(this->data_[i]);
        }

        else {
            first = true;
            result += std::to_string(this->data_[i]);
        }
    }

    return result;
}

 dbiguint::~dbiguint()
 {
   delete [] data_;
   data_ = nullptr;
   capacity_ = 0;
 }
