#include "ctest.h"
#include "100matches.hpp"

CTEST(Matches, PrintMenu) {
    Matches m;
    int ch = 1;
    ASSERT_INTERVAL(0, 1, m.PrintMenu(ch));
    ASSERT_EQUAL(1, m.PrintMenu(ch));
}

CTEST(Matches, GameMenu_Main) {
    Matches m;
    int ch = 2;
    ASSERT_INTERVAL(1, 2, m.GameMenu_Main(ch));
    ASSERT_EQUAL(2, m.GameMenu_Main(ch));
}

CTEST(Matches, GameStart) {
    Matches m;
    ASSERT_INTERVAL(-100, 0, m.GameStart(1, true, 5, 100));
}