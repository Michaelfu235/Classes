#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <cstring>

using namespace std;

class media{
 public:
  media();
  media(char* c, int x);
  ~media();

  char* title;
  char* getTitle();
  int year;
  int getyear();
  virtual void printvg();
};

#endif
