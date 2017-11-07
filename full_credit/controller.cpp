#include "controller.h"
#include "view.h"
#include "library.h"
#include "publication.h"
#include "patron.h"
#include "genre.h"
#include "media.h"
#include "age.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/fl_ask.H>
#include <FL/Fl_JPEG_Image.H>

using namespace std;

void Controller::gui() {

string menu = view.menu() + "\nCommand? ";
  string no_label = "";
  int cmd = -1;
  while (cmd != 0) {
    fl_message_title("Main Menu"); //title
     
    cmd = atoi(fl_input(menu.c_str(), 0));
    
    //cin.ignore();
    execute_cmd(cmd);
  }
} 

int Controller::get_int(string title, string user_cmd, int max) {
  string error = "Please enter an integer between 0 and " + max;
  int result;
  while(true) {
    fl_message_title(title.c_str());

    result = atoi(fl_input(user_cmd.c_str(), 0));
    if (0 <= result && result <= max) break;
    fl_message_title("Error: invalid input");

    fl_message(error.c_str());
  }
  return result;
} 

string Controller::get_string(string title, string user_cmd) {
  fl_message_title(title.c_str());

  string result{fl_input(user_cmd.c_str(), 0)};
  return result;
} 

void Controller::execute_cmd(int cmd) {
  if (cmd == 1) { // Add publication
    string title, author, copyright, isbn;
    int genre, media, age; 

     title = get_string("Publication Title", "Title? ");
    author = get_string(title, "Author? ");
    copyright = get_string(title, "Copyright date? ");
    genre = get_int(title, view.list_genre()+"Genre? ", Genre::num_genres - 1);
    media = get_int(title, view.list_media()+"Media? ", Media::num_media - 1);
    age = get_int(title, view.list_age()+"Age? ", Age::num_ages - 1); 
    isbn = get_string(title, "ISBN? "); 
    library.add_publication(Publication(title, author, copyright, genre, media, age, isbn)); 

 } else if (cmd == 2) { // List all publications
    //view.list_publications();
 string list = view.list_publication();
    fl_message_title("List of All Publications");

    fl_message(list.c_str());

 } else if (cmd == 3) { // Check out publication
    int pub, pat;  
 string user_cmd = view.list_publication() + "\nPublication number? ";
    pub = get_int("Select a Publication", user_cmd, library.number_of_publications() - 1);

    user_cmd = view.list_patrons()+ "\nPatron number? ";
    pat = get_int("Select a Beloved Patron", user_cmd, library.number_of_patrons() - 1);

    try {
      library.check_out(pub, pat);
    } catch (Publication::Invalid_transaction e) {
      user_cmd = "Error: selected publication is not available for check out";
      fl_message_title("ERROR");
     
      fl_message(user_cmd.c_str());
    }
    
 } else if (cmd == 4) { // Check in publication
     int pub;
    string user_cmd= view.list_publication() + "\nPublication number? ";
    pub = get_int("Select a Publication", user_cmd, library.number_of_publications() - 1);

    try {
      library.check_in(pub);
    } catch (Publication::Invalid_transaction e) {
       user_cmd = "Error: specified publication is not available for check in";
       fl_message_title("ERROR");
       
       fl_message(user_cmd.c_str());
    }

 } else if (cmd == 5) { // Add patron
    string name, number;

    name = get_string("Add patron", "Name? ");
    number = get_string(name, "Phone number? ");
    library.add_patron(Patron(name, number));
   // cout << "Name? ";
    //getline(cin, name);
    //cout << "Phone number? ";
    //getline(cin, number);
    //library.add_patron(Patron(name, number));
    
 } else if (cmd == 6) { // List all patrons
    //view.list_patrons();
 string list = view.list_patrons();
    fl_message_title("All Patrons");
    
    fl_message(list.c_str());


 } else if (cmd == 9) { // Help
    //view.help();
 string help = view.get_help();
    fl_message_title("Help");

    fl_message(help.c_str());
 } else if (cmd == 0) { // Exit
 } else if (cmd == 99) { // Easter Egg
   library.easter_egg();
string message = "More publications and patrons added!"; //new
   fl_message_title("Easter Egg");

   fl_message(message.c_str());
 } else {
   //cerr << "**** Invalid command - type 9 for help" << endl << endl;
 string error = "**** Invalid command - type 9 for help";
   fl_message_title("ERROR"); 

   fl_message(error.c_str());
 }
}

