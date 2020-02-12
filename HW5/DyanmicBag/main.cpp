#include "dynamicbag.h"
#include "dUSet.h"
#include "dSet.h"

#include <iostream>
#include <cstdlib>
using namespace std;


int main(){


DynamicBag b;
dUSet a;
DynamicBag d;
b.insert(5);
b.insert(70);
b.insert(76);
b.insert(70);
b.insert(3);
for(int i=0; i<5; i++){
    b.insert(i+1);
}

cout<<"Before Erase Duplicates: "<<b<<endl;
 a = dUSet(b);
cout<<"After Erase Duplicates: "<<a<<endl;
a.insert(12);
a.insert(90);
cout<<"Testing insert dUSet: "<<a<<endl;


// d.insert(75);
// d.insert(18);
// for(int i=0; i<5; i++)
//     d.insert(i+1);
// cout<<"Before set: "<<d<<endl;
// 
// 
//dSet c = dSet(d);
// cout<<c<<endl;

return 0;
}
