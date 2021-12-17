#include "maskbox.h"
#include "asciiart.h"

//Constructor
MaskBox::MaskBox( int t, int b, int l, int r, char c, AsciiArt *component ) : Decorator{component}, top{t}, bottom{b}, left {l}, right {r}, charr {c} {}

//Overrides parent charAt function
char MaskBox::charAt(int row, int col, int tick) {
	//Stores the char underneath this decoration
    char temp = component->charAt(row, col, tick);
    if(temp == ' '){
        return temp;
	//If there is a char underneath this decoration then else condition is reached
    } else { 
        if ((row >= top && row <= bottom) && (col >= left && col <= right)){
            return charr;
        }
        return component->charAt(row, col, tick);
    }
}

//Empty Destructor
MaskBox::~MaskBox() {}
