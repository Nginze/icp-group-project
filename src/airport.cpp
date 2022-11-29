#include<string>;
#include "airport.h";
using namespace std;

/**
 * This function is a constructor for the Airport class.
 * 
 * @param airport_id Unique OpenFlights identifier for this airport.
 * @param airport_name Name of the airport
 * @param city The city the airport is located in.
 * @param country The country the airport is located in.
 * @param iata_code The IATA code for the airport.
 * @param icao_code The ICAO code of the airport.
 */
Airport::Airport(string airport_id, string airport_name, string city, string country, string iata_code, string icao_code){
    this->airport_id = airport_id;
    this->airport_name = airport_name;
    this->city = city;
    this->country = country;
    this->iata_code = iata_code;
    this->icao_code = icao_code;
}

/**
 * It returns the airport_id.
 * 
 * @return The airport_id is being returned.
 */
string Airport::getAirportId(){
    return airport_id;
}

/**
 * This function returns the airport name.
 * 
 * @return The airport name.
 */
string Airport::getAirportName(){
    return airport_name;
} 

/**
 * It returns the country of the airport.
 * 
 * @return The country of the airport.
 */
string Airport::getAirportCity(){
    return country;
}

/**
 * It returns the iata_code of the airport.
 * 
 * @return The iata_code of the airport.
 */
string Airport::getIataCode(){
    return iata_code;
}

/**
 * It returns the icao_code of the airport.
 * 
 * @return The icao_code is being returned.
 */
string Airport::getIcaoCode(){
    return icao_code;
}

/**
 * It returns the latitude of the airport.
 * 
 * @return The latitude of the airport.
 */
string Airport::getLatitude(){
    return latitude;
}

/**
 * It returns the longitude of the airport.
 * 
 * @return The longitude of the airport.
 */
string Airport::getLongitude(){
    return longitude;
}

/**
 * It returns the city of the airport.
 * 
 * @return The city of the airport.
 */
string Airport::getCity() {
    return city;
}

/**
 * It returns the country of the airport.
 * 
 * @return The country of the airport.
 */
string Airport::getCountry() {
    return country;
}






