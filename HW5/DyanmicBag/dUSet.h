#ifndef DUSET_H
#define DUSET_H
#include <string>
#include <iostream>
#include "dynamicbag.h"


class dUSet: public DynamicBag
{
public:
  // default constructor pre none
  //post empty DynamicBag
dUSet();

dUSet(const DynamicBag &a);


void insert(int target);



};

#endif
