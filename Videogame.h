#include "Media.h"

class Videogame : public Media {
public:
  char publisher[100];
  int rating;

  char* getPublisher();
  int getRating();
  void setPublisher(char* publisher);
  void setRating(int rating);

  Videogame();

};
