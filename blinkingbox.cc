#include "blinkingbox.h"
#include "asciiart.h"

//Constructor
BlinkingBox::BlinkingBox( int t, int b, int l, int r, char c, AsciiArt *component ) : Decorator{component}, top{t}, bottom{b}, left {l}, right {r}, charr {c} {}

//Overrides parent charAt function
char BlinkingBox::charAt(int row, int col, int tick) {
    if ((row >= top && row <= bottom) && (col >= left && col <= right)){
        if(tick % 2 == 0){
        return charr;
        }
    }
    //If condition not met it moves onto to the next decoration in the linked list
    return component->charAt(row, col, tick);
}
//Empty Destructor
BlinkingBox::~BlinkingBox() {}

