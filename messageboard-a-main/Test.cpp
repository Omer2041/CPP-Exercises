#include "doctest.h"
#include "Board.hpp"
#include <string>
#include <algorithm>
#include <cstdlib>


using namespace ariel;
using namespace std;




TEST_CASE("CHECK INFINITE TABLE") {
    Board b;
    unsigned int rndcol = (unsigned int) rand();
    unsigned int rndrow = (unsigned int) rand();
    CHECK_NOTHROW(b.post(rndrow, rndcol, Direction::Horizontal, "abcde"));
    CHECK(b.read(rndrow, rndcol, Direction::Horizontal,5) == (string)("abcde"));


}

TEST_CASE("check Horizontal - post & read")
{
    Board b;

    // CHECK IF POSTED SUCCESFULLY (NO - THROW)
    CHECK_NOTHROW(b.post(10,10, Direction::Horizontal, "0merK"));

    // CHCECK IF EVERY CHAR IS IN HIS PLACE (HORIZONTAL)
    CHECK(b.read(10, 10, Direction::Horizontal,1) == (string)("0"));
    CHECK(b.read(10, 10, Direction::Horizontal,2) == (string)("0m"));
    CHECK(b.read(10, 10, Direction::Horizontal,3) == (string)("0me"));
    CHECK(b.read(10, 10, Direction::Horizontal,4) == (string)("0mer"));
    CHECK(b.read(10, 10, Direction::Horizontal,5) == (string)("0merK"));
    CHECK(b.read(10, 11, Direction::Horizontal,5) == (string)("merK_"));
    CHECK(b.read(10, 10, Direction::Horizontal,6) == (string)("0merK_"));
    CHECK_NOTHROW(b.post(10,13, Direction::Horizontal, "XYZ"));

    // CHCECK IF EVERY CHAR IS IN HIS PLACE AFTER OVERRIDING (HORIZONTAL)
    CHECK(b.read(10, 10, Direction::Horizontal,4) == (string)("0meX"));
    CHECK(b.read(10, 10, Direction::Horizontal,5) == (string)("0meXY"));
    CHECK(b.read(10, 10, Direction::Horizontal,6) == (string)("0meXYZ"));
    CHECK(b.read(10, 10, Direction::Horizontal,7) == (string)("0meXYZ_"));
    CHECK(b.read(10, 9, Direction::Horizontal,7) == (string)("_0meXYZ"));
}

TEST_CASE("check Vertical - post & read") {
    Board b;
    // CHECK IF POSTED SUCCESFULLY (NO - THROW)
    CHECK_NOTHROW(b.post(10,10, Direction::Vertical, "abcde"));

    // CHCECK IF EVERY CHAR IS IN HIS PLACE (VERTICAL)
    CHECK(b.read(10, 10, Direction::Vertical,1) == (string)("a"));
    CHECK(b.read(10, 10, Direction::Vertical,2) == (string)("ab"));
    CHECK(b.read(10, 10, Direction::Vertical,3) == (string)("abc"));
    CHECK(b.read(10, 10, Direction::Vertical,4) == (string)("abcd"));
    CHECK(b.read(10, 10, Direction::Vertical,5) == (string)("abcde"));
    CHECK(b.read(10, 10, Direction::Vertical,6) == (string)("abcde_"));
    CHECK(b.read(10, 10, Direction::Vertical,7) == (string)("abcde__"));
    CHECK(b.read(10, 10, Direction::Vertical,7) == (string)("abcde__"));

    // CHECK IF POSTED SUCCESFULLY (NO - THROW)
    CHECK_NOTHROW(b.post(13,10, Direction::Vertical, "ba"));

    // CHCECK IF EVERY CHAR IS IN HIS PLACE AFTER OVERRIDING (VERTICAL)
    CHECK(b.read(10, 10, Direction::Vertical,4) == (string)("abcb"));
    CHECK(b.read(10, 10, Direction::Vertical,5) == (string)("abcba"));
    CHECK(b.read(10, 10, Direction::Vertical,6) == (string)("abcba_"));
    




}

TEST_CASE("check Horizontal & Vertical - post & read"){
    Board b;

    // CHECK IF POSTED SUCCESFULLY (NO - THROW)
    CHECK_NOTHROW(b.post(10,10, Direction::Horizontal, "abcde"));
    CHECK_NOTHROW(b.post(10,10, Direction::Vertical, "xyz"));

    // CHCECK IF EVERY CHAR IS IN HIS PLACE AFTER OVERRIDING (VERTICAL ENTRY OVERRIDING FIRST CHAR OF HORIZONTAL ENTRY)
    CHECK(b.read(10, 10, Direction::Horizontal,6) == (string)("xbcde_"));
    CHECK(b.read(10, 10, Direction::Vertical,6) == (string)("xyz___"));

    // CHECK IF POSTED SUCCESFULLY (NO - THROW)
    // VERTICAL ENTRY OVERRIDES HORIZONTAL ENTRY FROM SECOND CHAR
    CHECK_NOTHROW(b.post(10,11, Direction::Vertical, "uvw"));

    // CHCECK IF EVERY CHAR IS IN HIS PLACE AFTER OVERRIDING (VERTICAL ENTRY OVERRIDING SECOND CHAR OF HORIZONTAL ENTRY)
    CHECK(b.read(10, 10, Direction::Horizontal,5) == (string)("xucde"));
    CHECK(b.read(10, 11, Direction::Vertical,4) == (string)("uvw_"));
    CHECK(b.read(11, 10, Direction::Horizontal,2) == (string)("yv"));
    CHECK(b.read(11, 10, Direction::Horizontal,3) == (string)("yv_"));
    CHECK(b.read(12, 10, Direction::Horizontal,2) == (string)("zw"));
    CHECK(b.read(12, 10, Direction::Horizontal,3) == (string)("zw_"));

    // CHECK IF POSTED SUCCESFULLY (NO - THROW)
    CHECK_NOTHROW(b.post(11,10, Direction::Horizontal, "mnk"));

    CHECK(b.read(10, 10, Direction::Vertical,3) == (string)("xmz"));
    CHECK(b.read(10, 10, Direction::Vertical,4) == (string)("xmz_"));
    CHECK(b.read(10, 11, Direction::Vertical,3) == (string)("unw"));
    CHECK(b.read(10, 11, Direction::Vertical,4) == (string)("unw_"));
    CHECK(b.read(10, 12, Direction::Vertical,3) == (string)("ck_"));
    CHECK(b.read(10, 12, Direction::Vertical,4) == (string)("ck__"));

}


