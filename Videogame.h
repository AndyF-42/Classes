//header for Videogame class

#include "Media.h"

class Videogame : public Media {
public:
  char publisher[100];
  char rating[10];

  char* getPublisher();
  char* getRating();
  void setPublisher(char* publisher);
  void setRating(char* rating);

  Videogame();

};
