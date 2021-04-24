#include "../thirdparty/ctest.h"
#include "../src/100matches.hpp"

Matches m;

CTEST(Matches, Computer)
{ 
    srand(time(0));
    int num = m.Computer();
    ASSERT_INTERVAL(1, 10, num);
}

CTEST(Matches, Player)
{ 
    int num   = 10;
    int count = 100;
    
    ASSERT_TRUE(m.Player(num, count));
}

// CTEST(Matches, IsCorrectInput)
// { 
//     int choice;
//     cin >> choice;
//     ASSERT_TRUE(m.IsCorrectInput());
// }