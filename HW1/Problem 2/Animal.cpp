#include<iostream>
using namespace std;

struct Animal
{
  string name;
  char gender;
  string type;
  int age;
  int price;
};
Animal cheapest(string type, Animal a[], int size)
{
  Animal min = a[0];
  for(int i=0; i <size; i++)
  {
    if(a[i].price<min.price)
    {
      min=a[i];
    }
  }
  return min;

}
 bool livetogether(Animal a, Animal b)
{
  return ((a.type=="Dog" && b.type=="Dog") || (a.type=="Cat" && b.type=="Cat"));


}
int main()
{
  Animal shelter[1000];
  Animal one;
  one.name = "Dallas";
  one.gender = 'M';
  one.age = 1;
  one.price = 90;
  one.type = "Dog";
  Animal two;
  two.name = "Lucy";
  two.gender = 'F';
  two.age = 4;
  two.price = 25;
  two.type = "Dog";
  Animal three;
  three.name="Cody";
  three.type="Cat";
  three.age = 3;
  three.price=68;
  three.gender = 'M';
  Animal four;
  four.name="Dubbe";
  four.type="Dog";
  four.age = 1;
  four.price=120;
  four.gender = 'M';
  shelter[0]=one;
  shelter[1]=two;
  shelter[2]=three;
  shelter[4]=four;


  Animal inexpensive = cheapest("Dog", shelter, 3);

  cout<<"Here's a perview of our cheapest animal"<<endl;
  cout<<"Name: "<<inexpensive.name<<endl;
  cout<<"Type: "<<inexpensive.type<<endl;
  cout<<"Price:$ "<<inexpensive.price<<endl;
  cout<<"Age: "<<inexpensive.age<<endl;
  cout<<"Gender: "<<inexpensive.gender<<endl;
  cout<<"Want to know if "<<inexpensive.name<<" can live with our other Animals? "<<endl;

  cout<<inexpensive.name<<" and "<<one.name;
  if(livetogether(one,two))
  {
    cout<<" can live together!"<<endl;
  }
  else{
    cout<<" cant live togther!"<<endl;
  }
  cout<<inexpensive.name<<" and "<<three.name;
  if(livetogether(two,three))
  {
    cout<<" can live together!"<<endl;
  }
  else
  {
    cout<<" can't live together!"<<endl;
  }
  cout<<inexpensive.name<<" and "<<four.name;
  if(livetogether(two,four))
  {
    cout<<" can live together!"<<endl;
  }
  else
  {
    cout<<" can't live together!"<<endl;
  }
}
