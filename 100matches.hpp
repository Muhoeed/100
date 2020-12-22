#ifndef _100MATCHES_H_
#define _100MATCHES_H_

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

class Matches {
    private:
        int count;
        int player;
        int num;
        bool correct;
        int choice;
		
    public:
        void PrintMenu(int choice);
        Matches();
        void InitFields();
};

#endif
