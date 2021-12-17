#include "addtext.h"

//AddText concrete observer Constructor
AddText::AddText( Studio *s, int top, int bottom, int left, int right )
    : subject{s}, top{top}, bottom{bottom}, left{left}, right{right}
    {
        subject->attach( this );
    }
//Concrete observer Destructor 
    AddText::~AddText() {
        subject->detach( this );
    }
//Renders observed boundaries
    void AddText::notify() {
        std::cout << '+';
  for (int j = left; j < right + 1; ++j) std::cout << '-';
  std::cout << '+' << std::endl;
  for (int i = top; i < bottom + 1; ++i) {
    std::cout << '|';
    for (int j = left; j < right + 1; ++j) {
      std::cout << subject->getState(i, j);
    }
    std::cout << '|' << std::endl;
  }
  std::cout << '+';
  for (int j = left; j < right + 1; ++j) std::cout << '-';
  std::cout << '+' << std::endl;     
    }
    
