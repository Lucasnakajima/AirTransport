//
// Created by Utilizador on 26-Dec-22.
//

#ifndef AIRTRANSPORT_AIRLINE_H
#define AIRTRANSPORT_AIRLINE_H
#include <string>
using namespace std;
///Classe para as Companhias Aéreas.
///
///Uma Companhia é identificada pelo seu código ICAO.
class Airline {
private:
    string Code; /*!< Código da Companhia Aérea*/
    string Name; /*!< Nome da Companhia Aérea*/
    string Callsign; /*!< Alcunha da Companhia Aérea*/
    string Country; /*!< País da Companhia Aérea*/
public:
    ///Set Code with @param Code
    void setCode(string Code);
    ///Set Name with @param Name
    void setName(string Name);
    ///Set Callsign with @param Callsign
    void setCallsign(string Callsign);
    ///Set Country with @param Country
    void setCountry(string Country);
    ///Creates a new Class without Callsign
    Airline(string Code, string Name, string Country);
    ///create a new Class with @param Callsign
    Airline(string Code, string Name,string Callsign, string Country);
};


#endif //AIRTRANSPORT_AIRLINE_H
