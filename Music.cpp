#include "Music.h"
#include <cstring>

Music::Music() {
}

char* Music::getArtist() {
  return artist;
}
char* Music::getDuration() {
  return duration;
}
char* Music::getPublisher() {
  return publisher;
}

void Music::setArtist(char* newArtist) {
  strcpy(artist, newArtist);
}
void Music::setDuration(char* newDuration) {
  strcpy(duration, newDuration);
}
void Music::setPublisher(char* newPublisher) {
  strcpy(publisher, newPublisher);
}
