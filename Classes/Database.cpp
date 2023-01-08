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
            airport.setGraphIndex(i);
            g.nodes[i].airport=airport;
            airports[row[0]] = airport;
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
                airlines.insert(airline);
            }
            else{
                Airline airline(row[0],row[1],row[2],row[3]);
                airlines.insert(airline);
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

double Database::coordsdist(double lat1, double lon1, double lat2, double lon2) {
    double pi=3.141592653589793;
    double dLat = (lat2 - lat1) *
                  pi / 180.0;
    double dLon = (lon2 - lon1) *
                  pi / 180.0;

    // convert to radians
    lat1 = (lat1) * pi / 180.0;
    lat2 = (lat2) * pi / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

vector<vector<vector<string>>> Database::path(string src, string dest, vector<string>& airlines) {
    int srci=airports.find(src)->second.getGraphIndex(), desti=airports.find(dest)->second.getGraphIndex();

    vector<vector<string>> paths;
    vector<vector<vector<string>>> allpaths;
    vector<string> path;
    vector<int> Parent[Everything.nodes.size()];
    Everything.bfsPath(Parent, srci, airlines);
    Everything.find_paths(paths, path, Parent, desti);
    for(int i=0; i<paths.size(); i++){
        vector<vector<string>> aux;
        for(int j=paths[i].size()-1; j>0; j--){
            vector<string> tmp;
            tmp.push_back(paths[i][j]);
            int indexfrom=airports.find(paths[i][j])->second.getGraphIndex(), indexto=airports.find(paths[i][j-1])->second.getGraphIndex();
            if(airlines.empty()) {
                tmp.insert(tmp.end(), Everything.nodes[indexfrom].adj.find(indexto)->second.Airlines.begin(),
                           Everything.nodes[indexfrom].adj.find(indexto)->second.Airlines.end());
                aux.push_back(tmp);
            }
            else{
                for(int k=0; k<airlines.size(); k++){
                    for(int l=0; l<Everything.nodes[indexfrom].adj.find(indexto)->second.Airlines.size(); l++){
                        if(airlines[k] == Everything.nodes[indexfrom].adj.find(indexto)->second.Airlines[l]){
                            tmp.push_back(Everything.nodes[indexfrom].adj.find(indexto)->second.Airlines[l]);
                        }
                    }
                }
                aux.push_back(tmp);
            }
        }
        vector<string> tmp;
        tmp.push_back(paths[i][0]);
        aux.push_back(tmp);
        allpaths.push_back(aux);
    }


    return allpaths;
}

vector<vector<vector<string>>> Database::cityPath(string srcCity, string srcCountry, string destCity, string destCountry, vector<string>& airlines) {
    vector<string> srci, desti;
    for(auto it : airports){
        if(it.second.getCity() == srcCity and it.second.getCountry() == srcCountry)
            srci.push_back(it.second.getCode());
        else if(it.second.getCity() == destCity and it.second.getCountry() == destCountry)
            desti.push_back(it.second.getCode());
    }
    vector<vector<vector<string>>> allpaths;
    for(int i=0; i<srci.size(); i++){
        for(int j=0; j<desti.size(); j++){

            vector<vector<vector<string>>> tmp = path(srci[i], desti[j], airlines);
            if(allpaths.empty()) {
                allpaths.insert(allpaths.end(), tmp.begin(), tmp.end());
            }
            else if(tmp[0].size() < allpaths[0].size()) {
                allpaths.clear();
                allpaths.insert(allpaths.end(), tmp.begin(), tmp.end());
            }
            else if(tmp[0].size() == allpaths[0].size()){
                allpaths.insert(allpaths.end(), tmp.begin(), tmp.end());
            }
        }
    }
    return allpaths;

}

vector<vector<vector<string>>> Database::coordsPath(double srcLati, double srcLongi, double destLati, double destLongi, vector<string>& airlines) {
    vector<string> srci, desti;
    double pi=3.141592653589793;
    for(auto it : airports){
        double airplati = it.second.getLatitude(), airplongi=it.second.getLongitude();
        double distancesrc = coordsdist(airplati, airplongi, srcLati, srcLongi);
        double distancedest =coordsdist(airplati, airplongi, destLati, destLongi);
        if(distancesrc < 50)
            srci.push_back(it.second.getCode());
        if(distancedest < 50)
            desti.push_back(it.second.getCode());
    }
    vector<vector<vector<string>>> allpaths;
    for(int i=0; i<srci.size(); i++){
        for(int j=0; j<desti.size(); j++){
            vector<string> airlines;
            vector<vector<vector<string>>> tmp = path(srci[i], desti[j], airlines);
            if(allpaths.empty()) {
                allpaths.insert(allpaths.end(), tmp.begin(), tmp.end());
            }
            else if(tmp[0].size() < allpaths[0].size()) {
                allpaths.clear();
                allpaths.insert(allpaths.end(), tmp.begin(), tmp.end());
            }
            else if(tmp[0].size() == allpaths[0].size()){
                allpaths.insert(allpaths.end(), tmp.begin(), tmp.end());
            }
        }
    }
    return allpaths;
}

