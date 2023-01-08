//
// Created by Utilizador on 27-Dec-22.
//

#ifndef AIRTRANSPORT_MENU_H
#define AIRTRANSPORT_MENU_H
#include "Database.h"
#include <stdlib.h>
///Classe para o Menu.
///
///Um menu apenas apresenta as opcoes.
class Menu {
private:
    Database database;
public:
    Menu();
    void run();

    void pathByCoordinates(double srcLati, double srcLongi, double destLati, double desLongi, vector<string> airlines);

    void pathByCity(string srcCity, string srcCountry, string destCity, string destCountry, vector<string> airlines);

    void pathByAirport(string srcAirport, string destAirport, vector<string> airlines);

    vector<string> airlineSubmenu();

    bool inputTest(char choice, vector<int> values);

    void flightsByAirport(string airport);

    void airlinesByAirport(string airport);

    void cityByAirport(string airport);

    void airportMaxYByAirport(string airport, int y);
};


#endif //AIRTRANSPORT_MENU_H
