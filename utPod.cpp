// utPod.cpp

#include "UtPod.h"
#include "Song.h"
#include <ctime>
#include <time.h>


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




/*
 *
Inside the pod we have a linked list of songs

How can we shuffle?

	• Generate two random numbers, move a pointer, p1 and p2, through the list some number times
	- loop through to find out how many songs
	- Mod a rand by #of songs
	- take the pointer and move it over that much
	- Then swap the contents of the songs in each of those which would swap the positions of the songs
	- Doing this 10 or 15 times would shuffle it


 */

void UtPod::shuffle() {

    int songLength = numSongs();

    SongNode *p1 = songs;
    SongNode *p2 = songs;

    int rand1;
    int rand2;
    int i;
    int j;

    unsigned int currentTime = (unsigned) time(0);

    srand(currentTime);

    if (songLength >= 2){

        for(i = 0; i < songLength * 2; i++){



            rand1 = rand() % songLength;
            rand2 = rand() % songLength;


           while(rand1 != 0 && p1->next != NULL){

               p1 = p1->next;
               rand1 = rand1 - 1;
           }


            while(rand2 != 0 && p2->next != NULL){

                p2 = p2->next;
                rand2 = rand2 - 1;
            }


//            for(j = 0; j < rand1; j++){
//
//                while(p1->next != NULL){
//                    p1 = p1->next;
//                }
//
//            }
//
//            for(j = 0; j < rand2; j++){
//
//                while(p2->next != NULL){
//                    p2 = p2->next;
//                }
//
//            }


            //showSongList();
            p1->s.swap(p2->s);
           // showSongList();



        }


    }



}


void UtPod::showSongList() {

    SongNode *temp = songs;

    while(temp != NULL){

        cout << temp->s.getTitle() << ", " << temp->s.getArtist() << ", " << temp->s.getSize() << endl;
        temp = temp->next;
    }

}



/*
 *
 *
Find best golfer: traverse list and find golfer with lowest handicap

overload the operator  s for the songs
Start with first, find the smallest, then swap , then go to the next



 */

void UtPod::sortSongList() {


    if (numSongs() >= 2) {                  // do nothing if less than 2

        while(sortHelper());                //continues to sort while sorting is taking place
        //see helper function below
    }

}


bool UtPod::sortHelper() {

    SongNode *p = songs;                    //I use a helper function to sort
    bool sorting = false;

    while (p->next != NULL) {

        if (p->s > p->next->s) {            // continuously calls the sortHelper function until no more swaps are needed

            p->s.swap(p->next->s);
            p = p->next;
            sorting = true;
        } else {

            p = p->next;
        }
    }

    return sorting;                         // if true, sortHelper will keep getting called "in while loop"
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


