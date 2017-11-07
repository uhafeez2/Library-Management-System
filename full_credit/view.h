#ifndef __VIEW_H
#define __VIEW_H 201609
 
#include "library.h"

class View {
  public:
    View(Library& lib) : library(lib) { }
    string menu();//void show_menu();
    string list_publication();//void list_publications();
    string list_patrons();//void list_patrons();
    string list_age();
    string list_genre();
    string list_media();
    string get_help(); //void help();
  private:
    Library& library; 
};
#endif
