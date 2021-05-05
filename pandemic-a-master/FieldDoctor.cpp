#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic
{
    string FieldDoctor::role() { return ""; }

    FieldDoctor &FieldDoctor::take_card(City c)
    {
        return *this;
    }
    FieldDoctor &FieldDoctor::drive(City c)
    {
        return *this;
    }
    FieldDoctor &FieldDoctor::fly_direct(City c) { return *this; }
    FieldDoctor &FieldDoctor::fly_charter(City c) { return *this; }
    FieldDoctor &FieldDoctor::fly_shuttle(City c) { return *this; }
    FieldDoctor &FieldDoctor::build() { return *this; }
    FieldDoctor &FieldDoctor::discover_cure(Color col) { return *this; }
    FieldDoctor &FieldDoctor::treat(City c) { return *this; }

}