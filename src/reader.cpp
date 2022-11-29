#include "reader.h";
#include <string>;
#include <iostream>;
#include <fstream>;
#include <sstream>;
#include <vector>;
using namespace std;

/**
 * It opens the files and reads them into the program.
 * 
 * @param airport_src "airports.dat"
 * @param airline_src "airlines.dat"
 * @param route_src "routes.dat"
 */
Reader::Reader(std::string airport_src, std::string airline_src, std::string route_src) {
    airport_stream.open(airport_src);
    airline_stream.open(airline_src);
    route_stream.open(route_src);
}

/**
 * The destructor is called when the object is destroyed
 */
Reader::~Reader(){
    cout<<"Reader object destroyed";
}

/**
 * It reads in a csv file, creates a vector of strings, and then creates a vector of Airport objects.
 * 
 * @return A vector of Airport objects.
 */
vector<Airport*> Reader::loadAirports() {
    string record;
    vector<string> airport_records;
    vector<Airport*> airport_objects;

    while(airport_stream.good()){
        getline(airport_stream, record);
        airport_records.push_back(record);
    }
    for(int i = 1; i < airport_records.size(); i++){
        stringstream  str_stream(airport_records[i]);
        string airport_id, airport_name, city, country, iata_code, icao_code;
        double latitude;
        double longitude;
        while(str_stream.good()){
            getline(str_stream, airport_id, ',');
            getline(str_stream, airport_name, ',');
            getline(str_stream, city, ',');
            getline(str_stream, country, ',');
            getline(str_stream, iata_code, ',');
            getline(str_stream, icao_code, ',');
            break;
        }
        Airport* new_airport = new Airport(airport_id, airport_name, city, country, iata_code, icao_code);
        airport_objects.push_back(new_airport);
    }
    airport_stream.close();

    return airport_objects;
}

/**
 * It reads a csv file, creates a vector of strings, and then creates a vector of objects from the
 * vector of strings
 * 
 * @return A vector of pointers to Airline objects.
 */
vector<Airline*> Reader::loadAirlines() {
    string record;
    vector<string> airline_records;
    vector<Airline*> airline_objects;

    while(airline_stream.good()){
        getline(airline_stream, record);
        airline_records.push_back(record);
    }

    for(int i = 1; i < airline_records.size(); i++){
        stringstream str_stream(airline_records[i]);
        string airline_id, airline_name, airline_alias, iata_code;
        while(str_stream.good()){
            getline(str_stream, airline_id, ',');
            getline(str_stream, airline_name, ',');
            getline(str_stream, airline_alias, ',');
            getline(str_stream, iata_code, ',');
            break;
        }
        Airline* new_airline = new Airline(airline_id, airline_name, airline_alias, iata_code);
        airline_objects.push_back(new_airline);
    }
    airline_stream.close();
    return airline_objects;
}

/**
 * It reads a csv file and creates a vector of objects from the data in the file.
 * 
 * @return A vector of Route objects.
 */
vector<Route*> Reader::loadRoutes() {
    string record;
    vector<string> route_records;
    vector<Route*> route_objects;

    while(route_stream.good()){
        getline(route_stream, record);
        route_records.push_back(record);
    }

    for(int i = 1; i < route_records.size(); i++){
        stringstream str_stream(route_records[i]);
        string  airline_id, airline_code, source_airport_code, source_airport_id,  destination_airport_code, destination_airport_id, codeshare, stops;
        while(str_stream.good()){
            getline(str_stream, airline_code, ',');
            getline(str_stream, airline_id, ',');
            getline(str_stream, source_airport_code, ',');
            getline(str_stream, source_airport_id, ',');
            getline(str_stream, destination_airport_code, ',');
            getline(str_stream, destination_airport_id, ',');
            getline(str_stream, codeshare, ',');
            getline(str_stream, stops, ',');
            break;
        }
        try{
            Route* new_route = new Route(airline_id, airline_code, source_airport_code, destination_airport_code, destination_airport_id, stoi(stops));
            route_objects.push_back(new_route);
        }catch(exception& e){
            cout << stops <<endl;
        }


    }

    route_stream.close();
    return route_objects;

}


/**
 * It reads the input file and stores the source and destination city and country in the respective
 * variables
 * 
 * @param input_src the path to the input file
 * @param source_city The city of origin
 * @param source_country "United States"
 * @param dest_city destination city
 * @param dest_country destination country
 */
void Reader::readInputSrc(string input_src,
                  string& source_city,
                  string& source_country,
                  string& dest_city,
                  string& dest_country){
    string record;
    vector<string> attributes;
    vector<string> input_data;
    ifstream input_stream(input_src);
    while(input_stream.good()){
        getline(input_stream, record);
        input_data.push_back(record);
    }
    for(string location: input_data){
        stringstream  str_stream(location);
        string attribute;
        while(str_stream.good()){
            getline(str_stream, attribute, ',');
            attributes.push_back(attribute);
        }
    }
    source_city = attributes[0];
    source_country = attributes[1];
    dest_city = attributes[2];
    dest_country = attributes[3];

    input_stream.close();
}



