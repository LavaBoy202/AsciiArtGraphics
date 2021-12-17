#ifndef __ADDGRAPHICS_H__
#define __ADDGRAPHICS_H__
#include <iostream>
#include "observer.h"
#include "studio.h"
#include "window.h"

class AddGraphics: public Observer {
    Studio *subject;
  int top;
  int bottom;
  int left;
  int right;
  Xwindow w;
 public:
  AddGraphics( Studio *s, int top, int bottom, int left, int right );
  void notify() override;
  ~AddGraphics();  
};

#endif

