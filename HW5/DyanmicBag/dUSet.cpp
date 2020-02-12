#include "dUSet.h"
#include <vector>
#include <cstdlib>

dUSet::dUSet():DynamicBag()
{}


dUSet::dUSet(const DynamicBag &a ): DynamicBag(a)
{

  size_type size = a.size();
  for(int i = 0; i < size; i++){
  for(int j = i + 1; j < size; j++){
    if(a[i] == a[j]){
      DynamicBag::erase_one(a[i]);
    }
  }
}
}





void dUSet::insert(int target)
{
  DynamicBag::erase(target);
  DynamicBag::insert(target);
}
