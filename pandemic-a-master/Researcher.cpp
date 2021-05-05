#include "Researcher.hpp"

using namespace std;

namespace pandemic
{
    string Researcher::role() { return ""; }

    Researcher &Researcher::take_card(City c)
    {
        return *this;
    }
    Researcher &Researcher::drive(City c) {
        return *this;
    }
    Researcher &Researcher::fly_direct(City c){return *this;}
    Researcher &Researcher::fly_charter(City c){return *this;}
    Researcher &Researcher::fly_shuttle(City c){return *this;}
    Researcher &Researcher::build(){return *this;}
    Researcher &Researcher::discover_cure(Color col){return *this;}
    Researcher &Researcher::treat(City c){return *this;}

}