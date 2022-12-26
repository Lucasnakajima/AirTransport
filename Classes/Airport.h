//
// Created by Utilizador on 26-Dec-22.
//

#ifndef AIRTRANSPORT_AIRPORT_H
#define AIRTRANSPORT_AIRPORT_H
#include <string>
using namespace std;
///Classe para os Aeroportos.
///
///Um Aeroporto é identificado por um código.
class Airport {
private:
    string Code; /*!< Código do Aeroporto*/
    string Name;
    string City;
    string Country;
    float Latitude;
    float Longitude;

public:
    ///set Code with @param Code
    void setCode(string Code);
    ///set Name with @param Name
    void setName(string Name);
    ///set City with @param City
    void setCity(string City);
    ///set Country with @param Country
    void setCountry(string Country);
    ///set Latitude with @param Latitude
    void setLatitude(float Latitude);
    ///set Longitude with @param Longitude
    void setLongitude(float Longitude);

    Airport(string Code, string Name, string City, string Country, float Latitude, float Longitude);
};


#endif //AIRTRANSPORT_AIRPORT_H
