#include <string>;
#include "airline.h";
using namespace std;


Airline::Airline(string airline_id, string airline_name, string airline_alias, string iata_code) {
    this->airline_id = airline_id;
    this->airline_name = airline_name;
    this->airline_alias = airline_alias;
    this->iata_code = iata_code;
}
Airline::Airline(string airline_id, string iata_code){
    this->airline_id = airline_id;
    this->iata_code = iata_code;
}

string Airline::getAirlineId(){
    return airline_id;
}

string Airline::getAirlineName(){
    return airline_name;
}

string Airline::getAirlineAlias(){
    return airline_alias;
}

string Airline::getAirlineIataCode(){
    return iata_code;
}

string Airline::getAirlineCountry(){
    return country;
}