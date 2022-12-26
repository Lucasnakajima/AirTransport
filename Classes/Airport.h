//
// Created by Utilizador on 26-Dec-22.
//

#ifndef AIRTRANSPORT_AIRPORT_H
#define AIRTRANSPORT_AIRPORT_H
#include <string>
#include <cmath>
using namespace std;
///Classe para os Aeroportos.
///
///Um Aeroporto é identificado por um código IATA.
class Airport {
private:
    string Code; /*!< Código do Aeroporto*/
    string Name; /*!< Nome do Aeroporto*/
    string City; /*!< Cidade do Aeroporto*/
    string Country; /*!< País do Aeroporto*/
    float Latitude; /*!< Latitude do Aeroporto*/
    float Longitude; /*!< Longitude do Aeroporto*/

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

    string getCode() const;
    string getName();
    string getCity();
    string getCountry();
    float getLatitude();
    float getLongitude();

    int hashCode();

    bool operator() (const Airport& a1, const Airport& a2) const;
    bool operator==(const Airport& a1) const;

    Airport(string Code, string Name, string City, string Country, float Latitude, float Longitude);
    Airport();
};
//TODO
/*template<>
struct hash<Airport>
{
    size_t operator()(const Airport & obj) const;
};

struct AirportHasher{
    size_t operator() (const Airport & obj) const;
};
*/

#endif //AIRTRANSPORT_AIRPORT_H
