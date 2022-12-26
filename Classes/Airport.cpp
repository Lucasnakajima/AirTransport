//
// Created by Utilizador on 26-Dec-22.
//

#include "Airport.h"

void Airport::setCode(string Code) {
    this->Code = Code;
}

void Airport::setName(string Name) {
    this->Name = Name;
}

void Airport::setCity(string City) {
    this->City = City;
}

void Airport::setCountry(string Country) {
    this->Country = Country;
}

void Airport::setLatitude(float Latitude) {
    this->Latitude = Latitude;
}

void Airport::setLongitude(float Longitude) {
    this->Longitude = Longitude;
}

Airport::Airport(string Code, string Name, string City, string Country, float Latitude, float Longitude) {
    setCity(City);
    setCode(Code);
    setCountry(Country);
    setName(Name);
    setLatitude(Latitude);
    setLongitude(Longitude);
}

int Airport::hashCode() {
    return (Name.length()%10 + static_cast<int>(Latitude))%3020;
}
