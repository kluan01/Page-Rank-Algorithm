//#include <catch2/catch_test_macros.hpp>
//#include <iostream>
//#include <sstream>
//#include "AdjacencyList.h"
//using namespace std;
//
//TEST_CASE("Test One - Base Test", "[Base Input/Test]") {
//    // instantiate class & variables
//    AdjacencyList adjList;
//    set<string> websites;
//    int powerIterations = 2;
//
//    // insert edges
//    adjList.insertEdge("facebook.com", "google.com", websites);
//    adjList.insertEdge("facebook.com", "gmail.com", websites);
//    adjList.insertEdge("google.com", "ufl.edu", websites);
//    adjList.insertEdge("gmail.com", "ufl.edu", websites);
//    adjList.insertEdge("ufl.edu", "minecraft.com", websites);
//    adjList.insertEdge("minecraft.com", "facebook.com", websites);
//    for (auto& website : websites) {
//        adjList.insertEmptyNode(website);
//    }
//
//    // calculate rank
//    int numWebsites = websites.size();
//    vector<double> initialRank(numWebsites, 1.0 / numWebsites);
//    adjList.calcPowerRank(initialRank, powerIterations);
//
//    // initialize expected results
//    vector<string> webOrder = {"facebook.com", "gmail.com", "google.com", "minecraft.com", "ufl.edu"};
//    vector<double> expectedRanks = {0.2, 0.1, 0.1, 0.2, 0.4};
//
//    // compare actual results vs expected results
//    for (int i = 0; i < webOrder.size(); i++) {
//        string website = webOrder[i];
//        double expectedRank = expectedRanks[i];
//        REQUIRE(initialRank[i] == expectedRank);
//    }
//    cout << "Test One Successful!" << endl;
//}
//
//TEST_CASE("Test Two - Empty Out-degree Connections", "[Empty Out-degree]") {
//    // instantiate class & variables
//    AdjacencyList adjList;
//    set<string> websites;
//    int powerIterations = 2;
//
//    // insert edges
//    adjList.insertEdge("google.com", "facebook.com", websites);
//    adjList.insertEdge("gmail.com", "google.com", websites);
//    adjList.insertEdge("gmail.com", "facebook.com", websites);
//    for (auto& website : websites) {
//        adjList.insertEmptyNode(website);
//    }
//
//    // calculate rank
//    int numWebsites = websites.size();
//    vector<double> initialRank(numWebsites, 1.0 / numWebsites);
//    adjList.calcPowerRank(initialRank, powerIterations);
//
//    // initialize expected results
//    vector<string> webOrder = {"facebook.com", "gmail.com", "google.com"};
//    vector<double> expectedRanks = {0.5, 0.0, 0.17};
//
//    // compare actual results vs expected results
//    for (int i = 0; i < webOrder.size(); i++) {
//        string website = webOrder[i];
//        double expectedRank = expectedRanks[i];
//        REQUIRE(initialRank[i] == expectedRank);
//    }
//    cout << "Test Two Successful!" << endl;
//}
//
//TEST_CASE("Test Three - Single Connection", "[Small Input] [Empty Out-degree]" ) {
//    // instantiate class & variables
//    AdjacencyList adjList;
//    set<string> websites;
//    int powerIterations = 2;
//
//    // insert edges
//    adjList.insertEdge("facebook.com", "google.com", websites);
//    for (auto& website : websites) {
//        adjList.insertEmptyNode(website);
//    }
//
//    // calculate rank
//    int numWebsites = websites.size();
//    vector<double> initialRank(numWebsites, 1.0 / numWebsites);
//    adjList.calcPowerRank(initialRank, powerIterations);
//
//    // initialize expected results
//    vector<string> webOrder = {"facebook.com", "google.com"};
//    vector<double> expectedRanks = {0.0, 0.5};
//
//    // compare actual results vs expected results
//    for (int i = 0; i < webOrder.size(); i++) {
//        string website = webOrder[i];
//        double expectedRank = expectedRanks[i];
//        REQUIRE(initialRank[i] == expectedRank);
//    }
//    cout << "Test Three Successful!" << endl;
//}
//
//TEST_CASE("Test Four - Cyclical Connection", "[Small Input] [Cyclical Map]" ) {
//    // instantiate class & variables
//    AdjacencyList adjList;
//    set<string> websites;
//    int powerIterations = 2;
//
//    // insert edges
//    adjList.insertEdge("facebook.com", "google.com", websites);
//    adjList.insertEdge("google.com", "facebook.com", websites);
//    for (auto& website : websites) {
//        adjList.insertEmptyNode(website);
//    }
//
//    // calculate rank
//    int numWebsites = websites.size();
//    vector<double> initialRank(numWebsites, 1.0 / numWebsites);
//    adjList.calcPowerRank(initialRank, powerIterations);
//
//    // initialize expected results
//    vector<string> webOrder = {"facebook.com", "google.com"};
//    vector<double> expectedRanks = {0.5, 0.5};
//
//    // compare actual results vs expected results
//    for (int i = 0; i < webOrder.size(); i++) {
//        string website = webOrder[i];
//        double expectedRank = expectedRanks[i];
//        REQUIRE(initialRank[i] == expectedRank);
//    }
//    cout << "Test Four Successful!" << endl;
//}
//
//TEST_CASE("Test Five - Large Cyclical Graph", "[Max Input/Constraints] [Cyclic Graph]") {
//    // instantiate class & variables
//    AdjacencyList adjList;
//    set<string> websites;
//    int powerIterations = 1000;
//    int numWebs = 10000;
//
//    // create a cyclical graph where each website points to the next website
//    for (int i = 0; i <= numWebs; i++) {
//        string from = "website" + to_string(i) + ".com";
//        string to = "website" + to_string(i+ 1) + ".com";
//        adjList.insertEdge(from, to, websites);
//    }
//    for (const auto& website : websites) {
//        adjList.insertEmptyNode(website);
//    }
//
//    // calculate rank
//    int numWebsites = websites.size();
//    vector<double> initialRank(numWebsites, 1.0 / numWebsites);
//    adjList.calcPowerRank(initialRank, powerIterations);
//
//    // actual vs. expected results --> cyclical result should make all expectedRanks equal
//    double expectedRank = 1.0 / numWebsites;
//    for (double rank : initialRank) {
//        REQUIRE(abs(rank - expectedRank) < 0.1); // should equal out to near zero
//    }
//    cout << "Test Five Successful" << endl;
//}