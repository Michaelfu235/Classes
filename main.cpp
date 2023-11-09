/*
 *Author: Michael Fu
 *11/9/2023
 *This is the main cpp file for the classes assignment in c++
 */


#include <iostream>
#include <vector>
#include <cstring>
#include <iterator>
#include "videogames.h"
#include "movie.h"
#include "music.h"


using namespace std;

//declare functions
void add(vector<media*> &listt);
void search(vector<media*> &listt);
void del(vector<media*> &listt);

int main(){
  //create the vector of the parent classes(medias)
  vector<media*> listt;

  //create a char list for the input and a boolean to check whether or not to keep going
  char inpt[10];
  
  bool justKeepGoing = true;

  while(justKeepGoing == true){
    //while justkeepgoing is true, ask wether they would like to add, search delete or quit and call a function depending on their response. If they respond q, then set justkeepgoing to false. 
    cout << "would you like to add(a), search(s), delete(d) or quit (q)?" << endl;
    cin.get(inpt,10);
    cin.get();
    if(strcmp(inpt,"a") == 0){
      add(listt);
    } else if (strcmp(inpt,"s")==0){
      search(listt);
    } else if (strcmp(inpt,"d")==0){
      del(listt);
      
    } else if (strcmp(inpt,"q")==0){
      justKeepGoing=false;
    }

    
  }




}


void add(vector<media*> &listt){
  //when the add function is called, ask what type of media they want and input their resposne
  cout << "what type of media would you like to add? videogame(vi), music(mu) or movie(mo)?" << endl;
  char inpat[3];
  cin.get(inpat,3);
  cin.get();
  if(strcmp(inpat,"vi") == 0){
    //if they responded with vi (videogame) initialize the variables and for each piece of data prompt for input and save their response in the variable. 
    char* c = new char[80];
    int x;
    char* p = new char[80];
    int r;

    cout << "title?" << endl;
    cin.get(c,80);
    cin.get();
    
    cout << "year?" << endl;
    cin >> x;
    cin.get();
    cout << "publisher?" << endl;
    cin.get(p,80);
    cin.get();
    cout << "rating?" << endl;
    cin >> r;
    cin.get();

    //create a videogames with the saved variabels and push that new videogame into the vector
    videogames* VG = new videogames(c,x,p,r);
    
    listt.push_back(VG);
    return;
  } else if (strcmp(inpat,"mu") == 0){
    //if they responded with "mu" (music) initialize the variables and for eachh piece of data prompt for nput and save their response in the variable
    char* c = new char[80];
    int x;
    char* a = new char[80];
    int dur;
    char* pub = new char[80];

    cout << "title?" << endl;
    cin.get(c,80);
    cin.get();
    cout << "year?" << endl;
    cin >> x;
    cin.get();
    cout << "artist?" << endl;
    cin.get(a,80);
    cin.get();
    cout << "duration?" << endl;
    cin >> dur;
    cin.get();
    cout << "publisher?" << endl;
    cin.get(pub,80);
    cin.get();

    //create a music with the saved variables and push that new music into the vector
    music* MU = new music(c,x,a,dur,pub);
    listt.push_back(MU);
    return;

  } else if (strcmp(inpat,"mo") == 0){
    //if they responded with mo(movie) initialize the variables and for each piece of data, prompt for input and save their responses in the variables
    char* c = new char[80];
    int x;
    int dur;
    char* dir = new char[80];
    int r;

    cout << "title?" << endl;
    cin.get(c,80);
    cin.get();
    cout << "year?" << endl;
    cin >> x;
    cin.get();
    cout << "duration?" << endl;
    cin >> dur;
    cin.get();
    cout << "director?" << endl;
    cin.get(dir,80);
    cin.get();
    cout << "rating?" << endl;
    cin >> r;
    cin.get();

    //create a movie with the saved variables and push that new movie into the vector
    movie* MO = new movie(c,x,dur,dir,r);
    listt.push_back(MO);
    return;

  } else {
    cout << "an invalid input was given" << endl;
    return;
  }
}



void search(vector<media*> &listt){
  //when the ssearch function is called, check if there are elemets in the database. 
  if(listt.size() == 0){
    cout << "no elements in database" << endl;
    return;
  }
  int search = 0;
  bool found = false;

  //ask wether they are looking by title or year. 
  cout << "are you loking by title(t) or year(y)?" << endl;
  char searcher;
  cin >> searcher;
  cin.get();
  int y;
  char* title = new char[80];
  //create variables for the year and title and input the title or year depending on what they responded in the previous prompt
  cout << "what is the title/year that you are looking for?" << endl;
  if(searcher=='t'){
    cin.get(title,80);
    cin.get();
  } else if(searcher == 'y'){
    cin >> y;
    cin.get();
  } else {
    //if they didnt respond with one of the right answers, then say so
    cout << "you did not enter a t or a y" << endl;
    return;
    
  }

  //go through the vector of media files and if the title matches the saved title/title they are looking for OR the year matches the year they are looking for, then call the print function on that media file. 
  cout << endl;
  for(int i = 0;i<listt.size();i++){
    if(strcmp(listt[i]->getTitle(),title)==0 || listt[i]->getyear()==y){
      listt[i]->printvg();
      cout << endl;
    }
  }
}




void del(vector<media*> &listt){
  //when the delete function is called, check to see if there are elements in the database
  if(listt.size() == 0){
    cout << "no elements in database" << endl;
    return;
  }
  int search = 0;
  bool found = false;
  char confirm;

  media* ptr;
  //after initializing variables, ask if they are looking for title or year and save the variable they enter, same as the search function. 
  cout << "are you loking by title(t) or year(y)?" << endl;
  char searcher;
  cin >> searcher;
  cin.get();
  int y;
  char* title = new char[80];
  cout << "what is the title/year that you are looking for?" << endl;
  if(searcher=='t'){
    cin.get(title,80);
    cin.get();
  } else if(searcher == 'y'){
    cin >> y;
    cin.get();
  } else {
    cout << "you did not enter a t or a y" << endl;
    return;

  }
  vector<media*>::iterator i;
  int temp = 0;

  //go through the vector and for each variable, if the title or year matches the title/year that the user wants to delete, output to check if they want to delete that file. If they do want to delete the file, erase it from the vector and delete the data. 
  cout << endl;
  for(i = listt.begin();i<listt.end();){
    ptr = *i;
    if(strcmp(ptr->getTitle(),title)==0 || ptr->getyear()==y){
      cout << endl;
      cout << "do you want to delete this(y/n):" << endl;
      ptr->printvg();
      cin >> confirm;
      cin.get();
      if(confirm=='y'){
	cout << ptr->getTitle() << " has been deleted" << endl;
	listt.erase(i);
	delete ptr;
		
      } else {
	i++;
      }
    } else {
      i++;
    }
  }
  


}
