#include <iostream>
#include <vector>
#include <cstring>
#include <iterator>
#include "videogames.h"
#include "movie.h"
#include "music.h"


using namespace std;

void add(vector<media*> &listt);
void search(vector<media*> &listt);
void del(vector<media*> &listt);

int main(){
  vector<media*> listt;

  char inpt[10];
  int numofstuff= 0;
  bool justKeepGoing = true;

  while(justKeepGoing == true){
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
    }else if (strcmp(inpt,"p")==0){
      for(int i = 0;i<listt.size();i++){
	listt[i]->printvg();
      }
    }

    
  }




}


void add(vector<media*> &listt){
  cout << "what type of media would you like to add? videogame(vi), music(mu) or movie(mo)?" << endl;
  char inpat[3];
  cin.get(inpat,3);
  cin.get();
  if(strcmp(inpat,"vi") == 0){
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

    videogames* VG = new videogames(c,x,p,r);
    
    listt.push_back(VG);
    return;
  } else if (strcmp(inpat,"mu") == 0){
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

    music* MU = new music(c,x,a,dur,pub);
    listt.push_back(MU);
    return;

  } else if (strcmp(inpat,"mo") == 0){
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

    movie* MO = new movie(c,x,dur,dir,r);
    listt.push_back(MO);
    return;

  } else {
    cout << "an invalid input was given" << endl;
    return;
  }
}



void search(vector<media*> &listt){
  if(listt.size() == 0){
    cout << "no elements in database" << endl;
    return;
  }
  int search = 0;
  bool found = false;
  
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

  cout << endl;
  for(int i = 0;i<listt.size();i++){
    if(strcmp(listt[i]->getTitle(),title)==0 || listt[i]->getyear()==y){
      listt[i]->printvg();
      cout << endl;
    }
  }
}




void del(vector<media*> &listt){
  if(listt.size() == 0){
    cout << "no elements in database" << endl;
    return;
  }
  int search = 0;
  bool found = false;
  char confirm;

  media* ptr;
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
