#include <iostream>
#include "movie.h"

using namespace std;

movie::movie(char* c, int x, int dur, char* dir, int r):media(c,x){
  duration = dur;
  rating = r;
  director = new char[80];
  strcpy(director, dir);
}

movie::~movie(){
  delete[] director;
}

int movie::getDuration(){
  return duration;
}

int movie::getRating(){
  return rating;
}

char* movie::getDirector(){
  return director;
}

void movie::printvg(){
  cout << "Movie: " << endl;
  cout << "title: " << title << endl;
  cout << "director: " << director << endl;
  cout << "year: " << year << endl;
  cout << "duration: " << duration <<" minutes" << endl;
  cout << "rating: " << rating << endl;
}
