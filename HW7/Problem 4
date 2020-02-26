#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
  map<int, pair<int,vector<string> > > v;
  ifstream in("input.txt");
  ofstream out("output.txt");
  string word;
  int index = 0;
  while(in>>index)
  {
    getline(in,word);
    v[index].first++;
    v[index].second.push_back(word);
  }
  for(int i =0; i<=10; i++){
    out << i;
    //cout<<v[i].first<<endl;
    for(int j=0; j<v[i].first; j++){
      out<<'X';
    }
    out<<endl;
  }
  char ans;
  cout<<"Would you like to see the names for a score? Enter Y or y!"<<endl;
  cin>>ans;
  if(ans=='Y'||ans=='y'){
  int answer;
  cout<<"Enter the score: "<<endl;
  cin>>answer;
  cout<<"Check the file it outputs too...to see the names"<<endl;
  //cout<<v[10].second[0]<<endl;
  out<<"People who scored: "<<answer<<endl;
  if(answer<11 && answer>=0){
    for(int i = 0; i<v[answer].first;i++)
      out<<v[answer].second[i]<<endl;

    }
  

  }


