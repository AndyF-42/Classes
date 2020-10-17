

class Music : public media {
public:
  char artist[80];
  char duration[80];
  char publisher[80];
  
  char* getArtist();
  char* getDuration();
  char* getPublisher();
  void setArtist(char artist[]);
  void setDuration(char duration[]);
  void setPublisher(char publisher[]);
  
};
