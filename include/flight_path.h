
#include <string>;
#include "node.h";
#include "route.h"
#include "reader.h"
#include <map>;
#include <vector>;
using namespace std;

class FlightPath{
    private:

        vector<Airport*> airports;
        vector<Airline*> airlines;
        vector<Route*> routes;

        string source_city;
        string source_country;
        string destination_city;
        string destination_country;

        string input_src;
        Reader* reader;
    public:
        FlightPath(string input_src);
        ~FlightPath();
        map<string, Airport*> getSourceAndDestinationAirport();
        Node* getFlightPath(Airport* source, Airport* destination);
        vector<Route*> getAvailableRoutes(Airport* airport);
        Airport* getAirportById(string airport_code, string airport_id);
        Airline* getAirlineById(string airline_code, string airline_id);
        Node getOptimalFlightPath();
        long getDistanceInKilometers();
        void outputDataToFile(stack<Node*> path);

        string getSourceCity();
        string getSourceCountry();
        string getDestinationCity();
        string getDestinationCountry();
        string getInputSrc();

        void setSourceCity(string src_city);
        void setSourceCountry(string src_country);
        void setDestinationCity(string dest_city);
        void setDestinationCountry(string dest_country);
        void setAirports(vector<Airport> airports);
        void setAirlines(vector<Airline> airlines);
        void setRoutes(vector<Route> routes);

        Reader* getReader();

};