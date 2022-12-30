//
// Created by Utilizador on 26-Dec-22.
//

#include "Airport.h"

Airport::Airport() {
}

string Airport::getCode() const {
    return this->Code;
}

string Airport::getName() const {
    return this->Name;
}

string Airport::getCity() {
    return this->City;
}

string Airport::getCountry() {
    return this->Country;
}

float Airport::getLatitude() {
    return this->Latitude;
}

float Airport::getLongitude() {
    return this->Longitude;
}

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

void Airport::setGraphIndex(int index) {
    graphIndex = index;
}

int Airport::getGraphIndex() {
    return graphIndex;
}

Airport::Airport(string Code, string Name, string City, string Country, float Latitude, float Longitude) {
    setCity(City);
    setCode(Code);
    setCountry(Country);
    setName(Name);
    setLatitude(Latitude);
    setLongitude(Longitude);
}

bool Airport::operator()(const Airport &a1, const Airport &a2) const {
    return a1.getCode() == a2.getCode();
}

bool Airport::operator==(const Airport &a1) const {
    return this->getCode()==a1.getCode();
}






