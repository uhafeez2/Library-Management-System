#include "view.h"
#include "library.h"
#include "controller.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/fl_ask.H>

using namespace std;

string View::menu() {
  string menu = R"(
=================================
CSE1325 Library Management System
=================================

Publications
------------
(1) Add publication
(2) List all publications
(3) Check out publication
(4) Check in publication

Patrons
=======
(5) Add patron
(6) List all patrons

Utility
-------
(9) Help
(0) Exit

)";
	return menu;
}

string View::list_publication() {
  string list = R"(
----------------------------
List of Library Publications
----------------------------
)";
  //cout << header;
  for (int i=0; i<library.number_of_publications(); ++i) {
    list+=std:: to_string(i) + ") " + library.publication_to_string(i) + '\n';
  }
return list;
}

string View::list_patrons() {
  string list = R"(
-----------------------
List of Beloved Patrons
-----------------------
)";
  //cout << header;
  for (int i=0; i<library.number_of_patrons(); ++i) {
     list+=std::to_string(i) + ") " + library.patron_to_string(i) + '\n';
  }
return list;
}

string View::list_genre(){
string list = "";
  for (int i = 0; i < Genre::num_genres; ++i)
    list += "  " + std::to_string(i) + ") " + Genre(i).to_string()+'\n';
return list;
}

string View::list_media() {
  string list = "";
  for (int i = 0; i < Media::num_media; ++i)
    list += "  " + std::to_string(i) + ") " + Media(i).to_string() +'\n';
 return list;
}

string View::list_age() {
  string list = "";
  for (int i = 0; i < Age::num_ages; ++i)
   list += "  " + std::to_string(i) + ") " + Age(i).to_string() + '\n';
return list;
}



string View::get_help() {
  return ( "The LMS tracks publication assets for a library, including those who check out and return those publications. \n(1) Add publication - This allows the librarian to enter data associated with a new publication. \n(2) List all publications - All data known about each publication in the library is listed.\n(3) Check out publication - Enter the data for patrons who check out a publication, and mark that publication as checked out.\n(4) Check in publication - Select a publication and mark it as checked in.\n(5) Add patron - This allows the librarian to enter data associated with a new library patron.\n(6) List patrons - All data know about each patron of the library. \n (9) Help - Print this text.\n(0) Exit - Exit the program. WARNING: The current version does NOT save any entered data. This feature will be added in the next version." );
  
}


