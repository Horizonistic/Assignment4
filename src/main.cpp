#include <iostream>

#include "utils/SuperOutput.h"
#include "Bikes.h"
#include "utils/Common.h"


using namespace std;

int main()
{
    string inputFilename = "prog_4_dat_file.dat";
    string outputFilename = "output.txt";
    Bikes* bikes = new Bikes;
    List<Bike>* primary = new List<Bike>;
    List<Bike>* sortedManufacturer = new List<Bike>;
    List<Bike>* sortedID = new List<Bike>;

    SuperOutput* so = new SuperOutput(outputFilename);

    string line = "";
    ifstream file;
    file.open(inputFilename);
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, line);
            int integer = Common::stringToInt(line);

            switch (integer)
            {
                case 1:
                    bikes->readBike(file, primary, sortedID, sortedManufacturer);
                    break;

                case 2:
                    break;

                case 3:
                    break;

                case 4:
                    break;

                case 5:
                    break;

                case 6:
                    break;

                case 7:
                    break;

                case 8:
                    break;

                case 9:
                    break;

                case 10:
                    break;

                default:
                    break;
            }
            //cout << line << endl;
        }
    }

    sortedID->dump(ID);

    /*
    Bike* bike = new Bike;
    bike->id_num = 1;
    Bike* bike2 = new Bike;
    bike2->id_num = 2;
    Bike* bike3 = new Bike;
    bike3->id_num = 3;
    Bike* bike4 = new Bike;
    bike4->id_num = 4;
    Bike* bike5 = new Bike;
    bike5->id_num = 5;
    Bike* bike6 = new Bike;
    bike6->id_num = 6;

    //bikes->init();
    primary->addLast(bike);
    primary->addLast(bike2);
    primary->addLast(bike3);
    primary->addLast(bike4);
    primary->addLast(bike5);
    primary->addNth(6, bike6);
    primary->dump();
    */

    cout << "wut";
}