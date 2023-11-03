#include <iostream>
#include "media.h"

using namespace std;

media::media(){
  title = new char[80];
}

media::media(char* c, int x){
  title = new char[80];
  strcpy(title, c);
  year = x;
}

media::~media(){
  delete[]title;
}

char* media::getTitle(){
  return title;
}

int media::getyear(){
  return year;
}

void media::printvg(){
    cout << "Title: " << title << endl;
    cout << "Year: " << year << endl;
}
