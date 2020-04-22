#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>

using namespace std;
int main(){
  ifstream in("input.txt");
  ofstream output("output.txt");
  set <string> s;
  string words;
  while(in >> words)
  {
    s.insert(words);
  }
  in.close();
  for(auto e:s){
    output<<e<<endl;;
  }
  output.close();
return 0;
}
