/*
 *Author: Michael Fu
 *11/9/2023
 *This is the header file for the movie child class
 */


#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class movie: public media{
 public:
  movie(char* c, int x, int dur, char* dir, int r);

  //destructor
  ~movie();

  int duration;
  virtual int getDuration();
  int rating;
  virtual int getRating();
  char* director;
  virtual char* getDirector();
  virtual void printvg();
};

#endif
