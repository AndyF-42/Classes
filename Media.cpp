#include "Media.h"
#include <cstring>
#define MOVIE 1
#define MUSIC 2
#define VIDEOGAME 3

Media::Media() {
}

int Media::getType() {
  return type;
}
int Media::getYear() {
  return year;
}
char* Media::getTitle() {
  return title;
}

void Media::setType(int newType) {
  type = newType;
}
void Media::setYear(int newYear) {
  year = newYear;
}
void Media::setTitle(char* newTitle) {
  strcpy(title, newTitle);
}
