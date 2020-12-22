#include "ctest.h"
#include "100matches.hpp"

Matches m;

CTEST(Matches, PrintMenu) {
    int ch = 1;
    ASSERT_INTERVAL(0, 1, m.PrintMenu(ch));
    ASSERT_EQUAL(1, m.PrintMenu(ch));
}

CTEST(Matches, GameMenu_Main) {
    int ch = 2;
    ASSERT_INTERVAL(1, 2, m.GameMenu_Main(ch));
    ASSERT_EQUAL(2, m.GameMenu_Main(ch));
}

CTEST(Matches, GameStart) {
    ASSERT_INTERVAL(-100, 0, m.GameStart(1, true, 5, 100));
}

CTEST(Matches, Player) {
    ASSERT_TRUE(m.Player(6, true, 100));
}

CTEST(Matches, Computer) {
    ASSERT_INTERVAL(1, 10, m.Computer());
}