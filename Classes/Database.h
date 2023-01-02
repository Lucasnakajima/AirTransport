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
#include <cmath>
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
    void graphEverything();
    vector<vector<vector<string>>> path(string src, string dest, vector<string>& airlines);
    double coordsdist(double lat1, double lon1, double lat2, double lon2);
    vector<vector<vector<string>>> cityPath(string src, string dest, vector<string>& airlines);
    vector<vector<vector<string>>> coordsPath(double srcLati, double srcLongi, double destLati, double destLongi, vector<string>& airlines);

};


#endif //AIRTRANSPORT_DATABASE_H
