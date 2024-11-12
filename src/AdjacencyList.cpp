#include <iostream>
#include "AdjacencyList.h"
#include <cmath>
#include <iomanip>

using namespace std;

int AdjacencyList::getOutDegree(const string& website) {
    int outDegree = 0;
    // iterate through each contributor website to see if 'website' is a contributor
    for(auto &it : AdjList) {
        for(int i = 0; i < it.second.size(); i++) {
           if(it.second[i].first == website) {
               outDegree += 1;
           }
        }
    }
    return outDegree;
}

void AdjacencyList::insertEdge(const string& from, const string& to, set<string>& websites) {
    // keep track of number of websites
    websites.insert(from);
    websites.insert(to);

    // get out-degrees
    int outDegree = getOutDegree(from) + 1;
    // update the out-degree values for current existing values
    for (auto& website : AdjList) {
        for(auto & pair : website.second) {
            if (pair.first == from) {
                pair.second = 1.0 / outDegree;
            }
        }
    }
    // add new value to contributing websites
    AdjList[to].emplace_back(from, 1.0 / outDegree);
}

void AdjacencyList::insertEmptyNode(const string& website) {
    if (AdjList.find(website) == AdjList.end()) {
        AdjList[website] = {}; // Initialize with an empty vector
    }
}

void AdjacencyList::calcPowerRank(vector<double>& initialRank, int powerIterations) {
    vector<double> newRank(initialRank.size(), 0.0);

    // create a map that associates each website with its index in initialRank
    map<string, int> websiteIndex;
    int index = 0;
    for (const auto& website : AdjList) {
        websiteIndex[website.first] = index++;
    }

    // power iteration loop to continue multiplying until finished
    for (int i = 1; i < powerIterations; i++) {
        // reset temp vector newRank for storing new values
        fill(newRank.begin(), newRank.end(), 0.0);
        int counter = 0; // helps keep track of what value should be replaced in initialValue vector
        for (auto &website : AdjList) {
            double resultRank = 0;
            for(auto &connections : website.second) {
                int toIndex = websiteIndex[connections.first];
                resultRank += (connections.second * initialRank[toIndex]);
            }
            newRank[counter] = resultRank;
            counter++;
        }
        initialRank = newRank;
    }
    // round each value to two decimal places
    for (double& rank : initialRank) {
        rank = round(rank * 100) / 100.0;
    }
}

void AdjacencyList::printPageRank(vector<double> initialRank) {
    int counter = 0;
    string result;
    // loop through each page in AdjList and print with precision
    for (auto& website : AdjList) {
        cout << website.first << " " << fixed << setprecision(2) << initialRank[counter++] << "\n";
    }
}

int main() {
    // initialize variables & graph
    int num_lines, power_iterations;
    string from, to;
    AdjacencyList adjList; // instance of class
    set<string> websites;

    // Take user input & create graph vertexes
    cin >> num_lines;
    cin >> power_iterations;
    for (int i = 0; i < num_lines; i++) {
        cin >> from;
        cin >> to;
        adjList.insertEdge(from, to, websites);
    }

    // ensure all websites in the set have an entry in adjacency list
    for (const auto& website : websites) {
        adjList.insertEmptyNode(website);
    }

    // create default ranks based off number of websites
    int numWebsites = websites.size();
    vector<double> initialRank(numWebsites, 1.0 / numWebsites);

    // call functions to calculate the power rank & print the results
    adjList.calcPowerRank(initialRank, power_iterations);
    adjList.printPageRank(initialRank);
    return 0;
}
