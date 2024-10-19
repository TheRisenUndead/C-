#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//Made by Kenu with the help of Ranithu and Tiago
// Save function for storing player data
void save(int savenum, const string &playerClass, const char name[], int level, const string items[]) {
    ofstream MyFile;

    // Open the appropriate save file
    if (savenum == 1) {
        MyFile.open("save1.txt");
    } else if (savenum == 2) {
        MyFile.open("save2.txt");
    } else if (savenum == 3) {
        MyFile.open("save3.txt");
    }

    // Write data to the file
    MyFile << "Class: " << playerClass << endl;
    MyFile << "Name: " << name << endl;
    MyFile << "Level: " << level << endl;
    MyFile << "Items: ";

    // Write items to the file
    for (int i = 0; i < 3; i++) {
        MyFile << items[i] << " ";
    }
    MyFile << endl;

    MyFile.close();
}

// Check if a save file exists and return which one
int read() {
    int saveexists = 0;
    ifstream infile;

    // Check for each save file
    infile.open("save1.txt");
    if (infile.good()) {
        saveexists = 1;
    }
    infile.close();

    infile.open("save2.txt");
    if (infile.good()) {
        saveexists = 2;
    }
    infile.close();

    infile.open("save3.txt");
    if (infile.good()) {
        saveexists = 3;
    }
    infile.close();

    return saveexists;
}
void loadnameclasslevel(int savefile) {
    string text;
    ifstream infile;
    if (savefile == 1) {
        infile.open("save1.txt");
    } else if (savefile == 2) {
        infile.open("save2.txt");
    } else if (savefile == 3) {
        infile.open("save3.txt");
    }
    int i = 0;
    while(i < 3) {
        getline(infile, text);
        cout << text << endl;
        i++;
    }
}
// Load and display inventory from the save file
void loadinventory(int savefile) {
    string text;
    ifstream infile;

    // Open the correct save file and read contents
    if (savefile == 1) {
        infile.open("save1.txt");
    } else if (savefile == 2) {
        infile.open("save2.txt");
    } else if (savefile == 3) {
        infile.open("save3.txt");
    }

    while (getline(infile, text)) {
        cout << text << endl;
    }

    infile.close();
}
void fight(string enemy) {
    cout << "Fight currently under progress" << endl;
}
// In-game menu
void menu(int savefile) {
    int i = 1;
    while (i == 1) {
        string choice;
        cout << "Menu:" << endl;
        cout << "1. Inventory" << endl;
        cout << "2. Encounter" << endl;
        cout << "3. Shop" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        while (choice != "1" && choice != "2" && choice != "3" && choice != "4") {
            cout << "Invalid choice. Please try again: ";
            cin >> choice;
        }

        if (choice == "1") {
            loadinventory(savefile);
        } else if (choice == "2") {
            srand((unsigned) time(NULL));
            int random = rand();
            while(random >= 10) {
                random /= 10;
            }
            if (random <= 3) {
                fight("goblin");
            }
            if(random > 3 && random <= 6) {
                fight("orc");
            }
            if(random > 7 && random <= 9) {
                fight("dragon");
            }
        } else if (choice == "3") {
            cout << "Shop" << endl;
        } else if (choice == "4") {
            break;
        }
    }
}

// Function to play the game
void play(int savefile) {
    menu(savefile);
}
void newfile(int filenum) {
    cout << "New player detected. Creating new player." << endl;
    char name[100];
    cout << "Please enter your name: ";
    cin >> name;

    string playerClass;
    cout << "Please enter your class (Warrior, Ranger, Mage): ";
    cin >> playerClass;

    // Validate class input
    while (playerClass != "Warrior" && playerClass != "Ranger" && playerClass != "Mage") {
        cout << "Class invalid. Please enter your class (Warrior, Ranger, Mage): ";
        cin >> playerClass;
    }

    // Set starting gear based on class
    string beginnerGear[3];
    if (playerClass == "Warrior") {
        beginnerGear[0] = "Sword";
        beginnerGear[1] = "Shield";
        beginnerGear[2] = "Iron Armour";
    } else if (playerClass == "Ranger") {
        beginnerGear[0] = "Bow";
        beginnerGear[1] = "Arrow";
        beginnerGear[2] = "Chain Armour";
    } else if (playerClass == "Mage") {
        beginnerGear[0] = "Staff";
        beginnerGear[1] = "Robes";
        beginnerGear[2] = "Sigil";
    }

    cout << "Writing to save1.txt" << endl;
    save(filenum, playerClass, name, 1, beginnerGear);
    play(filenum);
}

int main() {
    if (read() == 0) {
        newfile(1);
    }
    if(read() > 0) {
        cout << "Save Files: " << endl;
        if (read() == 1) {
            int choice;
            cout << "Save File 1: " << endl;
            loadnameclasslevel(1);
            cout << " " << endl;
            cout << "New Save File 2" << endl;
            cout << " " << endl;
            cout << "Pick save file ";
            cin >> choice;
            if (choice == 1) {
                play(1);
            } else if (choice == 2) {
                newfile(2);
            }
        }
        if (read() == 2) {
            int choice;
            cout << "Save File 1: " << endl;
            loadnameclasslevel(1);
            cout << " " << endl;
            cout << "Save File 2: " << endl;
            loadnameclasslevel(2);
            cout << " " << endl;
            cout << "New Save File 3" << endl;
            cout << " " << endl;
            cout << "Pick save file ";
            cin >> choice;
            if (choice == 1) {
                play(1);
            } else if (choice == 2) {
                play(2);
            }
            else if (choice == 3) {
                newfile(3);
            }
        }
        if (read() == 3) {
            int choice;
            cout << "Save File 1: " << endl;
            loadnameclasslevel(1);
            cout << " " << endl;
            cout << "Save File 2: " << endl;
            loadnameclasslevel(2);
            cout << " " << endl;
            cout << "Save File 3: " << endl;
            loadnameclasslevel(3);
            cout << " " << endl;
            cout << "Pick save file ";
            cin >> choice;
            if (choice == 1) {
                play(1);
            } else if (choice == 2) {
                play(2);
            }
            else if (choice == 3) {
                play(3);
            }
        }
    }
    return 0;
}
