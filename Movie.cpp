//getters and setters for Movie class

#include "Movie.h"
#include <cstring>

Movie::Movie() {
}

char* Movie::getDirector() {
  return director;
}
char* Movie::getDuration() {
  return duration;
}
char* Movie::getRating() {
  return rating;
}

void Movie::setDirector(char* newDirector) {
  strcpy(director, newDirector);
}
void Movie::setDuration(char* newDuration) {
  strcpy(duration, newDuration);
}
void Movie::setRating(char* newRating) {
  strcpy(rating, newRating);
}
