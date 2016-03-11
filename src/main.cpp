#include <iostream>

#include "utils/SuperOutput.h"
#include "Bikes.h"
#include "utils/List.h"


using namespace std;
int main()
{
    Bikes* bikes = new Bikes;
    List<Bike>* list = new List<Bike>;

    Bike* bike = new Bike;
    bike->id_num = 1;
    Bike* bike2 = new Bike;
    bike2->id_num = 2;

    //bikes->init();
    list->addFirst(bike);
    list->addFirst(bike2);
}