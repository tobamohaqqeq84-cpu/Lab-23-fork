//Toba Mohaqqeq
//COMSC -210
//Lab 23


#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
     bool again = true;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    // create list of goats
    list<Goat> trip;
      int choice = main_menu();// display menu and get choice
    
         if (choice == 1){
             add_goat(trip, names, colors);
         }
        else if (choice == 2){
            delete_goat(trip);
        }
        else if (choice == 3){
            display_trip(trip);
        }
        else if (choice == 4){
            cout << "goodbye!\n";
            again = false;// stops the loop 
        }



    return 0;
}
//*************************************************************
 int main_menu(){
     int choice;
     cout << " *** GOAT MANAGER 3001 ***\n";
     cout << "1) Add a goat\n";
     cout << "2) Delete a goat\n";
     cout << "3) List all goats\n";
     cout << "4) Quit\n";
     cout << "choice -->";
     cin >> choice;

    
     while (cin.fail() || choice < 1 || choice > 4){
         cin.clear();
         cin.ignore(1000, '\n');
             cout << "Invalid choice. Try again.\n";
        cin >> choice;
 
     }
 
     return choice;
 }
void add_goat(list<Goat> &trip, string names[], string colors[]){
int nNames = 0;
while (nNames < SZ_NAMES && !names[nNames].empty())++nNames;
 int nColors = 0;
    while (nColors < SZ_COLORS && !colors[nColors].empty())++nColors;

    int nameIdx = rand() % nNames;
    int colorIdx = rand() % nColors;
    int age = rand() % MAX_AGE + 1;

    Goat g(names[nameIdx], colors[colorIdx], age);
    trip.push_back(g);
    cout << "Added: " << g.getName() << " (" << g.getAge() << ")\n";
}
cout << "[0] cancel\nchoice -->";
 int choice

void delete_goat(list<Goat> &trip){
    int choice = select_goat(trip);
    if (choice<= 0){
        cout << "Cancelled.\n";
        return;
    }
    auto it = trip.begin();
    advance(it, choice - 1);

    cout << "Deleted: " << it->getName() << " (" << it ->getAge

        }