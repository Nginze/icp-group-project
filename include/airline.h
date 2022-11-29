//
// Created by User on 11/28/2022.
//

#ifndef ICP_INDIVIDUAL_C___AIRLINE_H
#define ICP_INDIVIDUAL_C___AIRLINE_H
#include<string>;
using namespace std;

class Airline{
private:
    string airline_id;
    string airline_name;
    string airline_alias;
    string iata_code;
    string country;
public:
    Airline(string airline_id, string airline_name, string airline_alias, string iata_code);
    Airline(string airline_id, string iata_code);

    string getAirlineId();
    string getAirlineName();
    string getAirlineAlias();
    string getAirlineIataCode();
    string getAirlineCountry();
};
#endif //ICP_INDIVIDUAL_C___AIRLINE_H
