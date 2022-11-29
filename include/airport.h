//
// Created by User on 11/28/2022.
//

#ifndef ICP_INDIVIDUAL_C___AIRPORT_H
#define ICP_INDIVIDUAL_C___AIRPORT_H
#include <string>;
using namespace std;

class Airport{
    private:
        string airport_id;
        string airport_name;
        string city;
        string country;
        string iata_code;
        string icao_code;
        string latitude;
        string longitude;
    public:
        Airport(string, string, string, string, string, string);
        string getAirportId();
        string getAirportName();
        string getAirportCity();
        string getCity();
        string getCountry();
        string getIataCode();
        string getIcaoCode();
        string getLatitude();
        string getLongitude();

};
#endif //ICP_INDIVIDUAL_C___AIRPORT_H
