#include <iostream>
#include <vector>
#include <cstring>
#include "videogames.h"
#include "movie.h"
#include "music.h"


using namespace std;



int main(){
  vector<media*> listt;


  char* c = new char[80];
  int x = 2020;
  char* p = new char[80];
  int r = 8;

  cin.get(c, 80);
  cin.get();
  cin.get(p, 80);
  cin.get();
  videogames* testing = new videogames(c,x,p,r);
  listt.push_back(testing);

  listt[0]->printvg();

  int dur = 123;
  char* dir = new char[80];
  cin.get(c, 80);
  cin.get();
  cin.get(dir,80);
  cin.get();

    
  movie* test = new movie(c,x,dur,dir,r);
  listt.push_back(test);
  listt[1]->printvg();

  dur = 156;
  char* artist = new char[80];
  char* publisher = new char[80];
  cin.get(artist, 80);
  cin.get();
  cin.get(publisher, 80);
  cin.get();
  
  music* testtt = new music(c,x,artist,dur,publisher);
  listt.push_back(testtt);
  listt[2]->printvg();
}
