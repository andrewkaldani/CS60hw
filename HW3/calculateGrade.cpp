#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;


struct Grade
{
  string name;
  double quiz1;
  double quiz2;
  double midterm;
  double final;
  double quizTotal;
  double quizGrade;
  double finalGrade;
  double midGrade;
  double percent;
  char letterGrade;
};

void input(Grade& g);
void calculate(Grade& g);
void letter(Grade& g);
void output(Grade& g);
int main()
{
  Grade g;
  input(g);
  calculate(g);
  letter(g);
  output(g);

}

void input(Grade& g)
{

 cout<<"Enter the students name: ";
 getline(cin,g.name);
 cout << "Enter score for quiz1(max of 10): ";
 cin >> g.quiz1;
 cout << "Enter score for quiz2(max of 10): ";
 cin >> g.quiz2;
 cout << "Enter score for mid term(max of 100): ";
 cin >> g.midterm;
 cout << "Enter score for final term(max of 100): ";
 cin >> g.final;
 return;
}
void calculate(Grade& g)
{
   double mid = g.midterm/100;
   double fin = g.final/100;
   g.quizTotal = (g.quiz1 + g.quiz2)/20;
   g.quizGrade = g.quizTotal * 25;
   g.finalGrade = fin * 50;
   g.midGrade = mid * 25;

   g.percent = g.quizGrade + g.finalGrade + g.midGrade;

}
void letter(Grade& g)
{
  if (g.percent >= 90.0)
    g.letterGrade = 'A';
  else if (g.percent >= 80.0)
    g.letterGrade = 'B';
  else if (g.percent >= 70.0)
    g.letterGrade = 'C';
  else if (g.percent >= 60.0)
    g.letterGrade = 'D';
  else
    g.letterGrade = 'F';
}
void output(Grade& g)
{
  cout<<"Student: "<<g.name<<endl;
  cout<<"Quiz 1 Score: "<<g.quiz1<<endl;
  cout<<"Quiz 2 Score: "<<g.quiz2<<endl;
  cout<<"Midterm Score: "<<g.midterm<<endl;
  cout<<"Final Score: "<<g.final<<endl;
  cout<<"Total Percent: "<<g.percent<<endl;
  cout<<"Letter Grade: "<<g.letterGrade<<endl;




}
