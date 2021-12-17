#include <iostream>
#include "asciiart.h"
#include "blank.h"
#include "studio.h"
#include "filledbox.h"
#include "blinkingbox.h"
#include "movingbox.h"
#include "maskbox.h"
#include "addtext.h"
#include "addgraphics.h"
#include <vector>
#include <memory>

int main () {
  AsciiArt *canvas = new Blank;

  Studio s{canvas};

  std::string command;

  std::vector <Observer*> y;
  std::vector <Observer*> c;

  while (std::cin >> command) {
    if (command == "render" ) {
      s.render();
    }
    else if (command == "animate") {
      int n;
      std::cin >> n;
      s.animate(n);
    }
    else if (command == "reset") {
      s.reset();
    }
    else if (command == "filledbox") {
      int top, bottom, left, right;
      char what;
      std::cin >> top >> bottom >> left >> right >> what;
      //Add filledbox
      //Adds decoration the linked list of decorations
      canvas = new FilledBox(top, bottom, left, right, what, canvas);
      s.picture() = canvas;

    }
    else if (command == "blinkingbox") {
      int top, bottom, left, right;
      char what;
      std::cin >> top >> bottom >> left >> right >> what;
      //Add blinkingbox
      //Adds decoration the linked list of decorations
      canvas = new BlinkingBox(top, bottom, left, right, what, canvas); 
      s.picture() = canvas;

    }
    else if (command == "movingbox") {
      int top, bottom, left, right;
      char what, dir;
      std::cin >> top >> bottom >> left >> right >> what >> dir;
      //Add movingbox
      //Adds decoration the linked list of decorations
      canvas = new MovingBox(top, bottom, left, right, what, dir, canvas);
      s.picture() = canvas;

    }
    else if (command == "maskbox") {
      int top, bottom, left, right;
      char what;
      std::cin >> top >> bottom >> left >> right >> what;
      //Add maskbox
      //Adds decoration the linked list of decorations
      canvas = new MaskBox(top, bottom, left, right, what, canvas);
      s.picture() = canvas;

    }
    else if (command == "addtext") {
      int top, bottom, left, right;
      std::cin >> top >> bottom >> left >> right;
      ////Observer pointer a points to new AddText object
      Observer* a = new AddText(&s, top, bottom, left, right);
      //Pushes object onto vector y
      y.push_back(a);

    }
    else if (command == "addgraphics") {
      int top, bottom, left, right;
      std::cin >> top >> bottom >> left >> right;
      //Observer pointer b points to new AddGraphics object
      Observer* b = new AddGraphics(&s, top, bottom, left, right);
      //Pushes object onto vector c
      c.push_back(b);
    }
  }
  //deletes vector y
  for ( auto a : y){
      delete a;
  }
  //deletes vector c
  for ( auto b : c){
      delete b;
  }
}
