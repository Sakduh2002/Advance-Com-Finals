#include <iostream>
#include <string>
#include <limits>
#include <cstdlib> 
#include "GreenList.h"
#include "GreenStack.h" 

using namespace std;

int main(int argc, char* argv[]) {
    GreenList list;
    GreenStack trashBin;

    if (argc > 1) {
        for (int i = 1; i < argc; i += 4) { 
            if (i + 3 < argc) {
                list.insertSorted(argv[i], argv[i+1], atoi(argv[i+2]), atoi(argv[i+3]));
            }
        }
    }

    int ans = 0;
    string name, loc;
    int year, sdg;

    while (ans != 6) {
        cout << "\n=== Mahidol Green DB ===\n";
        cout << "1. Add New Project (Auto-Sort by Year)\n";
        cout << "2. Delete Project (Move to Trash)\n";
        cout << "3. Undo Delete (Restore from Trash)\n";
        cout << "4. Show Active Projects\n";
        cout << "5. Show Trash Bin\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        
        
        if (!(cin >> ans)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (ans == 1) { // ADD PROJECT
            cout << "Name: "; getline(cin, name);
            cout << "Location: "; getline(cin, loc);
            
            cout << "Year: "; 
            while (!(cin >> year)) {
                cout << "Invalid Year! Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter SDG Goal (1-17): ";
            while (true) {
                if (!(cin >> sdg)) { 
                    
                    cout << "Error: That is not a number! Please enter 1-17: ";
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                } 
                else if (sdg < 1 || sdg > 17) {
                    cout << "Error: Number out of range! Please enter 1-17: ";
                } 
                else {
                    break; 
                }
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            list.insertSorted(name, loc, year, sdg); 
            cout << "Project added chronologically under SDG " << sdg << ".\n";
        }
        else if (ans == 2) { 
            cout << "Name to delete: "; getline(cin, name);
            
            if (list.removeByName(name, trashBin)) {
                 cout << "Deleted and moved to Trash Bin.\n";
            } else {
                cout << "Not found.\n";
            }
        }
        else if (ans == 3) { 
            if (trashBin.isEmpty()) {
                cout << "Nothing to restore!\n";
            } else {
                GreenNode* restored = trashBin.pop();
                
                list.insertSorted(restored->getName(), restored->getLoc(), 
                                  restored->getYear(), restored->getSDG());
                
                cout << "Restored: " << restored->getName() << "\n";
                delete restored; 
            }
        }
        else if (ans == 4) {
            list.printAll();
        }
        else if (ans == 5) {
            trashBin.printStack();
        }
    }
    return 0;
}