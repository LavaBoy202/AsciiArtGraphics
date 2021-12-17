#include "addgraphics.h"
#include "window.h"

//Concrete observer AddGraphics Constructor
AddGraphics::AddGraphics( Studio *s, int top, int bottom, int left, int right )
    : subject{s}, top{top}, bottom{bottom}, left{left}, right{right}, w{(bottom - top) * 10 , (right - left) * 10}
    {
        subject->attach( this );
    }
//Concrete observer destructor 
    AddGraphics ::~AddGraphics() {
        subject->detach( this );
    }
//Renders observed boundraies
    void AddGraphics::notify() {
    for (int i = top; i < bottom + 1; ++i) {
        for (int j = left; j < right + 1; ++j) {
      char temp = subject->getState(i, j);
      if (temp > 47 &&  temp < 58){
	      //If temp is a upper case letter then colour of rectangle is green
          w.fillRectangle(j * 10, i * 10 , 10, 10, 4);
      }else if (temp > 64 && temp < 91){
	      //If temp is a digit then colour of rectangle is blue
          w.fillRectangle(j * 10, i * 10, 10, 10, 3);
      }else if (temp > 96 && temp < 123){
	     //If temp is a lower case letter then colour of rectangle is red
          w.fillRectangle(j * 10, i * 10, 10, 10, 2);
      }else if (temp == 32){
	      //If temp is white space then the colour of rectangle is white
          w.fillRectangle(j * 10, i * 10, 10, 10, 0);
      }else{
	      //If temp is any other printable charecter then colour of rectangle is black
          w.fillRectangle(j * 10, i * 10, 10, 10, 1);
      }
    } 
  }
}



        

    
