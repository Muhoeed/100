#include "ctest.h"
#include "100matches.hpp"

CTEST(Matches, PrintMenu) {
    Matches m;
    int ch = 1;
    ASSERT_INTERVAL(0, 1, m.PrintMenu(1));
    ASSERT_EQUAL(1, m.PrintMenu(1));
}

CTEST(Matches, GameMenu_Main) {
    Matches m;
    int ch = 2;
    ASSERT_INTERVAL(1, 2, m.GameMenu_Main(ch));
    ASSERT_EQUAL(2, m.GameMenu_Main(ch));
}