#include <iostream>
#include <string>
//no using namespace
class Movie{
private:
std::string name_;
std::string rating_;
double revenue_;
public:
  std::string name(){return name_;}//_ used for ADT style
  std::string rating(){return rating_;}
  double revenue(){return revenue_;}

  Movie(){
    name_ = "";
    rating_ = "";
    revenue_ = 0;
  }
  Movie(std::string n, std::string r, double rev)
  {
    name_=n;
    rating_=r;
    revenue_=rev;
  }
  //pre:none
  //post: Returns a double that is the revenue for each movie how much each movie made
  //It takes in the number of people and multiples it by 12 price for a ticket
  double movieShowing(int n);
  //pre:none
  //post: prints out all the info about the movie
  void print();
  //pre:none
  //post: Combines duplicate movie objects return combined object
  // if the movie has the same name ratings are combined and amounts earned are combined
  //else it returns cannot combine movie
  Movie mergeMovie(Movie m);


};

int main()
{
  Movie in;
  Movie star = Movie("Star Wars", "PG-13", 78);
  star.print();
  Movie avengers= Movie("Avengers: Endgame","PG-13", 100);
  avengers.print();
  Movie joker = Movie("Joker","R",75);
  joker.print();
  Movie toyStory = Movie("Toy Story 4", "G", 68);
  toyStory.print();
  Movie me= Movie("Avengers: Endgame","PG-13", 53);
  Movie lol = Movie("Joker","G",25);
  joker.print();
  me.print();
  in = star.mergeMovie(avengers);
  in.print();
  in = avengers.mergeMovie(me);
  in.print();
  in=joker.mergeMovie(lol);
  in.print();


}
double Movie::movieShowing(int n)
{
   n= revenue_*12.00;
   return n;
}
void Movie::print()
{
double total;
std::cout<<"Movie: "<<name_<<std::endl;
std::cout<<"Rating: "<<rating_<<std::endl;
std::cout<<"Num of People Watched: "<<revenue_<<std::endl;
std::cout<< "Revenue:$ "<<movieShowing(total)<<std::endl;

}
Movie Movie::mergeMovie(Movie m)
{
  Movie r;

  if(name_==m.name_){
    r.revenue_ = revenue_+m.revenue_;
    if(m.rating_ == "R" || rating_=="R")
    {
      r.rating_="R";
    }
    else if(m.rating_ == "PG-13" || rating_=="PG-13")
    {
      r.rating_="PG-13";
    }
    else if(m.rating_ == "PG" || rating_=="PG")
    {
      r.rating_="PG";
    }
    else{
      r.rating_="G";
    }

    r.name_=name_;
  }
  else{
    std::cout<<"COULD NOT COMBINE!!!!"<<std::endl;
  }

  return r;
}
