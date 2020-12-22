#include "100matches.hpp"

void Matches::InitFields() {
    count = 100;
    player = 1;
    num = 0;
    correct = true;
}

Matches::Matches() {
    InitFields();
}

void Matches::PrintMenu(int choice) {
    if (choice == 0) {
        cout << "################################################################################################################" << endl;
        cout << "                        Welcome to the game of 100 matches." << endl;
        cout << "Game rules:" << endl;
        cout << "From the heap, initially containing 100 matches two players alternately take several matches: ";
        cout << "not less than one and not more than ten. The player who took the last match loses." << endl;
        cout << "################################################################################################################" << endl;

        cout << "1. Play the game" << endl;
        cout << "2. Exit" << endl;
    }
    else if (choice == 1) {
        cout << "Want to play again?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. Exit to the menu" << endl;
        cout << "3. Leave the game" << endl;
    }
}

void Matches::GameMenu_Main() {
    do {
        system("cls");
        PrintMenu(0);
        cout << "Please select an option: ";
        cin >> choice;
        
        switch (choice) {
        case 1:
            system("cls");
            choice = 2;
            break;
        case 2:
            choice = 2;
            break;
        }
    } while (choice != 2);
}