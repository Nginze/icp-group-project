#include <string>
#include <iostream>;
#include <queue>;
#include <unordered_set>;
#include <set>;
#include "flight_path.h"
using namespace std;



/**
 * It takes a string as input, creates a new Reader object, and then uses that object to load airports,
 * airlines, and routes
 * 
 * @param input_src The source airport
 */
FlightPath::FlightPath(std::string input_src) {
    this->input_src = input_src;
    this->reader = new Reader("../data/airports.csv", "../data/airlines.csv", "../data/routes.csv");
    this->airports = reader->loadAirports();
    this->airlines = reader->loadAirlines();
    this->routes = reader->loadRoutes();
}

/**
 * It returns the source city.
 * 
 * @return The source city.
 */
string FlightPath::getSourceCity(){
    return source_city;
}

/**
 * This function returns the source country of the flight.
 * 
 * @return The source country of the flight.
 */
string FlightPath::getSourceCountry(){
    return source_country;
}

/**
 * This function returns the destination city of the flight.
 * 
 * @return The destination city.
 */
string FlightPath::getDestinationCity(){
    return destination_city;
}

/**
 * This function returns the destination country of the flight
 * 
 * @return The destination country.
 */
string FlightPath::getDestinationCountry(){
    return destination_country;
}

/**
 * This function sets the source city of the flight path.
 * 
 * @param src_city The name of the city where the flight originates.
 */
void FlightPath::setSourceCity(string src_city){
    source_city = src_city;
}

/**
 * This function sets the source country of the flight path.
 * 
 * @param src_country The country where the flight originates
 */
void FlightPath::setSourceCountry(string src_country){
    source_country  = src_country;
}

/**
 * This function sets the destination city of the flight path.
 * 
 * @param dest_city The destination city of the flight
 */
void FlightPath::setDestinationCity(string dest_city){
    destination_city = dest_city;
}

/**
 * This function sets the destination country of the flight path
 * 
 * @param dest_country The country of the destination airport
 */
void FlightPath::setDestinationCountry(string dest_country){
    destination_country = dest_country;
}

//void FlightPath::setAirports(vector<Airport> airports){
//    this->airports = airports;
//}
//void FlightPath::setAirlines(vector<Airline> airlines){
//    this->airlines = airlines;
//}
//
//void FlightPath::setRoutes(vector<Route> routes){
//    this->routes = routes;
//}

/**
 * It takes a source and destination city and country and returns a map of the source and destination
 * airport
 * 
 * @return A map of string and Airport*
 */
map<string, Airport*> FlightPath::getSourceAndDestinationAirport(){
    map<string, Airport*> airport_map;
    Reader* reader = getReader();
    string current_input_src = getInputSrc();
    string sci, sco, dci, dco;
    reader->readInputSrc(current_input_src, sci, sco, dci, dco);
    setSourceCity(sci);
    setSourceCountry(sco);
    setDestinationCity(dci);
    setDestinationCountry(dco);

    for(Airport* airport: airports){
        if (airport_map.size() > 1){
            return airport_map;
        }
        if (source_city == airport->getCity() && source_country == airport->getCountry()){
            airport_map["source"] = airport;
        }

        else if (destination_city == airport->getCity() && destination_country == airport->getCountry()){
            airport_map["destination"] = airport;
        }

    }
    return airport_map;
};

/**
 * It returns the reader object.
 * 
 * @return The reader object.
 */
Reader* FlightPath::getReader() {
    return reader;
}

/**
 * This function returns the input_src variable.
 * 
 * @return The input_src variable is being returned.
 */
string FlightPath::getInputSrc(){
    return input_src;
}

/**
 * It takes an airport and a destination airport and returns a node that contains the flight path from
 * the airport to the destination airport
 * 
 * @param source The source airport
 * @param destination The destination airport
 * @return A pointer to a node.
 */
Node* FlightPath::getFlightPath(Airport* source, Airport* destination) {
    queue<Node *> routes_frontier;
    routes_frontier.push(new Node(source));
    unordered_set<string> explored;
    while (!routes_frontier.empty()) {
        Node *current = routes_frontier.front();
        routes_frontier.pop();
        explored.insert(current->getAirport()->getIataCode());
        for (Route *route: getAvailableRoutes(current->getAirport())) {
                Airport *flight_destination = getAirportById(route->getDestinationAirportCode(),
                                                             route->getDestinationAirportId());
                Airline *flight = getAirlineById(route->getAirlineCode(), route->getAirlineId());
                Node *child = new Node(current, flight_destination, flight, route->getStops());
                if (route->getDestinationAirportCode() == destination->getIataCode()) {
                    cout <<"Found route: "<< child->getAirport()->getIataCode()<<endl;
                    return child;
                }
                routes_frontier.push(child);
//                if (explored.find(child->getAirport()->getIataCode()) == explored.end()) {
//
//                }
        }
    }
    cout << "no routes found" <<endl;
    return NULL;
}



/**
 * It returns a pointer to an airline object if the airline_code or airline_id matches the airline_code
 * or airline_id of an airline object in the airlines vector
 * 
 * @param airline_code "DL"
 * @param airline_id "airline_id": "airline_id": "airline_id": "airline_id": "airline_id":
 * "airline_id": "airline_id": "airline_id": "airline_id": "airline_id":
 * @return A pointer to an airline object.
 */
Airline* FlightPath::getAirlineById(string airline_code, string airline_id) {
    for(Airline* airline: airlines){
        if(airline->getAirlineIataCode() == airline_code || airline->getAirlineId() == airline_id ){
            return airline;
        }
    }
    return NULL;
}

/**
 * It returns the first airport in the list of airports that matches the given airport code or airport
 * id
 * 
 * @param airport_code The IATA code of the airport.
 * @param airport_id "1"
 * @return A pointer to an Airport object.
 */
Airport* FlightPath::getAirportById(string airport_code, string airport_id) {
    for(Airport* airport: airports){
        if(airport->getIataCode() == airport_code || airport->getAirportId() == airport_id){
            return airport;
        }
    }
    return NULL;
}

/**
 * This function returns a vector of routes that are available from the airport passed in as a
 * parameter
 * 
 * @param airport The airport that the user is currently at.
 * @return A vector of routes
 */
vector<Route*> FlightPath::getAvailableRoutes(Airport* airport) {
    vector<Route*> availableRoutes;
    for(Route* route: routes){
        if(airport->getIataCode() == route->getSourceAirportCode()){
            availableRoutes.push_back(route);
        }
    }
    return availableRoutes;
}
//Node getOptimalFlightPath();
//long getDistanceInKilometers();
/**
 * This function takes a stack of nodes and outputs the data to a file
 * 
 * @param path stack of nodes
 */
void FlightPath::outputDataToFile(stack<Node*> path){
    int list_count = 0;
    int total_flights = path.size() - 1;
    int total_number_of_stops = 0;
    string output_src = source_city.append("-").append(destination_city).append( "-output").append(".txt");
    ofstream output_stream("../out/" + output_src);
    while(!path.empty()){
        Node* node = path.top();
        total_number_of_stops += node->getStops();
        path.pop();
        if(node->getParent() != NULL){
            if(node->getAirline() != NULL){
                output_stream << list_count << ". " <<  node->getAirline()->getAirlineIataCode() << " from " <<  node->getParent()->getAirport()->getIataCode() << " to " <<  node->getAirport()->getIataCode()  << " " << node->getStops() <<  " stops " << "\n";
            }else{
                output_stream << list_count << ". " << "N/A"<< " from " << node->getParent()->getAirport()->getIataCode() << " to " << node->getAirport()->getIataCode() << " " << node->getStops() + " stops "  << "\n";
            }
        }

        list_count += 1;

    }
    output_stream << "\n" << "Total Flights: " << total_flights <<  "\n";
    output_stream << "Total additional stops: " << total_number_of_stops << "\n";
    output_stream << "Total Distance: " << "Km" << "\n";
    output_stream << "Optimality criteria: Distance";
    output_stream.close();
}








