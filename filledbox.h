#ifndef _FILLEDBOX_H_
#define _FILLEDBOX_H_
#include "decorator.h"
class AsciiArt;

class FilledBox: public Decorator {
    int top;
    int bottom;
    int left;
    int right;
    char charr;
    public:
    FilledBox(int t, int b, int l, int r, char c, AsciiArt *component);
    char charAt(int row, int col, int tick) override;
    virtual ~FilledBox();
};

#endif
