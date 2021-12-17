#ifndef _BLINKINGBOX_H_
#define _BLINKINGBOX_H_
#include "decorator.h"
class AsciiArt;

class BlinkingBox: public Decorator {
    int top;
    int bottom;
    int left;
    int right;
    char charr;
    public:
    BlinkingBox(int t, int b, int l, int r, char c, AsciiArt *component);
    char charAt(int row, int col, int tick) override;
    virtual ~BlinkingBox();
};

#endif
