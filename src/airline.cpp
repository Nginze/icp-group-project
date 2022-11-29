#include <string>;
#include "airline.h";
using namespace std;


/**
 * The function is a constructor for the Airline class
 * 
 * @param airline_id Unique OpenFlights identifier for this airline.
 * @param airline_name Name of the airline
 * @param airline_alias Alias of the airline. For example, All Nippon Airways is commonly known as
 * "ANA".
 * @param iata_code The IATA code of the airline.
 */
Airline::Airline(string airline_id, string airline_name, string airline_alias, string iata_code) {
    this->airline_id = airline_id;
    this->airline_name = airline_name;
    this->airline_alias = airline_alias;
    this->iata_code = iata_code;
}
/**
 * A constructor for the Airline class.
 * 
 * @param airline_id Unique OpenFlights identifier for this airline.
 * @param iata_code The IATA code of the airline.
 */
Airline::Airline(string airline_id, string iata_code){
    this->airline_id = airline_id;
    this->iata_code = iata_code;
}

/**
 * It returns the airline_id.
 * 
 * @return The airline_id is being returned.
 */
string Airline::getAirlineId(){
    return airline_id;
}

/**
 * It returns the airline name.
 * 
 * @return The airline name.
 */
string Airline::getAirlineName(){
    return airline_name;
}

/**
 * It returns the airline alias.
 * 
 * @return The airline alias.
 */
string Airline::getAirlineAlias(){
    return airline_alias;
}

/**
 * It returns the iata_code of the airline.
 * 
 * @return The iata_code of the airline.
 */
string Airline::getAirlineIataCode(){
    return iata_code;
}

/**
 * It returns the country of the airline.
 * 
 * @return The country of the airline.
 */
string Airline::getAirlineCountry(){
    return country;
}