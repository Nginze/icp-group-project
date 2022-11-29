#include <string>;
#include "route.h";


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

string Route::getAirlineCode(){
    return airline_code;
}

string Route::getAirlineId(){
    return airline_id;
}

string Route::getSourceAirportCode(){
    return source_airport_code;
}

string Route::getDestinationAirportCode(){
    return destination_airport_code;
}

string Route::getDestinationAirportId(){
    return destination_airport_id;
}

int Route::getStops(){
    return stops;
}