#ifndef MAIN_H
#define MAIN_H

#include "gba.h"
#include "setup.h"

// TODO: Create any necessary structs

/*
* For example, for a Snake game, one could be:
*
* struct snake {
*   int heading;
*   int length;
*   int row;
*   int col;
* };
*
* Example of a struct to hold state machine data:
*
* struct state {
*   int currentState;
*   int nextState;
* };
*
*/

struct puffle {
    int row;
    int col;
    int height;
    int width;
    int vertDis;
    int horDis;
    int show;
    const short unsigned int *image;
};

struct penguin {
    int row;
    int col;
    int height;
    int width;
    int vertDis;
    int horDis;
    int show;
    const short unsigned int *image;
};

#endif
