#include "flight_path.h"

/**
 * The main function creates a FlightPath object, gets the source and destination airports, and then
 * finds the flight path between the two airports
 * 
 * @return The program is returning the shortest path from the source airport to the destination
 * airport.
 */
int main(){
    FlightPath fp("../dubai-winnipeg.txt");
    map<string, Airport*> map = fp.getSourceAndDestinationAirport();
    Airport* source_airport = map["source"];
    Airport* destination_airport = map["destination"];
    Node* found_destination = fp.getFlightPath(source_airport, destination_airport);
    stack<Node*> solution_path = found_destination->getSolutionPath();
    fp.outputDataToFile(solution_path);
    return 0;
}