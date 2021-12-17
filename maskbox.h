#ifndef _MASKBOX_H_
#define _MASKBOX_H_
#include "decorator.h"
class AsciiArt;

class MaskBox: public Decorator {
    int top;
    int bottom;
    int left;
    int right;
    char charr;
    public:
    MaskBox(int t, int b, int l, int r, char c, AsciiArt *component);
    char charAt(int row, int col, int tick) override;
    virtual ~MaskBox();
};

#endif
