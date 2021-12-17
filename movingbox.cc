#include "movingbox.h"
#include "asciiart.h"

//Constructor
MovingBox::MovingBox( int t, int b, int l, int r, char c, char dir, AsciiArt *component ) : Decorator{component}, top{t}, bottom{b}, left {l}, right {r}, charr {c}, direc {dir} {}

//Overrides parent charAt function 
char MovingBox::charAt(int row, int col, int tick) {
    int translatedU;
    int translatedD;
    int translatedL;
    int translatedR;
    if (direc == 'u'){
        translatedU = top - tick;
        translatedD = bottom - tick;
        translatedL = left;
        translatedR = right;
    } else if (direc == 'd'){
        translatedU = top + tick;
        translatedD = bottom + tick;
        translatedL = left;
        translatedR = right;
    } else if(direc == 'r'){
        translatedU = top;
        translatedD = bottom;
        translatedL = left + tick;
        translatedR = right + tick;
    } else {
        translatedU = top;
        translatedD = bottom;
        translatedL = left - tick;
        translatedR = right - tick;
    }
    if ((row >= translatedU && row <= translatedD) && (col >= translatedL && col <= translatedR)){
        return charr;
    }
    //If codition is not met then charAt for next decoration in linked list is returned
    return component->charAt(row, col, tick);
}
//Empty Destructor
MovingBox::~MovingBox() {}

