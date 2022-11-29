//
// Created by User on 11/28/2022.
//
#include "node.h";
#include <stack>;
#include <iostream>;
using namespace std;

/**
 * Node::Node(Node *parent, Airport *airport, Airline *airline, int stops) {
 *     this->parent = parent;
 *     this->airport = airport;
 *     this->airline = airline;
 *     this->stops = stops;
 * }
 * 
 * @param parent The parent node of the current node.
 * @param airport The airport that the node represents
 * @param airline The airline that the flight is on
 * @param stops The number of stops it took to get to this node.
 */
Node::Node(Node *parent, Airport *airport, Airline *airline, int stops) {
    this->parent = parent;
    this->airport = airport;
    this->airline = airline;
    this->stops = stops;
}

Node::~Node() {
    cout << "Node destroyed";
}
/**
 * Node::Node(Airport *airport) {
 *     this->airport = airport;
 *     this->parent = NULL;
 *     this->airline = NULL;
 *     this->stops = 0;
 * }
 * 
 * @param airport The airport that this node represents
 */
Node::Node(Airport *airport) {
    this->airport = airport;
    this->parent = NULL;
    this->airline = NULL;
    this->stops = 0;
}

/**
 * It returns the airport object.
 * 
 * @return The airport object.
 */
Airport *Node::getAirport() {
    return airport;
}

/**
 * It returns the airline object.
 * 
 * @return The airline object.
 */
Airline *Node::getAirline() {
    return airline;
}


/**
 * It returns the parent of the node.
 * 
 * @return The parent node of the current node.
 */
Node *Node::getParent() {
    return parent;
}

/**
 * It returns a stack of nodes that represent the path from the current node to the root node.
 * 
 * @return A stack of pointers to nodes.
 */
stack<Node*> Node::getSolutionPath() {
    Node* node = this;
    stack<Node*> path;
    while(node != NULL){
        path.push(node);
        node = node->getParent();
    }
    return path;
}


/**
 * This function returns the number of stops in the node.
 * 
 * @return The number of stops.
 */
int Node::getStops() {
    return stops;
};

