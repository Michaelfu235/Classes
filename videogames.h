/*
 *Author: Michael Fu
 *11/9/2023
 *This is the header file for the videogames child class
 */


#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class videogames: public media{
 public:
  videogames(char* c, int x, char* p, int r);

  //destructor
  ~videogames();

  char* publisher;
  virtual char* getPublisher();
  int rating;
  virtual int getRating();
  virtual void printvg();
};

#endif
