#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class videogames: public media{
 public:
  videogames(char* c, int x, char* p, int r);
  ~videgames();

  char* publisher;
  char* getPublisher();
  int rating;
  int getRating();
  void printvg();
};

#endif
