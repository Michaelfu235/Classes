#include <iostream>
#include "music.h"

using namespace std;

music::music(char* c, int x, char* a, int dur, char* pub):media(c,x){
  artist = new char[80];
  strcpy(artist,a);
  publisher = new char[80];
  strcpy(publisher,pub);
  duration = dur;
}

music::~music(){
  delete[] artist;
  delete[] publisher;
}

char* music::getArtist(){
  return artist;
 
}

int music::getDuration(){
  return duration;
}

char* music::getPublisher(){
  return publisher;
}

void music::printvg(){
  cout << "music: " << endl;
  cout << "Title: " << title << endl;
  cout << "artist: " << artist << endl;
  cout << "year: " << year << endl;
  cout << "duration: " << duration << " seconds" << endl;
  cout << "publisher: " << publisher << endl;
}