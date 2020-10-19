//header for Media parent class

#pragma once

class Media {
public:
  int type;
  int year;
  char title[80];

  int getType();
  int getYear();
  char* getTitle();
  void setType(int type);
  void setYear(int year);
  void setTitle(char* title);

  Media();
  virtual ~Media() {}; //virtual to make it polymorphic
  
};
