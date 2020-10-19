//header for Movie class

#include "Media.h"

class Movie : public Media {
public:
  char director[80];
  char duration[80];
  char rating[10];

  char* getDirector();
  char* getDuration();
  char* getRating();
  void setDirector(char* newDirector);
  void setDuration(char* newDuration);
  void setRating(char* newRating);

  Movie();
  //~Movie();
  
};
