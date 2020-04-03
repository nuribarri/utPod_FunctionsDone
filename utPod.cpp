// utPod.cpp

#include "UtPod.h"
#include "Song.h"


using namespace std;


UtPod::UtPod() {

    songs = NULL;               //default, sets head pointer
    tsongs = NULL;              // default, sets tail pointer
    memSize = MAX_MEMORY;       // initialize to max MB
}


UtPod::UtPod(int size) {

    songs = NULL;
    tsongs = NULL;

    if(size > MAX_MEMORY || size <= 0){
        memSize = MAX_MEMORY;
    } else{
        memSize = size;
    }

}


int UtPod::addSong(Song const &s) {

    // check if enough memory

    int remainingMem = getRemainingMemory();

    if (remainingMem < s.getSize()){
        return -1;
    }else{

        SongNode *temp = new SongNode;
        temp->next = songs;
        temp->s = s;                    // Setting  new song (temp) = s
        songs = temp;                   // set head to top of song list
        tsongs = temp->next;
        return 0;

    }



}


int UtPod::removeSong(Song const &s) {

    SongNode *temp = songs;

    if(songs == NULL) {
        return -2;
    }

   if(songs->s == s.getTitle()) {
       if (songs->next == NULL) {            //deletes first song, if only one song
           songs = NULL;
       } else {
           SongNode *target = songs;        //deletes first song,
           songs = songs->next;             // remove link
           delete target;
       }
       return 0;
   }

   while(temp->next != NULL){

       if(temp->next->s == s){

           SongNode *target = temp->next;
           temp->next = temp->next->next;
           delete target;
           return 0;
       }

       temp = temp->next;

   }

   return -2;               // nothing is removed

}


void UtPod::shuffle() {

}


void UtPod::showSongList() {

    SongNode *temp = songs;

    while(temp != NULL){

        cout << temp->s.getTitle() << ", " << temp->s.getArtist() << ", " << temp->s.getSize() << endl;
        temp = temp->next;
    }

}


void UtPod::sortSongList() {

}


void UtPod::clearMemory() {

    SongNode *temp = songs;

    if(temp->next == NULL){
        SongNode *clear = temp;
        songs = NULL;
        delete clear;
    }

    while(temp->next != NULL){
        SongNode *clear = temp;
        temp = temp->next;
        delete clear;

    }

    SongNode *clear = temp;
    delete clear;
    songs = NULL;       // no more songs

}


int UtPod::getRemainingMemory() {

    int remainingMem = memSize;

    SongNode *temp = songs;

    while(temp != NULL){
        remainingMem = remainingMem - temp->s.getSize();
        temp = temp->next;
    }

    return remainingMem;

}


int UtPod::numSongs() {

    SongNode *temp = songs;
    int count = 0;

    if(songs == NULL){          //no songs
        return 0;
    }

    count = count + 1;          // first song

    while(temp->next != NULL){
        count = count + 1;
        temp = temp->next;
    }

    return count;

}


UtPod::~UtPod() {

}