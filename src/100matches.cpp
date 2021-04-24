#include "100matches.hpp"

void Matches::InitFields() {
    count = 100;
    player = 1;
    num = 0;
    correct = true;
}

Matches::Matches() {
    srand(time(0));
    InitFields();
}

void Matches::PrintMenu(string choice) {
    if (choice == "main_menu") {
        cout << "################################################################################################################" << endl;
        cout << "                        Welcome to the game of 100 matches." << endl;
        cout << "Game rules:" << endl;
        cout << "From the heap, initially containing 100 matches two players alternately take several matches: ";
        cout << "not less than one and not more than ten. The player who took the last match loses." << endl;
        cout << "################################################################################################################" << endl;

        cout << "1. Play the game" << endl;
        cout << "2. Exit" << endl;
    }
    else if (choice == "restart") {
        cout << "Want to play again?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. Exit to the menu" << endl;
        cout << "3. Leave the game" << endl;
    }
    else if (choice == "player_turn") {
        cout << "Your turn. On the table " << count << " matches." << endl;
        cout << "How many matches will you take?\n";
    }
    else if (choice == "option_select") {
        cout << "Please select an option: ";
    }
    else if (choice == "computer_turn") {
        cout << "My turn. I took " << num << " matches." << endl << endl;
    }
    else if (choice == "win_check") {
        if (player == 1)
            cout << "You won!" << endl << endl;
        else
            cout << "You lost!" << endl << endl;
    }
    else if (choice == "re_enter") {
        cout << "Wrong! Please re-enter!" << endl;
    }               
}

bool Matches::IsCorrectInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return false;
    }

    return true;
}

void Matches::GameMenu_Restart() {
    do {
        PrintMenu("restart");
        PrintMenu("option_select");

        cin >> choice;
        if (!IsCorrectInput()) {
            continue;
        }

        switch (choice) {
			
        case 1:
            system("cls");
            InitFields();
            GameStart();
            choice = 3;
            break;
        case 2:
            InitFields();
            GameMenu_Main();
            choice = 3;
            break;
        case 3:
            choice = 3;
            break;
			
        }
        system("cls");
    } while (choice != 3);
}

bool Matches::Player(int &num, int count) {
    if (!IsCorrectInput()) {
        num = 11;
    }

    if (num >= 1 && num <= 10 && num <= count)
        correct = true;
    else {
        correct = false;
    }

    return correct;
}

int Matches::Computer() {
    num = 1 + rand() % 10;
    return num;
}

void Matches::GameMenu_Main() {
    do {
        system("cls");
        PrintMenu("main_menu");
        PrintMenu("option_select");
        
        cin >> choice;
        if (!IsCorrectInput()) {
            continue;
        }

        switch (choice) {
        case 1:
            system("cls");
            GameStart();
            choice = 2;
            break;
        case 2:
            choice = 2;
            break;
        }
    } while (choice != 2);
}

void Matches::GameStart() {
    do {
        if (player == 1) {
            do {
                PrintMenu("player_turn");
                cin >> num;
                Player(num, count);
                if (!correct) {
                    PrintMenu("re_enter");
                }
                cout << endl;
            } while (!correct);
        }
        else {
            do {
                Computer();
                PrintMenu("computer_turn");
            } while (!correct);
        }

        count -= num;

        if (player == 1)
            player = 2;
        else
            player = 1;

    } while (count > 0);

    PrintMenu("win_check");
    GameMenu_Restart();
}
