//
// Created by User on 11/28/2022.
//

#ifndef ICP_INDIVIDUAL_C___ROUTE_H
#define ICP_INDIVIDUAL_C___ROUTE_H
#include <string>;
using namespace std;

class Route{
    private:
        string airline_code;
        string airline_id;
        string source_airport_code;
        string destination_airport_code;
        string destination_airport_id;
        int stops;
    public:
        Route(string, string, string, string, string, int);
        string getAirlineCode();
        string getAirlineId();
        string getSourceAirportCode();
        string getDestinationAirportCode();
        string getDestinationAirportId();
        int getStops();

};
#endif //ICP_INDIVIDUAL_C___ROUTE_H
