

class Media {
public:
  int getYear();
  char* getTitle();
  void setYear(int year);
  void setTitle(char title[]);
  
  int year;
  char title[80];
};
