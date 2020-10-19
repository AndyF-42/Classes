//getters and setters for Videogame class

#include "Videogame.h"
#include <cstring>

Videogame::Videogame() {
}

char* Videogame::getPublisher() {
  return publisher;
}
char* Videogame::getRating() {
  return rating;
}

void Videogame::setPublisher(char* newPublisher) {
  strcpy(publisher, newPublisher);
}
void Videogame::setRating(char* newRating) {
  strcpy(rating, newRating);
}
