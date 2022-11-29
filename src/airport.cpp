#include<string>;
#include "airport.h";
using namespace std;

Airport::Airport(string airport_id, string airport_name, string city, string country, string iata_code, string icao_code){
    this->airport_id = airport_id;
    this->airport_name = airport_name;
    this->city = city;
    this->country = country;
    this->iata_code = iata_code;
    this->icao_code = icao_code;
}

string Airport::getAirportId(){
    return airport_id;
}

string Airport::getAirportName(){
    return airport_name;
}   

string Airport::getAirportCity(){
    return country;
}

string Airport::getIataCode(){
    return iata_code;
}

string Airport::getIcaoCode(){
    return icao_code;
}

string Airport::getLatitude(){
    return latitude;
}

string Airport::getLongitude(){
    return longitude;
}

string Airport::getCity() {
    return city;
}

string Airport::getCountry() {
    return country;
}






