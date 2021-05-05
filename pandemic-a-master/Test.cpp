#include "doctest.h"
#include "Board.hpp"
#include <string>
#include <algorithm>
#include <cstdlib>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;
using namespace std;

TEST_CASE("Test Official's roles func")
{
    Board board;
    FieldDoctor fd{board, City::Johannesburg};
    Virologist v{board, City::Atlanta};
    Medic m{board, City::SanFrancisco};
    OperationsExpert op{board, City::Madrid};
    Dispatcher d{board, City::Madrid};
    GeneSplicer gs{board, City::NewYork};
    Researcher r{board, City::Osaka};
    Scientist s{board, City::SaoPaulo, 2};

    CHECK_EQ(fd.role(), "FieldDoctor");
    CHECK_EQ(op.role(), "OperationsExpert");
    CHECK_EQ(d.role(), "Dispatcher");
    CHECK_EQ(s.role(), "Scientist");
    CHECK_EQ(r.role(), "Researcher");
    CHECK_EQ(m.role(), "Medic");
    CHECK_EQ(v.role(), "Virologist");
    CHECK_EQ(gs.role(), "GeneSplicer");
}

TEST_CASE("Start Game")
{
    Board board;
    CHECK(board.is_clean());

    CHECK_THROWS(board[City::Lima] = -1);

    Player player(board, City::Lima);
    player.take_card(City::Lima);
    CHECK_THROWS(player.treat(City::Lima));

    board[City::Lima] = 1;
    CHECK(!board.is_clean());

    player.treat(City::Lima);
    CHECK(board[City::Lima] == 0);
    CHECK(board.is_clean());

    // Check the connect between citys
    Player a(board, City::Baghdad);
    Player b(board, City::BuenosAires);
    CHECK_THROWS(a.drive(City::Bogota));
    CHECK_THROWS(a.drive(City::Sydney));
    CHECK_THROWS(b.drive(City::Mumbai));
    CHECK_THROWS(b.drive(City::Jakarta));

    a.take_card(City::Baghdad);
    b.take_card(City::BuenosAires);
    a.build();
    CHECK_THROWS(a.fly_shuttle(City::BuenosAires));
    b.build();
    CHECK_NOTHROW(a.fly_shuttle(City::BuenosAires));
    CHECK(!board.is_clean());
}

TEST_CASE("Test Officials")
{
    Board board;

    FieldDoctor fd{board, City::Johannesburg};
    CHECK_THROWS(fd.build());
    CHECK_THROWS(fd.treat(City::Johannesburg));
    board[City::Johannesburg] = 2;
    board[City::Kinshasa] = 1;
    CHECK_NOTHROW(fd.treat(City::Kinshasa));
    CHECK_NOTHROW(fd.treat(City::Johannesburg));
    CHECK_NOTHROW(fd.drive(City::Khartoum));
    CHECK_NOTHROW(fd.drive(City::Kinshasa));

    Virologist v{board, City::Atlanta};
    CHECK_THROWS(v.build());
    v.take_card(City::Sydney)
        .take_card(City::LosAngeles);
    CHECK_THROWS(v.treat(City::MexicoCity));
    CHECK_NOTHROW(v.treat(City::LosAngeles));
    CHECK_NOTHROW(v.treat(City::Sydney));

    Medic m{board, City::SanFrancisco};
    CHECK_THROWS(m.build());
    CHECK_THROWS(m.treat(City::SanFrancisco));
    board[City::SanFrancisco] = 4;
    CHECK_NOTHROW(m.treat(City::SanFrancisco));
    CHECK_EQ(board[City::SanFrancisco], 0);

    OperationsExpert op{board, City::Madrid};
    CHECK_THROWS(op.treat(City::Madrid));
    CHECK_NOTHROW(op.build());
    board[City::Madrid] = 1;
    CHECK_NOTHROW(op.treat(City::Madrid));

    Dispatcher d{board, City::Madrid};
    CHECK_THROWS(d.build());
    CHECK_THROWS(d.treat(City::Madrid));
    board[City::Madrid] = 1;
    CHECK_NOTHROW(d.treat(City::Madrid));
    CHECK_NOTHROW(d.fly_direct(City::Manila));

    GeneSplicer gs{board, City::NewYork};
    CHECK_THROWS(gs.build());
    gs.take_card(City::Sydney)
        .take_card(City::LosAngeles)
        .take_card(City::Miami)
        .take_card(City::Algiers)
        .take_card(City::Washington);
    CHECK_THROWS(m.treat(City::NewYork));
    board[City::NewYork] = 1;
    CHECK_NOTHROW(m.treat(City::NewYork));
    CHECK_NOTHROW(gs.discover_cure(Color::Blue));

    Researcher r{board, City::Osaka};
    CHECK_THROWS(r.build());
    CHECK_THROWS(r.treat(City::Osaka));
    board[City::Osaka] = 1;
    CHECK_NOTHROW(r.treat(City::Osaka));
    CHECK_NOTHROW(r.discover_cure(Color::Red));

    Scientist s{board, City::SaoPaulo, 2};
    CHECK_THROWS(s.build());
    CHECK_THROWS(m.treat(City::SaoPaulo));
    board[City::SaoPaulo] = 1;
    CHECK_NOTHROW(m.treat(City::SaoPaulo));
    s.take_card(City::Algiers)
        .take_card(City::Riyadh);

    CHECK_NOTHROW(s.discover_cure(Color::Yellow));
}
