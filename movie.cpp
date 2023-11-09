/*
 *Author: Michael Fu
 *11/9/2023
 *This is the cpp file for the movie child class
 */


#include <iostream>
#include "movie.h"

using namespace std;

//creating/setting variables
movie::movie(char* c, int x, int dur, char* dir, int r):media(c,x){
  duration = dur;
  rating = r;
  director = new char[80];
  strcpy(director, dir);
}

//destructor
movie::~movie(){
  delete[] director;
}

//get the duration
int movie::getDuration(){
  return duration;
}

//get the rating
int movie::getRating(){
  return rating;
}

//get the director
char* movie::getDirector(){
  return director;
}

//print the media type and all 4 variables
void movie::printvg(){
  cout << "Movie: " << endl;
  cout << endl;
  cout << "title: " << title << endl;
  cout << "director: " << director << endl;
  cout << "year: " << year << endl;
  cout << "duration: " << duration <<" minutes" << endl;
  cout << "rating: " << rating << endl;
}
