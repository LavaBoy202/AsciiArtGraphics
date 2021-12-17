#ifndef __ADDTEXT_H__
#define __ADDTEXT_H__
#include <iostream>
#include "observer.h"
#include "studio.h"


class AddText: public Observer {
    Studio *subject;
  int top;
  int bottom;
  int left;
  int right;
 public:
  AddText( Studio *s, int top, int bottom, int left, int right );
  void notify() override;
  ~AddText();
  
};

#endif
