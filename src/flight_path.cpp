#include <string>
#include <iostream>;
#include <queue>;
#include <unordered_set>;
#include <set>;
#include "flight_path.h"
using namespace std;



FlightPath::FlightPath(std::string input_src) {
    this->input_src = input_src;
    this->reader = new Reader("../data/airports.csv", "../data/airlines.csv", "../data/routes.csv");
    this->airports = reader->loadAirports();
    this->airlines = reader->loadAirlines();
    this->routes = reader->loadRoutes();
}
string FlightPath::getSourceCity(){
    return source_city;
}
string FlightPath::getSourceCountry(){
    return source_country;
}
string FlightPath::getDestinationCity(){
    return destination_city;
}
string FlightPath::getDestinationCountry(){
    return destination_country;
}

void FlightPath::setSourceCity(string src_city){
    source_city = src_city;
}
void FlightPath::setSourceCountry(string src_country){
    source_country  = src_country;
}
void FlightPath::setDestinationCity(string dest_city){
    destination_city = dest_city;
}
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

Reader* FlightPath::getReader() {
    return reader;
}

string FlightPath::getInputSrc(){
    return input_src;
}
Node* FlightPath::getFlightPath(Airport* source, Airport* destination) {
    queue<Node *> routes_frontier;
    routes_frontier.push(new Node(source));
    unordered_set<string> explored;
    set<string> blacklist;
    while (!routes_frontier.empty()) {
        Node *current = routes_frontier.front();
        routes_frontier.pop();
        explored.insert(current->getAirport()->getIataCode());
        for (Route *route: getAvailableRoutes(current->getAirport())) {
//            cout << route->getSourceAirportCode()<<endl;
            if (blacklist.find(route->getDestinationAirportCode()) == blacklist.end()) {
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
    }
    cout << "no routes found" <<endl;
    return NULL;
}



Airline* FlightPath::getAirlineById(string airline_code, string airline_id) {
    for(Airline* airline: airlines){
        if(airline->getAirlineIataCode() == airline_code || airline->getAirlineId() == airline_id ){
            return airline;
        }
    }
    return NULL;
}

Airport* FlightPath::getAirportById(string airport_code, string airport_id) {
    for(Airport* airport: airports){
        if(airport->getIataCode() == airport_code || airport->getAirportId() == airport_id){
            return airport;
        }
    }
    return NULL;
}
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
void FlightPath::outputDataToFile(stack<Node*> path){
    int list_count = 0;
    int total_flights = path.size() - 1;
    int total_number_of_stops = 0;
    string output_src = source_city.append("-").append(destination_city).append(".txt");
    ofstream output_stream("../out/" + output_src);
    while(!path.empty()){
        Node* node = path.top();
        total_number_of_stops += node->getStops();
        path.pop();
        if(node->getParent() != NULL){
            if(node->getAirline() != NULL){
                output_stream << list_count << ". " <<  node->getAirline()->getAirlineId() << " from " <<  node->getParent()->getAirport()->getIataCode() << " to " <<  node->getAirport()->getIataCode()  << " " << node->getStops() <<  " stops " << "\n";
            }else{
                output_stream << list_count << ". " << "N/A"<< " from " << node->getParent()->getAirport()->getIataCode() << " to " << node->getAirport()->getIataCode() << " " << node->getStops() + " stops "  << "\n";
            }
        }

        list_count += 1;

    }
    output_stream << "\n" << "Total Flights: " << total_flights <<  "\n";
    output_stream << "Total additional stops: " <<total_number_of_stops << "\n";
    output_stream << "Total Distance: " << "Km" << "\n";
    output_stream << "Optimality criteria: Distance";
    output_stream.close();
}

int main(){
    FlightPath fp("../input.txt");
    map<string, Airport*> map = fp.getSourceAndDestinationAirport();
    Airport* source_airport = map["source"];
    Airport* destination_airport = map["destination"];
    Node* found_dest = fp.getFlightPath(source_airport, destination_airport);
    stack<Node*> sol_path = found_dest->getSolutionPath();
    fp.outputDataToFile(sol_path);

    return 0;
}






