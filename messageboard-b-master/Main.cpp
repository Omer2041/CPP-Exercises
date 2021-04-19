#include <iostream>
#include "Board.hpp"
#include "Direction.hpp"

using namespace std;
using namespace ariel;

Board emptyBoard()
{
    Board board;
    for (size_t i = 0; i <= 20; i++)
    {
        for (size_t j = 0; j <= 20; j++)
        {
            board.post(i, j, Direction::Horizontal, " ");
        }
    }
    return board;
}

Board XBoard()
{
    Board board;
    for (size_t i = 0; i <= 30; i++)
    {
        for (size_t j = 0; j <= 30; j++)
        {
            if (i == 0)
            {
                // board.post(i, j, Direction::Horizontal, "-");
            }

            if (j == 0)
            {
                board.post(i, j, Direction::Horizontal, "|");
            }

            if (i == j)
            {
                board.post(i, j, Direction::Horizontal, "\\");
                board.post(30 - i, 30, Direction::Horizontal, "|");
                board.post(i, 30 - j, Direction::Horizontal, "/");

            }

        }
    }
    return board;
}

Board cppBoard()
{
    Board board;
    for (size_t i = 0; i <= 50; i++)
    {
            board.post(i, i + 1, Direction::Horizontal, "Thanks for watching");
    }

    board.post(0, 69, Direction::Vertical, "OMeR");
    board.post(50, 0, Direction::Horizontal, "OMeR");

    return board;
}

int main()
{
    Board borders;
    Board snowmans;
    Board blank = emptyBoard();
    Board closed = XBoard();
    Board cpp = cppBoard();

    cout << "******************************************\n******************************************\n     WellCome to OMeR's MessageBoard: \n******************************************\n******************************************\n" << endl;

    cout << "" << endl;





    cout << "Empty Board with borders:\n" << endl;

    //post borders of the board
    borders.post(500, 500, Direction::Horizontal, "left-up");
    borders.post(500, 532, Direction::Horizontal, "right-up");
    borders.post(530, 500, Direction::Horizontal, "left-down");
    borders.post(530, 530, Direction::Horizontal, "right-down");

    borders.show();

    cout << "\n\nSnowman's Board:\n";

    snowmans.post(/*row=*/2000, /*column=*/2600, ariel::Direction::Horizontal, "  /_\\ ");
    snowmans.post(/*row=*/2001, /*column=*/2600, ariel::Direction::Horizontal, "\\(o_.) ");
    snowmans.post(/*row=*/2002, /*column=*/2600, ariel::Direction::Horizontal, " (] [)>");
    snowmans.post(/*row=*/2003, /*column=*/2600, ariel::Direction::Horizontal, " (   ) ");

    snowmans.post(/*row=*/2000, /*column=*/2620, ariel::Direction::Horizontal, " (_*_) ");
    snowmans.post(/*row=*/2001, /*column=*/2620, ariel::Direction::Horizontal, " (.,.) ");
    snowmans.post(/*row=*/2002, /*column=*/2620, ariel::Direction::Horizontal, " ( : ) ");
    snowmans.post(/*row=*/2003, /*column=*/2620, ariel::Direction::Horizontal, " ( : )");

    snowmans.post(/*row=*/2000, /*column=*/2640, ariel::Direction::Horizontal, "   /_\\ ");
    snowmans.post(/*row=*/2001, /*column=*/2640, ariel::Direction::Horizontal, " \\(o_O)");
    snowmans.post(/*row=*/2002, /*column=*/2640, ariel::Direction::Horizontal, "  (] [)>");
    snowmans.post(/*row=*/2003, /*column=*/2640, ariel::Direction::Horizontal, "  (\" \")");

    snowmans.post(/*row=*/2006, /*column=*/2600, ariel::Direction::Horizontal, " _===_ ");
    snowmans.post(/*row=*/2007, /*column=*/2600, ariel::Direction::Horizontal, " (.,.) ");
    snowmans.post(/*row=*/2008, /*column=*/2600, ariel::Direction::Horizontal, " ( : ) ");
    snowmans.post(/*row=*/2009, /*column=*/2600, ariel::Direction::Horizontal, " ( : ) ");

    snowmans.post(/*row=*/2006, /*column=*/2620, ariel::Direction::Horizontal, " (_*_) ");
    snowmans.post(/*row=*/2007, /*column=*/2620, ariel::Direction::Horizontal, " (.,.) ");
    snowmans.post(/*row=*/2008, /*column=*/2620, ariel::Direction::Horizontal, " (> <) ");
    snowmans.post(/*row=*/2009, /*column=*/2620, ariel::Direction::Horizontal, " (___) ");

    snowmans.post(/*row=*/2006, /*column=*/2640, ariel::Direction::Horizontal, " _===_ ");
    snowmans.post(/*row=*/2007, /*column=*/2640, ariel::Direction::Horizontal, " (.,.)/");
    snowmans.post(/*row=*/2008, /*column=*/2640, ariel::Direction::Horizontal, "/(] [) ");
    snowmans.post(/*row=*/2009, /*column=*/2640, ariel::Direction::Horizontal, " (\" \")");

    snowmans.post(/*row=*/2012, /*column=*/2600, ariel::Direction::Horizontal, " (_*_) ");
    snowmans.post(/*row=*/2013, /*column=*/2600, ariel::Direction::Horizontal, " (o_O) ");
    snowmans.post(/*row=*/2014, /*column=*/2600, ariel::Direction::Horizontal, "/( : ) ");
    snowmans.post(/*row=*/2015, /*column=*/2600, ariel::Direction::Horizontal, " ( : ) ");

    snowmans.post(/*row=*/2012, /*column=*/2620, ariel::Direction::Horizontal, " _===_ ");
    snowmans.post(/*row=*/2013, /*column=*/2620, ariel::Direction::Horizontal, " (O_.) ");
    snowmans.post(/*row=*/2014, /*column=*/2620, ariel::Direction::Horizontal, " (] [)>");
    snowmans.post(/*row=*/2015, /*column=*/2620, ariel::Direction::Horizontal, " (___) ");

    snowmans.post(/*row=*/2012, /*column=*/2640, ariel::Direction::Horizontal, "  /_\\ ");
    snowmans.post(/*row=*/2013, /*column=*/2640, ariel::Direction::Horizontal, "\\(o_O) ");
    snowmans.post(/*row=*/2014, /*column=*/2640, ariel::Direction::Horizontal, " (> <) ");
    snowmans.post(/*row=*/2015, /*column=*/2640, ariel::Direction::Horizontal, " ( : ) ");

    snowmans.show();

    cout << "\n\nBlank MessageBoard:\n" << endl;
    blank.show();

    cout << "\n\nSorry, MessageBoard is closed now:\n" << endl;
    closed.show();



    cout << "\n\nOMeR's MessageBoard: \n" << endl;;
    cpp.show();


    cpp.post(0,0,Direction::Horizontal, "overriding overriding overriding overriding");
    cpp.post(0,10,Direction::Vertical, "overriding overriding overriding overriding");
    // cpp.show();


    return 0;
}
