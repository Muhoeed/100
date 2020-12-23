#ifndef _100MATCHES_H_
#define _100MATCHES_H_

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

class Matches {
    // private:
    //     int count;
    //     int player;
    //     int num;
    //     bool correct;
    //     int choice;
		
    public:
        int PrintMenu(int choice);
        int GameMenu_Main(int choice);
        int GameStart(int player, bool correct, int num, int count);
        bool Player(int num, int correct, int count);
        int Computer();
        bool WinCheck(int player);
        int GameMenu_Restart(int choice);
};

#endif
