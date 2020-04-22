#include <iostream>
#include "lbag.h"
#include "node.h"

using namespace std;

int main(int argc, char *argv[])
{
  LBag<int> var,a;
  var.insert(3);
  var.insert(2);
  var.insert(1);
  cout<<var<<endl<<endl;
  a.insert(5);
  a.insert(4);
  cout<<"before += and + "<<endl;
  cout<<var<<endl;
  cout<<a<<endl;
  cout<<"a+var  ="<<(var+a)<<endl;
  var+=a;
  cout<<"after += "<<var<<endl;

  cout<<var.erase_one(3)<<endl;
  cout<<"after erase one"<<endl;
  cout<<var<<endl;
  cout<<var.erase(5)<<endl;
  cout<<"after erase "<<var<<endl;
    return 0;
}
