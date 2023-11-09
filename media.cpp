/*
 *Author: Michael Fu
 *11/9/2023
 *This is the cpp file for the parent media class
 */
#include <iostream>
#include "media.h"

using namespace std;

media::media(){
  title = new char[80];
}

//create/set variables for media
media::media(char* c, int x){
  title = new char[80];
  strcpy(title, c);
  year = x;
}

//destructor
media::~media(){
  delete[] title;
}

//get title
char* media::getTitle(){
  return title;
}

//get year
int media::getyear(){
  return year;
}

//print the title and year
void media::printvg(){
    cout << "Title: " << title << endl;
    cout << "Year: " << year << endl;
}
