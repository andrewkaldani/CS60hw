#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
const int SIZE = 50;
void writeletter(string names[], int size, char letter, ostream& out);
int main()
{
  ifstream in;
  ofstream o;
  string n[SIZE];
  int s=0;



  in.open("input.txt");
  o.open("output.txt");
  if(in.fail())
  {
    cout<<"fail"<<endl;
    exit(1);
  }
  if(o.fail())
  {
    cout<<"fail"<<endl;
    exit(1);
  }
  while (!in.eof())
  {
    in>>n[s];
    s++;
  }
  char l[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  for(int i =0; i<26; i++)
    writeletter(n,s,l[i],o);
  in.close();
  o.close();
  return 0;
}
void writeletter(string names[], int size, char letter, ostream& out)
{
  for(int i = 0; i < size; i++){
    if(names[i][0] == letter)
      out<<names[i]<<endl;
  }


}
