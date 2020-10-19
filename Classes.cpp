#include <iostream>
#include <cstring>
#include "Movie.h"
#include "Music.h"
#include "Videogame.h"
#include <vector>
#define MOVIE 1
#define MUSIC 2
#define VIDEOGAME 3

using namespace std;

void addMedia(vector<Media*>* &vPtr);
void searchMedia(vector<Media*>* vPtr);
void deleteMedia(vector<Media*>* &vPtr);

int main() {
  
  cout << "Welcome to Classes, a database of media." << endl;
  cout << "You can use the commands ADD, SEARCH, DELETE, and QUIT." << endl;

  vector<Media*>* vPtr = new vector<Media*>;
  
  char input[10];
  while (strcmp(input, "QUIT") != 0) {
    cout << ">> ";
    cin >> input;
    
    if (strcmp(input, "ADD") == 0) {
      addMedia(vPtr);
    } else if (strcmp(input, "SEARCH") == 0) {
      searchMedia(vPtr);
    } else if (strcmp(input, "DELETE") == 0) {
      deleteMedia(vPtr);
    } else if (strcmp(input, "QUIT") != 0) {
      cout << "Invalid command. Please use ADD, SEARCH, DELETE, or QUIT." << endl;
    }
  }
  cout << "Goodbye!" << endl;
  return 0;
}

void addMedia(vector<Media*>* &vPtr) {
  char type[10];
  cout << "What type of media would you like to add? (MOVIE, MUSIC, VIDEOGAME)" << endl;
  cin >> type;
  cin.ignore(1000, '\n');
  char title[80];
  int year;
  char director[80];
  char duration[80];
  int rating = 0;
  
  if (strcmp(type, "MOVIE") == 0) {
    
    cout << "Title: ";
    cin.get(title, 80);
    cin.get();
    
    cout << "Year: ";
    cin >> year;
    cin.ignore();
  
    cout << "Director: ";
    cin.get(director, 80);
    cin.get();

    cout << "Duration: ";
    cin.get(duration, 80);
    cin.get();

    cout << "Rating: ";
    cin >> rating;

    Movie* newMovie = new Movie();
    newMovie->setType(MOVIE);
    newMovie->setTitle(title);
    newMovie->setYear(year);
    newMovie->setDirector(director);
    newMovie->setDuration(duration);
    newMovie->setRating(rating);
    vPtr->push_back(newMovie);
    cout << "Movie added." << endl;
    
  } else if (strcmp(type, "MUSIC") == 0) {
    //pass
  } else if (strcmp(type, "VIDEOGAME") == 0) {
    //pass
  } else { //TODO: add a back function?
    cout << "Invalid media type." << endl;
  }

}

void searchMedia(vector<Media*>* vPtr) {
  char input[10];
  cout << "Search by TITLE or YEAR? " << endl;
  cin >> input;
  cin.ignore();

  if (strcmp(input, "TITLE") == 0) {
    char title[80];
    cout << "Title: ";
    cin.get(title, 80);

    for (vector<Media*>::iterator it = vPtr->begin(); it != vPtr->end(); ++it) {
      if (strcmp((*it)->getTitle(), title) == 0) {
	cout << "Match found" << endl;
	if ((*it)->getType() == MOVIE) {
	  cout << "Media Type: Movie" << endl; 
	  cout << "Title: " << (*it)->getTitle() << endl; 
	  cout << "Year: " << (*it)->getYear() << endl; 
	  cout << "Director: " << (dynamic_cast<Movie*>(*it))->getDirector() << endl; 
	  cout << "Duration: " << (dynamic_cast<Movie*>(*it))->getDuration() << endl; 
	  cout << "Rating: " << (dynamic_cast<Movie*>(*it))->getRating() << endl;
	}
      }
    }
    if (vPtr->size() == 0) {
      cout << "[No media]" << endl;
    }
    
  } else if (strcmp(input, "YEAR") == 0) {
    int year;
    cout << "Year: " << endl;
    cin >> year;
    
  } else {
    cout << "Invalid input." << endl;
  }


}

void deleteMedia(vector<Media*>* &vPtr) {
  
  

}

