// Song.cpp


#include "Song.h"



using namespace std;


Song::Song() {

    artist = "";
    title = "";
    size = MAX_SIZE;

}

Song::Song(string artist) {

    this->artist = artist;
    title = "";
    size = MAX_SIZE;

}

Song::Song(string _artist, string _title, int _size) {

    artist = _artist;
    title = _title;
    size = _size;

}

string Song::getTitle() const {
    return title;
}

void Song::setTitle(string name) {

    title = name;
}

int Song::getSize() const {
    return  size;
}

void Song::setSize(int s) {

    this->size = s;
}

void Song::swap(Song &p) {

    Song temp = p;
    p = *this;
    *this = temp;
}

bool Song::operator>(Song const &rhs) {

    if(artist > rhs.artist){
        return true;
    } else if (artist > rhs.artist)
        return false;
    else{
        if (title > rhs.title){
            return true;
        }
        else if (title < rhs.title)
            return false;
    }

    if(size > rhs.size){
        return true;
    }
    //else if (size < rhs.size){
            return false;

}




bool Song::operator<(Song const &rhs) {

    if(artist < rhs.artist){
        return true;
    } else if (artist < rhs.artist)
        return false;
    else{
        if (title < rhs.title){
            return true;
        }
        else if (title > rhs.title)
            return false;
    }

    if(size < rhs.size){
        return true;
    }
    //else if(size > rhs.size){

            return false;
}




bool Song::operator==(Song const &rhs) {

    return (artist == rhs.artist &&
            title == rhs.title &&
            size == rhs.size);
}

Song::~Song() {

    cout << "debug - in destructor for " << artist << endl;
}



ostream& operator << (ostream& out, const Song &s)
    {
        out << s.getArtist() << " (" << s.getTitle() <<
        ") - " << s.getSize();
        return out;
    }





