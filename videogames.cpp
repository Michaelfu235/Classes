/*
 *Author: Michael Fu
 *11/9/2023
 *This is the cpp file for the videogame child class
 */

#include <iostream>
#include "videogames.h"

using namespace std;

//creating/setting variables
videogames::videogames(char* c, int x, char* p, int r):media(c,x){
  publisher = new char[80];
  strcpy(publisher,p);
  rating = r;
}

//destructor
videogames::~videogames(){
  delete[] publisher;
}

//get publisher
char* videogames::getPublisher(){
  return publisher;
}

//get rating
int videogames::getRating(){
  return rating;
}

//print media type and the 4 variables
void videogames::printvg(){
  cout << "Video Game:" << endl;
  cout << endl;
  cout << "title: " << title << endl;
  cout << "year: " << year << endl;
  cout << "publisher: " << publisher << endl;
  cout << "rating: " << rating << endl;
}
