/*
 *Author: Michael Fu
 *11/9/2023
 *This is the cpp file for the music child class
 */


#include <iostream>
#include "music.h"

using namespace std;

//creating/setting variables
music::music(char* c, int x, char* a, int dur, char* pub):media(c,x){
  artist = new char[80];
  strcpy(artist,a);
  publisher = new char[80];
  strcpy(publisher,pub);
  duration = dur;
}

//destructor
music::~music(){
  delete[] artist;
  delete[] publisher;
}

//get the artist
char* music::getArtist(){
  return artist;
 
}

//get the duration
int music::getDuration(){
  return duration;
}

//get the publisher
char* music::getPublisher(){
  return publisher;
}

//print the media type and variables
void music::printvg(){
  cout << "music: " << endl;
  cout << endl;
  cout << "Title: " << title << endl;
  cout << "artist: " << artist << endl;
  cout << "year: " << year << endl;
  cout << "duration: " << duration << " seconds" << endl;
  cout << "publisher: " << publisher << endl;
}
