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
///Classe para a Database.
///
///A database é apenas para gerenciamento das varíaveis.


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
    ///Os melhores caminhos no grafo, com os aeroportos. Usando o algoritmo de Djikstra de complexidade O(V^2)
    vector<vector<vector<string>>> path(string src, string dest, vector<string>& airlines);
    double coordsdist(double lat1, double lon1, double lat2, double lon2);
    ///Os melhores caminhos no grafo, com as cidades aeroportos. Usando o algoritmo de Djikstra de complexidade O(V^2)
    vector<vector<vector<string>>>cityPath(string srcCity, string srcCountry, string destCity, string destCountry, vector<string> &airlines);
    ///Os melhores caminhos no grafo, com as coordenadas dos aeroportos. Usando o algoritmo de Djikstra de complexidade O(V^2)
    vector<vector<vector<string>>> coordsPath(double srcLati, double srcLongi, double destLati, double destLongi, vector<string>& airlines);

    unordered_set<string> airportMaxY(string airport, int y);

    unordered_set<string> airportList(string airport, int code);
};


#endif //AIRTRANSPORT_DATABASE_H
