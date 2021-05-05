#include "OperationsExpert.hpp"

using namespace std;

namespace pandemic
{
    string OperationsExpert::role() { return ""; }

    OperationsExpert &OperationsExpert::take_card(City c)
    {
        return *this;
    }
    OperationsExpert &OperationsExpert::drive(City c) {
        return *this;
    }
    OperationsExpert &OperationsExpert::fly_direct(City c){return *this;}
    OperationsExpert &OperationsExpert::fly_charter(City c){return *this;}
    OperationsExpert &OperationsExpert::fly_shuttle(City c){return *this;}
    OperationsExpert &OperationsExpert::build(){return *this;}
    OperationsExpert &OperationsExpert::discover_cure(Color col){return *this;}
    OperationsExpert &OperationsExpert::treat(City c){return *this;}

}