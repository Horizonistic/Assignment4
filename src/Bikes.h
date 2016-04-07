#ifndef _BIKES_H_
#define _BIKES_H_

#include <fstream>
#include <string.h>
#include "utils/SuperOutput.h"
#include "utils/List.h"
#include "utils/Common.h"

enum status {NO_STATUS, NOT_RENTED, RENTED, ALL};

struct Bike
{
    char manufact[25];
    int id_num;
    status rented_code; //RENTED/NOT_RENTED
    char to_whom[25]; //to whom bike is rented
    int size;
    float cost_per_day;
    bool deleted; //to mark bike as deleted in the list.
    Bike* next_manuf; //pointer to next node in the manufacturers list
    Bike* next_id; //pointer to the next node in the list by ID
    Bike* next; //pointer to the next node in the general list
};

class Bikes
{
public:
    /*
     * readBike:
     *
     * Purpose: reads bikes from the file, creates new Bike object, and calls functions to add bike to the
     * general list, to the list sorted by id, and to the list sorted by the manufacturer.
     *
     * Parameters - handle to the input file, and head pointers to the three lists.
    */
    template<class T>
    void readBike(ifstream& file, List<T>*& head, List<T>*& manuf, List<T>*& id)
    {
        string line;
        int count = 0;
        T* bike = new Bike;

        for (int i = 1; i < 5; i++)
        {
            getline(file, line);

            switch (i)
            {
                case 1: // ID
                    bike->id_num = Common::stringToInt(line);
                    break;

                case 2: // Size?
                    bike->size = Common::stringToInt(line);
                    break;

                case 3: // $/day
                    bike->cost_per_day = Common::stringToInt(line);
                    break;

                case 4: // Manufacturer
                    strcpy(bike->manufact, line.c_str());
                    break;

                default:
                    break;
            }
        }

        head->addLast(bike);

        if (id->isEmpty())
        {
            id->addLast(bike);
        }
        else
        {
            id->insertOrdered(bike, ID);
        }

        if (manuf->isEmpty())
        {
            manuf->addLast(bike);
        }
        else
        {
            manuf->insertOrdered(bike, MANUF);
        }
    }


    /*
     * addBike:-
     *
     * Purpose: adds bike to the general list
     *
     * Parameters: pointer to the first node in the list, pointer to the new node
     *
     * Returns pointed to the first node in the list.
     *
     * This function is overloaded with two other functions below
    */
    template<class T>
    T* addBike(T* head, T* new_bike)
    {
        // TODO
    }


    /*
     * *printBike:-
     *
     * Purpose: Prints any list of bikes, that have not been deleted, depending on the
     * status, and the head pointer passed. If status is RENTED, you print only bikes
     * that are rented. If status is ALL, you print the entire list of (not deleted)
     * bikes. Note, that depending on the list, you pointer assignments should be
     * different.
     * The last part is not applicable if you choose not to implement sorted list
     *
     * Parameters:
     * Bike* - pointer to the first node of the list of bikes.
     * order - needed to control pointer re-assignment. I.e. if order == ID,
     * you should move along the list, sorted by ID.
     * status - Determines which bikes to print from the list. I.e. rented, not
     * rented, or all.
    */
    template<class T>
    void printBikes(T*, order, status)
    {
        // TODO
    }


    /*
     * do_transact:-
     *
     * Purpose: Reads the ID, number of days from the file, and depending on the status
     * (RENTED/NOT_RENTED) either rents bike to the person (in which case you need to
     * read person's name from the file, or performs return transaction. If transaction
     * is rented, you should also display the total cost of the rent
     * (number of days * cost of rent per day).
     * in both cases, if status of bike does not correspond to the type of the
     * transaction (i.e. you try to rent the bike which status is RENTED), you need to
     * output an appropriate message and return.
    */
    template<class T>
    void doTransaction(SuperOutput &, T*, status)
    {
        // TODO
    }


    /*
     * del_id_bike:-
     *
     * Purpose: Finds the bike by the ID in the list and sets its deleted flag to true.
     * Note, that you do not delete the node. You set its deleted flag to true.
     *
     * Parameters:
     * fstream object to the file to read the bike's ID
     * pointer to the head of the bike's list sorted by ID. If you did not implement
     * the sorted list, pass there a pointer to the head of the general list.
    */
    template<class T>
    void deleteIdBike(SuperOutput &, T*)
    {
        // TODO
    }


    /*
     * del_manuf:-
     *
     * Purpose: Finds the bike by the manufacturer's name in the list and sets its
     * deleted flag to true.
     *
     * Parameters: as above.
    */
    template<class T>
    void deleteManufacturer(SuperOutput &, T*)
    {
        // TODO
    }


    /*
     * deleteBikes:-
     *
     * Purpose: To traverse the general list of bikes and deletes all the nodes in
     * it, releasing back the memory. It is called before your program exits.
     * Note, that if you implemented any dynamically allocated memory in the node,
     * you will need to release that memory first, before deleting the node itself.
     *
     * Parameters: pointer to the head of the general list of bikes.
    */
    template<class T>
    void deleteBikes(T *)
    {
        // TODO
    }


    /*
     * init:-
     *
     * Purpose: This function initializes the new Bike's object to all default values
     * (char array should be initialized to ""
    */
    Bike* init()
    {
        struct Bike* bike = (struct Bike*) calloc(1, sizeof(struct Bike));

        strcpy(bike->manufact, "");
        bike->id_num = 0;
        bike->rented_code = NOT_RENTED;
        strcpy(bike->to_whom, "");
        bike->size = 0;
        bike->cost_per_day = 0;
        bike->deleted = false;
        bike->next_manuf = 0;
        bike->next_id = 0;
        bike->next = 0;

        return bike;
    }

};


#endif /* _BIKES_H_*/