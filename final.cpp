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
//Beginning of File Input | Vertex file must be first argument, edge file must be second.
    ifstream inStreamVerticies(argv[1]);
    ifstream inStreamEdges(argv[2]);
    string currentline;
    regex replaceCommas(",");
    regex getRidOfSpaces("\\s{2,}");
    //Vertex Input
    while(getline(inStreamVerticies, currentline)){
        currentline = regex_replace(currentline, replaceCommas, " ");
        stringstream ss(currentline);
        vertex toAdd;
        ss >> toAdd.name;
        ss >> toAdd.latitude;
        ss >> toAdd.longitude;
        mygwaf.addVertexObject(toAdd);
    }
    //Edges Input
    while(getline(inStreamEdges, currentline)){
        currentline = regex_replace(currentline, replaceCommas, " ");
        currentline = regex_replace(currentline, getRidOfSpaces, "");
        stringstream ss2(currentline);
        string baseNode;
        ss2 >> baseNode;
        while(ss2.good()){
            string connectNode;
            int weight;
            ss2 >> connectNode;
            ss2 >> weight;
            mygwaf.addEdge(baseNode, connectNode, weight);
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
        "Acedemic: Engineering_Center, Duane_Physics, Math, Fleming, Wolf_Law,\n"
        "Environmental_Design, Econ, Hale_Science, Leeds_Business\n"
        "Recreation: C4C, UMC, Fiske_Planetarium, Rec_Center, Farrand_Field, Kitt_Field, Old_Main, Folsom_Field \n"
        "Residence Halls: Hallett, Engineering_Quad, Kitt_Central, Farrand, Arnett, Baker, Andrews, Sewall\n";

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