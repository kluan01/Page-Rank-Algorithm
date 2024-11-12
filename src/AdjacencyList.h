#pragma once
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <set>
using namespace std;

class AdjacencyList {
private:
    // data structure to represent website adjacency list
    map<string, vector<pair<string, double>>> AdjList;
public:
    // adds a new edge between from and to vertexes
    void insertEdge(const string& from, const string& to, set<string>& websites);
    // adds an empty weighted edge if called
    void insertEmptyNode(const string& website);
    // calculate the rank of the page with power iteration
    void calcPowerRank(vector<double>& initialRank, int powerIterations);
    // getter function for out-degrees
    int getOutDegree(const string& website);
    // getter function to allow finding size of AdjList in loops
    const map<string, vector<pair<string, double>>>& getAdjList() const {
        return AdjList;
    }
    // prints the PageRank of all pages after p powerIterations in ascending alphabetical order of webpages and
    // rounding rank to two decimal places
    void printPageRank(vector<double> initialRank);
};

