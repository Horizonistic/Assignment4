//
// Created by Infernia on 03/03/2016.
//

#include "Bikes.h"

void Bikes::readBike(fstream &, Bike*& head, Bike*& manuf, Bike*& id)
{
    // TODO
}

Bike * Bikes::addBike(Bike* head, Bike* new_bike)
{
    // TODO
}

void Bikes::printBikes(Bike*, order, status)
{
    // TODO
}

void Bikes::doTransaction(fstream &, Bike*, status)
{
    // TODO
}

void Bikes::deleteIdBike(fstream &, Bike*)
{
    // TODO
}

void Bikes::deleteManufacuter(fstream &, Bike*)
{
    // TODO
}

void Bikes::deleteBikes(Bike *)
{
    // TODO
}

void Bikes::init(Bike * bikePointer) {
    /*
     * char manufact[25];
    int id_num;
    status rented_code; //RENTED/NOT_RENTED
    char to_whom[25]; //to whom bike is rented
    int size;
    float cost_per_day;
    bool deleted; //to mark bike as deleted in the list.
    Bike *next_manuf; //pointer to next node in the manufacturers list
    Bike *next_id; //pointer to the next node in the list by ID
    Bike *next; //pointer to the next node in the general list
     */

    *bikePointer->manufact = {''};
    bikePointer->id_num = 0;
    bikePointer->rented_code = NOT_RENTED;
    *bikePointer->to_whom = {''};
    bikePointer->size = 0;
    bikePointer->cost_per_day = 0;
    bikePointer->deleted = false;
    bikePointer->next_manuf = 0;
    bikePointer->next_id = 0;
    bikePointer->next = 0;
}