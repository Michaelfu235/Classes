#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class music: public media{
 public:
  music(char* c, int x, char* a, int dur, char* pub);
  ~music();

  char* artist;
  virtual char* getArtist();
  int duration;
  virtual int getDuration();
  char* publisher;
  virtual char* getPublisher();
  virtual void printvg();
};
#endif
