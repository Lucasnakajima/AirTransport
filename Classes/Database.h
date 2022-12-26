//
// Created by Utilizador on 26-Dec-22.
//

#ifndef AIRTRANSPORT_DATABASE_H
#define AIRTRANSPORT_DATABASE_H
#include "Airport.h"
#include "Airline.h"
#include <fstream>
#include <vector>
#include <unordered_set>
#include "list"

class Database {
private:
    //TODO
    //unordered_set<Airport> airports;
    list<Airport> airports;
    list<Airline> airlines;

public:
    void readAirports();
    void readAirlines();
    Database();
};


#endif //AIRTRANSPORT_DATABASE_H
