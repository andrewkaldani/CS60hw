
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
int main(){
  ifstream in("input.txt");
  ofstream output("output.txt");
  vector <string> v;
  string words;
  while(in >> words)
  {
    v.push_back(words);
  }
  in.close();
  sort(v.begin(),v.end());
  for(auto e:v){
    output<<e<<endl;;
  }
  output.close();

  vector<string>v1;
  ifstream input("output.txt");
  ofstream out("outFile.txt");
  string noDup;
  while(input >> noDup)
  {
    v1.push_back(noDup);
  }
  input.close();
  int size = v1.size();
  for(int i =0; i < size; i++)
  {
    if(v1[i] != v1[i+1])
    {
      out<<v1[i]<<endl;
    }
  }
  out.close();

  vector<string>v2;
  ifstream inWord("output.txt");
  ofstream outWord("count.txt");
  string wordCount;
  int count = 1;
  while(inWord >> wordCount)
  {
    v2.push_back(wordCount);
  }
  inWord.close();
  size = v2.size();
  for(int i =0; i < size; i++)
  {
    if(v2[i]==v2[i+1]){
      count++;
    }
    if(v2[i]!=v2[i+1]){
      outWord<<v2[i]<<"  "<<count<<endl;
      count =1;
   }
 }


outWord.close();
  return 0;
}
