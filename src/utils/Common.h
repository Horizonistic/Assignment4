//
// Created by Infernous on 3/17/2016.
//

#ifndef BIKES_COMMON_H
#define BIKES_COMMON_H

#include <string>
#include <sstream>

using namespace std;

enum order{NO_ORDER, ID, MANUF};

class Common
{
public:
    static int stringToInt(string &text)
    {
        stringstream integer(text);
        int result;
        return integer >> result ? result : 0;
    }
};

#endif //BIKES_COMMON_H
