//
// Created by User on 11/28/2022.
//

#ifndef ICP_INDIVIDUAL_C___NODE_H
#define ICP_INDIVIDUAL_C___NODE_H
#include <string>;
#include "airline.h";
#include "airport.h";
#include <stack>;
using namespace std;

class Node{
    private:
        Node* parent;
        Airport* airport;
        Airline* airline;
        int stops;
        double distance;
    public:
        Node(Node* parent, Airport* airport, Airline* airline, int stops);
        Node(Airport* airport);
        ~Node();
        Node* getParent();
        Airport* getAirport();
        Airline* getAirline();
        double getDistance();
        stack<Node*> getSolutionPath();
        int getStops();
};
#endif //ICP_INDIVIDUAL_C___NODE_H
