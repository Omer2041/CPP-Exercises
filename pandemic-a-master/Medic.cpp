#include "Medic.hpp"

using namespace std;

namespace pandemic
{
    string Medic::role() { return ""; }

    Medic &Medic::take_card(City c)
    {
        return *this;
    }
    Medic &Medic::drive(City c) {
        return *this;
    }
    Medic &Medic::fly_direct(City c){return *this;}
    Medic &Medic::fly_charter(City c){return *this;}
    Medic &Medic::fly_shuttle(City c){return *this;}
    Medic &Medic::build(){return *this;}
    Medic &Medic::discover_cure(Color col){return *this;}
    Medic &Medic::treat(City c){return *this;}

}