#include "100matches.hpp"

int Matches::PrintMenu(int choice) {
    if (choice == 0) {
        // cout << "################################################################################################################" << endl;
        // cout << "                        Welcome to the game of 100 matches." << endl;
        // cout << "Game rules:" << endl;
        // cout << "From the heap, initially containing 100 matches two players alternately take several matches: ";
        // cout << "not less than one and not more than ten. The player who took the last match loses." << endl;
        // cout << "################################################################################################################" << endl;

        // cout << "1. Play the game" << endl;
        // cout << "2. Exit" << endl;
    }
    else if (choice == 1) {
        // cout << "Want to play again?" << endl;
        // cout << "1. Yes" << endl;
        // cout << "2. Exit to the menu" << endl;
        // cout << "3. Leave the game" << endl;
    }
    return choice;
}

bool Matches::Player(int num, int correct, int count) {
    //cout << "Your turn. On the table " << count << " matches." << endl;
    //cout << "How many matches will you take?\n";

    //cin >> num;

    if (num >= 1 && num <= 10 && num <= count)
        correct = true;
    else {
        //cout << "Wrong! Please re-enter!" << endl;
        correct = false;
    }

    cout << endl;

    return correct;
}

int Matches::Computer() {
    int num = 1 + rand() % 10;

    //cout << "My turn. I took " << num << " matches." << endl << endl;
    return num;
}

bool Matches::WinCheck(int player) {
    bool wincheck = true;

    if (player == 1)
        wincheck = true;
    else
        wincheck = false;

    return wincheck;
}


int Matches::GameMenu_Main(int choice) {
    do {
        system("cls");
        // PrintMenu(0);
        cout << "Please select an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        
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

    return choice;
}

int Matches::GameStart(int player, bool correct, int num, int count) {
    do {
        if (player == 1) {
            do {
                //Player();
            } while (!correct);
        }
        else {
            do {
                //Computer();
            } while (!correct);
        }
        count -= num;

        if (player == 1)
            player = 2;
        else
            player = 1;
    } while (count > 0);
    //cout << count << endl;
    return count;
}