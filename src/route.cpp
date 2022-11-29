#include <string>;
#include "route.h";


/**
 * This function is a constructor for the Route class. It takes in 6 parameters and assigns them to the
 * corresponding class variables.
 * 
 * @param airline_id The ID of the airline.
 * @param airline_code The code of the airline
 * @param source_airport_code The IATA code of the source airport
 * @param destination_airport_code The IATA code of the destination airport.
 * @param destination_airport_id The unique OpenFlights identifier for this airport.
 * @param stops number of stops on route
 */
Route::Route(string airline_id,
             string airline_code,
             string source_airport_code,
             string destination_airport_code,
             string destination_airport_id,
             int stops){
    this->airline_id = airline_id;
    this->airline_code = airline_code;
    this->source_airport_code = source_airport_code;
    this->destination_airport_code = destination_airport_code;
    this->destination_airport_id = destination_airport_id;
    this->stops = stops;
}

/**
 * It returns the airline code.
 * 
 * @return The airline code.
 */
string Route::getAirlineCode(){
    return airline_code;
}

/**
 * It returns the airline_id.
 * 
 * @return The airline_id
 */
string Route::getAirlineId(){
    return airline_id;
}

/**
 * It returns the source airport code.
 * 
 * @return The source airport code.
 */
string Route::getSourceAirportCode(){
    return source_airport_code;
}

/**
 * It returns the destination airport code.
 * 
 * @return The destination airport code.
 */
string Route::getDestinationAirportCode(){
    return destination_airport_code;
}

/**
 * It returns the destination airport id.
 * 
 * @return The destination airport id.
 */
string Route::getDestinationAirportId(){
    return destination_airport_id;
}

/**
 * This function returns the number of stops in the route.
 * 
 * @return The number of stops in the route.
 */
int Route::getStops(){
    return stops;
}