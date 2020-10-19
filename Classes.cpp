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

//main function, everything starts here
int main() {
  
  cout << "Welcome to Classes, a database of media." << endl;
  cout << "You can use the commands ADD, SEARCH, DELETE, and QUIT." << endl;

  vector<Media*>* vPtr = new vector<Media*>; //vector pointer of parent Media pointers
  
  char input[10];
  while (strcmp(input, "QUIT") != 0) { //get input, leave loop on QUIT command
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

//add media entry to vector
void addMedia(vector<Media*>* &vPtr) {
  char type[10];
  cout << "What type of media would you like to add? (MOVIE, MUSIC, VIDEOGAME)" << endl;
  cin >> type;
  cin.ignore();

  char title[80];
  int year;

  if (strcmp(type, "MOVIE") == 0) { //adding a movie

    char director[80];
    char duration[80];
    char rating[10];
    
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

    cout << "Rating (G, PG, PG-13, R, NC-17, or NR): ";
    cin.get(rating, 10);
    cin.get();

    //setting up the variables into a Movie class to add to vector
    Movie* newMovie = new Movie();
    newMovie->setType(MOVIE);
    newMovie->setTitle(title);
    newMovie->setYear(year);
    newMovie->setDirector(director);
    newMovie->setDuration(duration);
    newMovie->setRating(rating);
    vPtr->push_back(newMovie);
    cout << "Movie added." << endl;
    
  } else if (strcmp(type, "MUSIC") == 0) { //adding music

    char artist[80];
    char duration[80];
    char publisher[80];
    
    cout << "Title: ";
    cin.get(title, 80);
    cin.get();
    
    cout << "Year: ";
    cin >> year;
    cin.ignore();
  
    cout << "Artist: ";
    cin.get(artist, 80);
    cin.get();

    cout << "Duration: ";
    cin.get(duration, 80);
    cin.get();

    cout << "Publisher: ";
    cin.get(publisher, 80);
    cin.get();

    //setting up the variables into a Music class to add to vector
    Music* newMusic = new Music();
    newMusic->setType(MUSIC);
    newMusic->setTitle(title);
    newMusic->setYear(year);
    newMusic->setArtist(artist);
    newMusic->setDuration(duration);
    newMusic->setPublisher(publisher);
    vPtr->push_back(newMusic);
    cout << "Music added." << endl;
    
  } else if (strcmp(type, "VIDEOGAME") == 0) { //adding Videogame

    char publisher[80];
    char rating[10];
    
    cout << "Title: ";
    cin.get(title, 80);
    cin.get();
    
    cout << "Year: ";
    cin >> year;
    cin.ignore();
  
    cout << "Publisher: ";
    cin.get(publisher, 80);
    cin.get();

    cout << "Rating (E, E10+, EC, T, M, RP, or AO): ";
    cin.get(rating, 10);
    cin.get();

    //setting up the variables into a Videogame class to add to vector
    Videogame* newVideogame = new Videogame();
    newVideogame->setType(VIDEOGAME);
    newVideogame->setTitle(title);
    newVideogame->setYear(year);
    newVideogame->setPublisher(publisher);
    newVideogame->setRating(rating);
    vPtr->push_back(newVideogame);
    cout << "Videogame added." << endl;
    
  } else {
    cout << "Invalid media type." << endl;
  }

}

//search the vector for a specific media (given title or year)
void searchMedia(vector<Media*>* vPtr) {
  //get whether searching by title or year
  char input[10];
  cout << "Search by TITLE or YEAR? " << endl;
  cin >> input;
  cin.ignore();
  char title[80];
  int year;
  
  if (strcmp(input, "TITLE") == 0) {
    cout << "Title: ";
    cin.get(title, 80);
  } else if (strcmp(input, "YEAR") == 0) {
    cout << "Year: ";
    cin >> year;
  } else {
    cout << "Invalid input." << endl;
  }

  //iterator for vector, with bool to track if we actually find something
  bool mediaFound = false;
  for (vector<Media*>::iterator it = vPtr->begin(); it != vPtr->end(); ++it) {

    //will enter the if statement if the titles match and they are searching
    //by title, or if the years match and they are searching by year
    if ((strcmp((*it)->getTitle(), title) == 0 && strcmp(input, "TITLE") == 0) ||
	((*it)->getYear() == year && strcmp(input, "YEAR") == 0)) {

      mediaFound = true;
      cout << endl;
      if ((*it)->getType() == MOVIE) { //matching movie found
	cout << "Media Type: Movie" << endl; 
	cout << "Title: " << (*it)->getTitle() << endl; 
	cout << "Year: " << (*it)->getYear() << endl; 
	cout << "Director: " << (dynamic_cast<Movie*>(*it))->getDirector() << endl; 
	cout << "Duration: " << (dynamic_cast<Movie*>(*it))->getDuration() << endl; 
	cout << "Rating: " << (dynamic_cast<Movie*>(*it))->getRating() << endl;
      } else if ((*it)->getType() == MUSIC) { //matching music found
	cout << "Media Type: Music" << endl; 
	cout << "Title: " << (*it)->getTitle() << endl; 
	cout << "Year: " << (*it)->getYear() << endl; 
	cout << "Artist: " << (dynamic_cast<Music*>(*it))->getArtist() << endl; 
	cout << "Duration: " << (dynamic_cast<Music*>(*it))->getDuration() << endl; 
	cout << "Publisher: " << (dynamic_cast<Music*>(*it))->getPublisher() << endl;
      } else if ((*it)->getType() == VIDEOGAME) { //matching videogame found
	cout << "Media Type: Videogame" << endl; 
	cout << "Title: " << (*it)->getTitle() << endl; 
	cout << "Year: " << (*it)->getYear() << endl; 
	cout << "Publisher: " << (dynamic_cast<Videogame*>(*it))->getPublisher() << endl; 
	cout << "Rating: " << (dynamic_cast<Videogame*>(*it))->getRating() << endl;
      }
    }
  }
  if (!mediaFound) { //never found a matching media (or no media exists)
    cout << "Could not find media." << endl;
  }
}

//deletes a media element from the vector
void deleteMedia(vector<Media*>* &vPtr) {
  //get whether searching by title or year
  char input[10];
  cout << "Delete by TITLE or YEAR? " << endl;
  cin >> input;
  cin.ignore();
  char title[80];
  int year;
  
  if (strcmp(input, "TITLE") == 0) {
    cout << "Title: ";
    cin.get(title, 80);
  } else if (strcmp(input, "YEAR") == 0) {
    cout << "Year: ";
    cin >> year;
  } else {
    cout << "Invalid input." << endl;
  }
  
  //iterator for vector, with bool to track if we actually find something
  int index = 0;
  bool mediaFound = false;
  for (vector<Media*>::iterator it = vPtr->begin(); it != vPtr->end(); ++it) {
 
    //will enter the if statement if the titles match and they are searching
    //by title, or if the years match and they are searching by year
    if ((strcmp((*it)->getTitle(), title) == 0 && strcmp(input, "TITLE") == 0) ||
	((*it)->getYear() == year && strcmp(input, "YEAR") == 0)) {

      mediaFound = true;
      cout << endl;
      if ((*it)->getType() == MOVIE) {
	cout << "Media Type: Movie" << endl; 
	cout << "Title: " << (*it)->getTitle() << endl; 
	cout << "Year: " << (*it)->getYear() << endl; 
	cout << "Director: " << (dynamic_cast<Movie*>(*it))->getDirector() << endl; 
	cout << "Duration: " << (dynamic_cast<Movie*>(*it))->getDuration() << endl; 
	cout << "Rating: " << (dynamic_cast<Movie*>(*it))->getRating() << endl;
      } else if ((*it)->getType() == MUSIC) {
	cout << "Media Type: Music" << endl; 
	cout << "Title: " << (*it)->getTitle() << endl; 
	cout << "Year: " << (*it)->getYear() << endl; 
	cout << "Artist: " << (dynamic_cast<Music*>(*it))->getArtist() << endl; 
	cout << "Duration: " << (dynamic_cast<Music*>(*it))->getDuration() << endl; 
	cout << "Publisher: " << (dynamic_cast<Music*>(*it))->getPublisher() << endl;
      } else if ((*it)->getType() == VIDEOGAME) {
	cout << "Media Type: Videogame" << endl; 
	cout << "Title: " << (*it)->getTitle() << endl; 
	cout << "Year: " << (*it)->getYear() << endl; 
	cout << "Publisher: " << (dynamic_cast<Videogame*>(*it))->getPublisher() << endl; 
	cout << "Rating: " << (dynamic_cast<Videogame*>(*it))->getRating() << endl;
      }
      //media was found and printed, check if this is the one to delete
      char checkDelete;
      cout << "Delete this entry? (y/n): ";
      cin >> checkDelete;
      if (checkDelete == 'y') {
	delete (*vPtr)[index];
	vPtr->erase(it);
	cout << "Media deleted." << endl;
	break; //if they delete the media, the iterator is thrown off, so we need to break
      }
    }
    index++;
  }
  if (!mediaFound) { //did not find matching media (or no media exists)
    cout << "Could not find media." << endl;
  }  
}

