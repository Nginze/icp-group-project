//
// Created by User on 11/28/2022.
//

#ifndef ICP_INDIVIDUAL_C___READER_H
#define ICP_INDIVIDUAL_C___READER_H
#include <iostream>;
#include <fstream>;
#include <string>;
#include <vector>;
#include "airport.h";
#include "route.h";
#include "airline.h";
using namespace std;

class Reader{
    private:
        ifstream airport_stream;
        ifstream airline_stream;
        ifstream route_stream;
    public:
        Reader(string airport_src, string airline_src, string route_src);
        ~Reader();
        vector<Airport*> loadAirports();
        vector<Airline*> loadAirlines();
        vector<Route*> loadRoutes();
        void readInputSrc(string, string& , string& , string& , string& );
};
#endif //ICP_INDIVIDUAL_C___READER_H
