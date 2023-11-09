/*
 *Author: Michael Fu
 *11/9/2023
 *this is the header file for the parent media class
 */

#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <cstring>

using namespace std;

class media{
 public:
  media();
  media(char* c, int x);
  //destructor
  ~media();

  //initializing variables and functions
  char* title;
  char* getTitle();
  int year;
  int getyear();

  //prints the title and year
  virtual void printvg();
};

#endif
