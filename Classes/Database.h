//
// Created by Utilizador on 26-Dec-22.
//

#ifndef AIRTRANSPORT_DATABASE_H
#define AIRTRANSPORT_DATABASE_H
#include "Airport.h"
#include <fstream>
#include <vector>
#include "list"

class Database {
private:
    list<Airport> airports;

public:
    void readAirports();
    Database();
};


#endif //AIRTRANSPORT_DATABASE_H
