#include <iostream>
#include <cstring>

using namespace std;

void addMedia();
void searchMedia();
void deleteMedia();

int main() {
  
  cout << "Welcome to Classes, a database of media." << endl;
  cout << "You can use the commands ADD, SEARCH, DELETE, and QUIT." << endl;

  char input[10];
  while (strcmp(input, "QUIT") != 0) {
    cout << ">> ";
    cin >> input;
    
    if (strcmp(input, "ADD") == 0) {
      addMedia();
    } else if (strcmp(input, "SEARCH") == 0) {
      searchMedia();
    } else if (strcmp(input, "DELETE") == 0) {
      deleteMedia();
    } else if (strcmp(input, "QUIT") != 0) {
      cout << "Invalid command. Please use ADD, SEARCH, DELETE, or QUIT." << endl;
    }
  }
  cout << "Goodbye!" << endl;
  return 0;
}

void addMedia() {
  char type[10];
  cout << "What type of media would you like to add? (MOVIE, MUSIC, VIDEOGAME)" << endl;
  cin >> type;
  cin.ignore();

  if (strcmp(type, "MOVIE") == 0) {
    char title[80];
    int year;
    char director[80];
    char duration[80];
    int rating = 0;

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

    cout << "Director is " << director << endl;
    cout << "Duration is " << duration << endl;
    cout << "Rating is " << rating << endl;

  } else if (strcmp(type, "MUSIC") == 0) {
    //pass
  } else if (strcmp(type, "VIDEOGAME") == 0) {
    //pass
  } else { //TODO: add a back function?
    cout << "Invalid media type." << endl;
  }

}

void searchMedia() {



}

void deleteMedia() {



}

