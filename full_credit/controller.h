#ifndef __CONTROLLER_H
#define __CONTROLLER_H 201609

#include "library.h"
#include "view.h"

class Controller {
  public:
    Controller (Library& lib, View& view):library(lib), view(view){ }
    void gui();//void cli();
    void execute_cmd(int cmd);
  private:
	int get_int(string title, string user_cmd, int max); 
	string get_string(string title, string user_cmd); 
    	Library& library; 
    	View& view;
};
#endif
