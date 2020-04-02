//DOCUMENT HERE

#ifndef Song_H
#define Song_H

#include <string>
#include <iostream>

using namespace std;


class Song
{

    private:
     string artist;
     string title;
     int size;

     static const int MAX_SIZE = 512;

    public:
     Song();
     Song(string artist);
     Song(string artist, string title, int size);

     string getArtist() const
     { return artist; }


     void setArtist( string a )
     {
        artist = a;
     }


     string getTitle() const;

     void setTitle( string name);

     int getSize() const;

     void setSize( int s);

     void swap(Song &p);

     bool operator >(Song const &rhs);
     bool operator ==(Song const &rhs);

     ~Song();

};

    ostream& operator << (ostream& out, const Song &g);




#endif

