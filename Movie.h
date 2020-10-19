#include "Media.h"

class Movie : public Media {
public:
  char director[80];
  char duration[80];
  int rating;

  char* getDirector();
  char* getDuration();
  int getRating();
  void setDirector(char* newDirector);
  void setDuration(char* newDuration);
  void setRating(int newRating);

  Movie();
  //~Movie();
  
};
