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
int Movie::getRating() {
  return rating;
}

void Movie::setDirector(char* newDirector) {
  strcpy(director, newDirector);
}
void Movie::setDuration(char* newDuration) {
  strcpy(duration, newDuration);
}
void Movie::setRating(int newRating) {
  rating = newRating;
}
