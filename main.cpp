#include <iostream>
#include <vector>
#include <cstring>
#include "videogames.h"

using namespace std;



int main(){
  vector<media*> listt;


  char* c = new char[80];
  int x = 2020;
  char* p = new char[80];
  int r = 8;
  cin.get(c, 80);
  cin.get(p, 80);
  videogames* testing = new videogames(c,x,p,r);
  listt.push_back(testing);
  cout << listt[0] << endl;
}