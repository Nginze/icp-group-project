//
// Created by User on 11/28/2022.
//
#include "node.h";
#include <stack>;
#include <iostream>;
using namespace std;

Node::Node(Node *parent, Airport *airport, Airline *airline, int stops) {
    this->parent = parent;
    this->airport = airport;
    this->airline = airline;
    this->stops = stops;
}
Node::Node(Airport *airport) {
    this->airport = airport;
    this->parent = NULL;
    this->airline = NULL;
    this->stops = 0;
}

Airport *Node::getAirport() {
    return airport;
}

Airline *Node::getAirline() {
    return airline;
}


Node *Node::getParent() {
    return parent;
}

stack<Node*> Node::getSolutionPath() {
    Node* node = this;
    stack<Node*> path;
    while(node != NULL){
        path.push(node);
        node = node->getParent();
    }
    return path;
}


int Node::getStops() {
    return stops;
};

