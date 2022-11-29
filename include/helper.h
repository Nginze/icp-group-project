//
// Created by User on 11/29/2022.
//

#ifndef ICP_INDIVIDUAL_C___HELPER_H
#define ICP_INDIVIDUAL_C___HELPER_H
#include <vector>
#include <unordered_map>
#include <iostream>
#include <deque>
#include "Node.h"


bool frontierContains(deque<Node*> front, Node* curr_node){
    for(Node* node: front){
        if(node == curr_node){
            return true;
        }
    }
    return false;
}


bool exploredContains(set<string> explored, string current_iata_code){
    for(string code : explored){
        if(code == current_iata_code){
            return true;
        }
    }
    return false;
}
#endif //ICP_INDIVIDUAL_C___HELPER_H
