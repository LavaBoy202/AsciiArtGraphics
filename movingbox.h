#ifndef _MOVINGBOX_H_
#define _MOVINGBOX_H_
#include "decorator.h"
class AsciiArt;

class MovingBox: public Decorator {
    int top;
    int bottom;
    int left;
    int right;
    char charr;
    char direc;
    public:
    MovingBox(int t, int b, int l, int r, char c, char dir, AsciiArt *component);
    char charAt(int row, int col, int tick) override;
    virtual ~MovingBox();
};

#endif
