//
// Created by Utilizador on 26-Dec-22.
//

#include <sstream>
#include "Database.h"

Database::Database() {
    readAirports();
    readAirlines();
    graphEverything();
}

void Database::readAirports() {
    Graph g(3019, true);
    int i=1;
    fstream fin("airports.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    if(fin.is_open()){
        getline(fin, line);
        while(getline(fin, line)){
            row.clear();
            stringstream str(line);

            while(getline(str, word, ',')) {
                row.push_back(word);
            }
            Airport airport(row[0], row[1], row[2], row[3], stof(row[4]), stof(row[5]));
            g.nodes[i].airport=airport;
            airports.push_back(airport);
            i++;
        }
    }
    Everything = g;
}

void Database::readAirlines() {
    fstream fin("airlines.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    if(fin.is_open()){
        getline(fin, line);
        while(getline(fin, line)){
            row.clear();
            stringstream str(line);

            while(getline(str, word, ',')) {
                row.push_back(word);
            }
            if(row[2]=="_"){
                Airline airline(row[0],row[1],row[3]);
                airlines.push_back(airline);
            }
            else{
                Airline airline(row[0],row[1],row[2],row[3]);
                airlines.push_back(airline);
            }
        }
    }
}

void Database::graphEverything() {
    fstream fin("flights.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    if(fin.is_open()){
        getline(fin, line);
        while(getline(fin, line)){
            row.clear();
            stringstream str(line);

            while(getline(str, word, ',')) {
                row.push_back(word);
            }
            Everything.addEdge(row[0], row[1], row[2]);
        }
    }
}

/*vector<Database::flight> Database::distance(string src, string dest) {
    return Everything.distance(src, dest);
}*/

int Database::distance(string src, string dest) {
    return Everything.distance(src, dest);
}

int Database::path(string src, string dest) {
    vector<int> path = Everything.Path(src, dest);
    return path.size();
}
