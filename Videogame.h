#include "Media.h"

class Videogame : public Media {
public:
  char publisher[100];
  int rating;

  char* getPublisher();
  int getRating();
  void setPublisher(char publisher[100]);
  void setRating(int rating);


};
