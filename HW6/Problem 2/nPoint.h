#ifndef NPOINT_H
#define NPOINT_H
#include <iostream>
#include <cstdlib>
#include <string>
#include<cmath>

using namespace std;

template <typename T>
class nPoint {
private:
  T arr[10];
  int dimension;
public:
  nPoint();
  nPoint(int d);
  nPoint(int d, T a[]);
  T ith(int i);
  int size(){return dimension;}
  void operator  =(nPoint<T> rhs);
  //void operator +=(nPoint array);
  void operator +=( const nPoint &rhs);


};
  template <typename T>
   nPoint<T>::nPoint()
  {
    dimension = 0;

  }

  template <typename T>
  nPoint<T>::nPoint(int d)
  {
    dimension = d;
    for(int i = 0; i < dimension; i++)
    {
      arr[i]=T();
    }
  }
  template <typename T>
  nPoint<T>::nPoint(int d, T a[])
  {
    dimension = d;
    for(int i = 0; i < dimension; i++)
    {
      arr[i]=a[i];
    }
  }
  template <typename T>
T nPoint<T>::ith(int i){
  return arr[i];
}
  template <typename T>
  //support =
void nPoint<T>::operator  =(nPoint<T> rhs)
{
  dimension = rhs.size();

  for(int i =0; i < size(); i++)
  {
    arr[i] = rhs.ith(i);

  }

}

template <typename T>
//support += and = and <
void nPoint<T>::operator += ( const nPoint &rhs)
{

  if(dimension < rhs.dimension)
	{
		dimension = rhs.dimension;
	}
	for(int i = 0; i < dimension; ++i)
	{
		arr[i] += rhs.arr[i];
	}
}
template<typename T>
// support == <
bool operator ==(nPoint<T> lhs, nPoint<T> rhs)
{
  if(lhs.size()==rhs.size())
  {
    for(int i =0; i < rhs.size(); i++){
      if(lhs.ith(i)==rhs.ith(i)){
        return true;
      }
    }
  }
  return false;
}
template<typename T>
//support += and = and <
nPoint<T> operator +(nPoint<T> lhs, nPoint<T> rhs)
{
  nPoint<T> result(lhs);
  result +=rhs;
  return result;
}
int operator -(string lhs,  string rhs)
{
 return rhs[0]-lhs[0];
}
template<typename T>
//support +=, sqrt, -, *
double distance (nPoint<T> lhs, nPoint<T> rhs)
{
  double sumofSquares = 0;
  for(int i =0; i<lhs.size(); i++){
    sumofSquares += (lhs.ith(i) - rhs.ith(i)) * (lhs.ith(i) - rhs.ith(i));
  }
  return sqrt(sumofSquares);
}
#endif
