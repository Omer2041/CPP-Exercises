#include "Dispatcher.hpp"

using namespace std;

namespace pandemic
{
    string Dispatcher::role() { return ""; }


    Dispatcher &Dispatcher::take_card(City c)
    {
        return *this;
    }
    Dispatcher &Dispatcher::drive(City c) {
        return *this;
    }
    Dispatcher &Dispatcher::fly_direct(City c){return *this;}
    Dispatcher &Dispatcher::fly_charter(City c){return *this;}
    Dispatcher &Dispatcher::fly_shuttle(City c){return *this;}
    Dispatcher &Dispatcher::build(){return *this;}
    Dispatcher &Dispatcher::discover_cure(Color col){return *this;}
    Dispatcher &Dispatcher::treat(City c){return *this;}

}