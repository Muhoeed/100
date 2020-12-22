#include "ctest.h"
#include "100matches.hpp"

CTEST(Matches, PrintMenu) {
    Matches m;
    ASSERT_INTERVAL(0, 1, m.PrintMenu(1));
    ASSERT_EQUAL(1, m.PrintMenu(1));
}