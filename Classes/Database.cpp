//
// Created by Utilizador on 26-Dec-22.
//

#include <sstream>
#include "Database.h"

Database::Database() {}

void Database::readAirports() {
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
            airports.push_back(airport);
        }
    }

}

