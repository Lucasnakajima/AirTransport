//
// Created by Utilizador on 26-Dec-22.
//

#include "Airline.h"

void Airline::setCode(string Code) {
    this->Code = Code;
}

void Airline::setName(string Name) {
    this->Name = Name;
}

void Airline::setCallsign(string Callsign) {
    this->Callsign = Callsign;
}

void Airline::setCountry(string Country) {
    this->Country = Country;
}

Airline::Airline(string Code, string Name, string Country) {
    setCode(Code);
    setName(Name);
    setCountry(Country);
}

Airline::Airline(string Code, string Name, string Callsign, string Country) {
    setCode(Code);
    setName(Name);
    setCallsign(Callsign);
    setCountry(Country);
}

string Airline::getCode() const {
    return this->Code;
}

string Airline::getName() const {
    return this->Name;
}
bool Airline::operator==(const Airline &a1) const {
    return this->getCode()==a1.getCode();
}
