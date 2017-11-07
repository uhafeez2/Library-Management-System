#include "controller.h"
#include "library.h"
#include <string>
 #include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Shared_Image.H>


int main() {
  fl_register_images();
  Fl_Window win(1,1);
  win.show();
  Library library;
  View view{library};
  Controller controller(library, view);
  controller.gui();
  //controller.cli();
}
