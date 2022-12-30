//
// Created by Utilizador on 26-Dec-22.
//

#ifndef AIRTRANSPORT_DATABASE_H
#define AIRTRANSPORT_DATABASE_H
#include "Airport.h"
#include "Airline.h"
#include "Graph.h"
#include <fstream>
#include <vector>
#include <unordered_set>
#include "list"

class Database {
private:
    unordered_map<string, Airport> airports;
    unordered_set<Airline, Airline_hash> airlines;
    Graph Everything;

public:

    void readAirports();
    void readAirlines();
    Database();
    int distance(string src, string dest);
    vector<vector<vector<string>>> path(string src, string dest);
    void graphEverything();
};


#endif //AIRTRANSPORT_DATABASE_H
