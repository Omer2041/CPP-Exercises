#include "Scientist.hpp"

using namespace std;

namespace pandemic
{
    string Scientist::role() { return ""; }

    Scientist &Scientist::take_card(City c)
    {
        return *this;
    }
    Scientist &Scientist::drive(City c) {
        return *this;
    }
    Scientist &Scientist::fly_direct(City c){return *this;}
    Scientist &Scientist::fly_charter(City c){return *this;}
    Scientist &Scientist::fly_shuttle(City c){return *this;}
    Scientist &Scientist::build(){return *this;}
    Scientist &Scientist::discover_cure(Color col){return *this;}
    Scientist &Scientist::treat(City c){return *this;}

}