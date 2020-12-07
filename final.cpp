#include <iostream>
#include <fstream>
#include "Stack.h"
#include "Graph.h"
#include <regex>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){
    Graph mygwaf;
    Stack locationStack;
//Beginning of File Input
    ifstream inStream(argv[1]);
    string currentline;
    regex replaceCommas(",");
    regex getRidOfSpaces("\\s{2,}");
    getline(inStream, currentline);
    while(getline(inStream, currentline)){
        currentline = regex_replace(currentline, replaceCommas, " ");
        currentline = regex_replace(currentline, getRidOfSpaces, "");
        stringstream ss(currentline);
        vertex addToGraph;
        ss >> addToGraph.name;
        ss >> addToGraph.latitude;
        ss >> addToGraph.longitude;
        mygwaf.addVertex(addToGraph);
        while(ss.good()){
            string connectedNodeName;
            int weight;
            ss >> connectedNodeName;
            ss >> weight;
            mygwaf.addVertex(connectedNodeName, 0, 0);
            mygwaf.addEdge(addToGraph.name, connectedNodeName, weight);
        }
    }
    mygwaf.displayEdges();
//End of File Input
    string startingLocation;
    std::string mainMenu = 
        "======Main Menu=====\n"
        "1. Set New Starting Location\n"
        "2. Set Destination and Follow\n"
        "3. Config\n"
        "4. AddLocation\n"
        "5. Exit\n";

    std::string locationList= 
        "======Avalible Locations=====\n"
        "Acedemic: C4C, UMC,  Engineering Building, Duane Physics, Math Building,\n"
        "Fleming Building, Wolf Law Jila, Enviromental Design Building, Econ Building,\n"
        "Hale Science, Leeds Buisness\n\n"
        "Recreation: C4C, Fiske Planetarium, Rec Center, Farrand Feild, Kitt Feild, Old Main,\n"
        "Folsom Feild \n\n"
        "Residence Halls: Hallet, Engeneering Quad Andrews, Kitt Central, Farrand, Arnett, Baker,\n"
        "Libby, Sewall, Kitt West, Smith \n";

    int choice;
    bool exit = false;
    
    cout << mainMenu << endl;
    
    while(cin >> choice) {
        
        // flush the newlines and other characters
        cin.clear();
        cin.ignore();
        
        switch (choice) {
            case 1:
            {
                cin.clear();
                cin.ignore();
                string location;
                cout << "Choose a starting Location:\n" << locationList << endl;
                getline(cin, location);
                startingLocation = location;
                //TODO
                //dikjstra using location as root;
            }
            
            case 2:
            {
                cin.clear();
                cin.ignore();
                string location;
                cout << "Choose destination starting location is"<< startingLocation <<"\n" << locationList << endl;
                getline(cin, location);
                //TODO
                //find shortest distance to new location and build a stack of nodes to it
                    while(!locationStack.isEmpty()){
                        //TODO
                        //Step through locations giving directions
                    }
                }
                case 3:
                {
                    //TODO
                    //implement configurations (mph, descrpitions of buldings, ect.)
                }
                case 4:
                {
                    //TODO
                    //maybe add feature to add locations
                }
                case 5:
                {
                    cout << "Exiting..." << endl;
                    return 0;
                }
                default:
                {
                    cout << "Enter Valid Input" << endl;
                }
            
            if (exit) {
                break;
            }
            
            cout << mainMenu << endl;
        }
    }
    return 0;
}