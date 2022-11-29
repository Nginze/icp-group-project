#include "flight_path.h"

int main(){
    FlightPath fp("../dubai-winnipeg.txt");
    map<string, Airport*> map = fp.getSourceAndDestinationAirport();
    Airport* source_airport = map["source"];
    Airport* destination_airport = map["destination"];
    Node* found_dest = fp.getFlightPath(source_airport, destination_airport);
    stack<Node*> sol_path = found_dest->getSolutionPath();
    fp.outputDataToFile(sol_path);
    return 0;
}