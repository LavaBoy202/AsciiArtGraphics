#include "filledbox.h"
#include "asciiart.h"

//Constructor
FilledBox::FilledBox( int t, int b, int l, int r, char c, AsciiArt *component ) : Decorator{component}, top{t}, bottom{b}, left {l}, right {r}, charr {c} {}

//Overrides parent charAt function
char FilledBox::charAt(int row, int col, int tick) {
    if ((row >= top && row <= bottom) && (col >= left && col <= right)){
        return charr;
    }
    //If condition is not met then it moves onto the next decoration in the linked list
    return component->charAt(row, col, tick);
}
//Empty Destructor
FilledBox::~FilledBox() {}
