#include <iostream>
#include <cstdlib>
#include <ctime>
void reverse(int a[], int first, int last);
using namespace std;

int main(){
srand(time(0));
int a[5];
for(int i = 0; i < 5; i++)
  a[i] = rand()%100;

for(int i = 0; i < 5; i++){
  cout<<a[i]<<" ";
}
cout<<endl;

reverse(a,0,4);
cout<<"after swap "<<endl;
for(int i =0; i < 5; i++){
  cout<<a[i]<<" ";
}
cout<<endl;
return 0;

}

void reverse(int a[], int first, int last){
  if(first>=last){
    return;
  }
  else{
    int temp = a[first];
    a[first]  = a[last];
    a[last] = temp;
    reverse(a,first+1,last-1);
  }
}
