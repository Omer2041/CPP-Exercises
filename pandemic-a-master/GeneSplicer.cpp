#include "GeneSplicer.hpp"

using namespace std;

namespace pandemic
{
    string GeneSplicer::role() { return ""; }

    GeneSplicer &GeneSplicer::take_card(City c)
    {
        return *this;
    }
    GeneSplicer &GeneSplicer::drive(City c) {
        return *this;
    }
    GeneSplicer &GeneSplicer::fly_direct(City c){return *this;}
    GeneSplicer &GeneSplicer::fly_charter(City c){return *this;}
    GeneSplicer &GeneSplicer::fly_shuttle(City c){return *this;}
    GeneSplicer &GeneSplicer::build(){return *this;}
    GeneSplicer &GeneSplicer::discover_cure(Color col){return *this;}
    GeneSplicer &GeneSplicer::treat(City c){return *this;}

}