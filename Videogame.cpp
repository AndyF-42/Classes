#include "Videogame.h"
#include <cstring>

Videogame::Videogame() {
}

char* Videogame::getPublisher() {
  return publisher;
}
int Videogame::getRating() {
  return rating;
}

void Videogame::setPublisher(char* newPublisher) {
  strcpy(publisher, newPublisher);
}
void Videogame::setRating(int newRating) {
  rating = newRating;
}
