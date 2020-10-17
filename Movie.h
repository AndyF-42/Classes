#include "Media.h"

class Movie : public Media {

  char director[80];
  char duration[80];
  int rating;

  char* getDirector();
  char* getDuration();
  int getRating();
  void setDirector(char director[]);
  void setDuration(char duration[]);
  void setRating(int rating);

};
