#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;


string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("check with nospaces") {
    CHECK(nospaces(snowman(11114411)) == nospaces(string("      \n _===_\n (.,.) \n ( : ) \n ( : )")));
    CHECK(nospaces(snowman(33232124)) == nospaces(string("   _   \n  /_\\ \n\\(o_O) \n (] [)>\n (   ) \n")));

}

TEST_CASE("test hats") {
    CHECK(snowman(11114411) == string("      \n _===_\n (.,.) \n ( : ) \n ( : )"));
    CHECK(snowman(21114411) == string("  ___ \n .....\n (.,.) \n ( : ) \n ( : )"));
    CHECK(snowman(31114411) == string("   _  \n  /_\\ \n (.,.) \n ( : ) \n ( : )"));
    CHECK(snowman(41114411) == string("  ___ \n (_*_)\n (.,.) \n ( : ) \n ( : )"));
}

TEST_CASE("test base") {
    CHECK(snowman(11114411) == string("      \n _===_\n (.,.) \n ( : ) \n ( : )"));
    CHECK(snowman(11114412) == string("      \n _===_\n (.,.) \n ( : ) \n (\" \")"));
    CHECK(snowman(11114413) == string("      \n _===_\n (.,.) \n ( : ) \n (___)"));
    CHECK(snowman(11114414) == string("      \n _===_\n (.,.) \n ( : ) \n (   )"));
}

TEST_CASE("test torso") {
    CHECK(snowman(11114411) == string("      \n _===_\n (.,.) \n ( : ) \n ( : )"));
    CHECK(snowman(11114421) == string("      \n _===_\n (.,.) \n (] [) \n ( : )"));
    CHECK(snowman(11114431) == string("      \n _===_\n (.,.) \n (> <) \n ( : )"));
    CHECK(snowman(11114441) == string("      \n _===_\n (.,.) \n (   ) \n ( : )"));
}

TEST_CASE("test nose") {
    CHECK(snowman(11114411) == string("      \n _===_\n (.,.) \n ( : ) \n ( : )"));
    CHECK(snowman(12114411) == string("      \n _===_\n (...) \n ( : ) \n ( : )"));
    CHECK(snowman(13114411) == string("      \n _===_\n (._.) \n ( : ) \n ( : )"));
    CHECK(snowman(14114411) == string("      \n _===_\n (. .) \n ( : ) \n ( : )"));

}

TEST_CASE("test left eye") {
    CHECK(snowman(33132124) == string("   _   \n  /_\\ \n\\(._O) \n (] [)>\n (   ) \n"));
    CHECK(snowman(33232124) == string("   _   \n  /_\\ \n\\(o_O) \n (] [)>\n (   ) \n"));
    CHECK(snowman(33332124) == string("   _   \n  /_\\ \n\\(O_O) \n (] [)>\n (   ) \n"));
    CHECK(snowman(33432124) == string("   _   \n  /_\\ \n\\(-_O) \n (] [)>\n (   ) \n"));

}

TEST_CASE("test right eye") {
    CHECK(snowman(33212124) == string("   _   \n  /_\\ \n\\(o_.) \n (] [)>\n (   ) \n"));
    CHECK(snowman(33222124) == string("   _   \n  /_\\ \n\\(o_o) \n (] [)>\n (   ) \n"));
    CHECK(snowman(33232124) == string("   _   \n  /_\\ \n\\(o_O) \n (] [)>\n (   ) \n"));
    CHECK(snowman(33242124) == string("   _   \n  /_\\ \n\\(o_-) \n (] [)>\n (   ) \n"));

}

TEST_CASE("test left arm") {
    CHECK(snowman(33231124) == string("   _   \n  /_\\ \n (o_O) \n<(] [)>\n (   ) \n"));
    CHECK(snowman(33232124) == string("   _   \n  /_\\ \n\\(o_O) \n (] [)>\n (   ) \n"));
    CHECK(snowman(33233124) == string("   _   \n  /_\\ \n (o_O) \n/(] [)>\n (   ) \n"));
    CHECK(snowman(33234124) == string("   _   \n  /_\\ \n (o_O) \n (] [)>\n (   ) \n"));

}

TEST_CASE("test right arm") {
    CHECK(snowman(33232124) == string("   _   \n  /_\\ \n\\(o_O) \n (] [)>\n (   ) \n"));
    CHECK(snowman(33232224) == string("   _   \n  /_\\ \n\\(o_O)//\n (] [) \n (   ) \n"));
    CHECK(snowman(33232324) == string("   _   \n  /_\\ \n\\(o_O) \n (] [)\\\n (   ) \n"));
    CHECK(snowman(33232424) == string("   _   \n  /_\\ \n\\(o_O) \n (] [) \n (   ) \n"));

}

TEST_CASE("check length") {
    string actual = snowman(11114411);
    string expected = "      \n _===_\n(.,.)\n( : )\n ( : ) ";
    CHECK (actual.length() == expected.length());
}

TEST_CASE("check chars") {
    string actual = snowman(33232124);
    string expected = "   _   \n  /_\\ \n\\(o_O) \n (] [)>\n (   ) \n";
    CHECK (actual == expected);
}

TEST_CASE("wrong input - digits greater than 4") {
    CHECK_THROWS(snowman(62548521));
    CHECK_THROWS(snowman(15423384));
    CHECK_THROWS(snowman(11111119));
}

TEST_CASE("wrong input - digits smaller than 0") {
    CHECK_THROWS(snowman(-62548521));
    CHECK_THROWS(snowman(-15423384));
    CHECK_THROWS(snowman(-11111119));
}

TEST_CASE("wrong input - less than 8 digits") {
    CHECK_THROWS(snowman(233));
    CHECK_THROWS(snowman(9));
    CHECK_THROWS(snowman(14321));
}

TEST_CASE("wrong input - more than 8 digits") {
    CHECK_THROWS(snowman(233412342));
    CHECK_THROWS(snowman(1231124232));
    CHECK_THROWS(snowman(143212111));
}

