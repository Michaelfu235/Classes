#include <iostream>
#include "videogames.h"

using namespace std;

videogames::videogames(char* c, int x, char* p, int r):media(c,x){
  publisher = new char[80];
  strcpy(publisher,p);
  rating = r;
}

videogames::~videogames(){
  delete[] publisher;
}

char* videogames::getPublisher(){
  return publisher;
}

int videogames::getRating(){
  return rating;
}

void videogames::printvg(){
  cout << "Video Game:" << endl;
  cout << "title: " << title << endl;
  cout << "year: " << year << endl;
  cout << "publisher: " << publisher << endl;
  cout << "rating: " << rating << endl;
}
