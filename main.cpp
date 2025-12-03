#include <iostream>
#include <string>
#include <limits>
#include "GreenList.h"
#include "GreenStack.h" 

using namespace std;

int main() {
    GreenList list;
    GreenStack trashBin;

    int ans = 0;
    string name, loc;
    int year;

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

        if (ans == 1) { 
            cout << "Name: "; getline(cin, name);
            cout << "Location: "; getline(cin, loc);
            cout << "Year: "; cin >> year;
            
            list.insertSorted(name, loc, year); 
            cout << "Project added chronologically.\n";
        }
        else if (ans == 2) { 
            cout << "Name to delete: "; getline(cin, name);
            
            if (list.removeByName(name, trashBin)) {
                 cout << "Deleted! (Note: In this simple version, data is gone. See GreenList.cpp comments on how to push to stack properly!)\n";
            } else {
                cout << "Not found.\n";
            }
        }
        else if (ans == 3) { // UNDO
            if (trashBin.isEmpty()) {
                cout << "Nothing to restore!\n";
            } else {
                GreenNode* restored = trashBin.pop();
                
                list.insertSorted(restored->getName(), restored->getLoc(), restored->getYear());
                
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
