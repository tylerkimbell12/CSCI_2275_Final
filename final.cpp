#include <iostream>
#include <fstream>
#include "Graph.h"
#include <regex>
#include <sstream>
#include <queue>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char *argv[]){
    Graph mygwaf;
    stack<vertex*> locationStack;
    vector<string> locVector;
    string startLoc = "";
    int distance = 0;
    int speed = 2;

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
        "1. Set New Current Location\n"
        "2. Set New Destination\n"
        "3. Remove Destination\n"
        "4. Follow Shortest Path To Next Destination\n"
        "5. Set Speed\n"
        "6. Exit\n";

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
                cout << "Set current location:\n\n" << locationList << endl;
                cin >> location;
                cin.clear();
                cin.ignore();
                startingLocation = location;

                if (mygwaf.vertexExists(location)){
                    startLoc = location;
                }
                else{
                    cout << "Current location was not added/changed, enter valid location next time" << endl;
                }
                break;
            }
            
            case 2:
            {
                cin.clear();
                cin.ignore();
                string location;
                cout << "Add destination to queue:\n\n" << locationList << endl;
                getline(cin, location);
                if (mygwaf.vertexExists(location)){
                    locVector.push_back(location);
                }
                else{
                    cout << "New destination was not added, enter valid location next time" << endl;
                }
                break;
            }
            case 3:
            {
                cout << "Removing destination:" << locVector.back() << " from end of queue..." << endl;
                locVector.pop_back();
                break;
            }
            case 4:
            {
                if(locVector.empty()){
                    cout << "Add a Destination" << endl;
                    break;
                }
                else if(startLoc == ""){
                    cout << "Choose current Location" << endl;
                    break;
                }
                else{
                    mygwaf.unassignDistance();
                    distance = 0.0;
                    string temp;
                    cout << "Following path from:" << startLoc << " to:" << locVector.back() << endl;
                    mygwaf.assignDistance(startLoc);
                    distance = mygwaf.distanceBetweenWords(startLoc,locVector.back());
                    cout << "Distance to Location:" << distance << endl;
                    cout << "ETA:" << distance/speed << "sec" << endl;
                    mygwaf.addLocationstoQueue(startLoc, locVector.back(), locationStack);
                    while(!locationStack.empty()){
                        if(locationStack.top()->name == locVector.back()){
                            cout << "Head" << "Twards your destination: " << locVector.back()<< endl;
                            startLoc = locVector.back();
                            locationStack.pop();
                            locVector.pop_back();
                            cout << "Type any Character to exit" <<endl;
                            cin >> temp;
                            break;
                        }
                        cout << "Head " << " Twards " << locationStack.top()->name << endl;
                        locationStack.pop();
                        cout << "Type any character to advance:" <<endl;
                        cin >> temp;

                    }
                }

                break;
            }
            case 5:
            {
                cout << "Enter new walking speed in meters/s:" << endl;
                cin >> speed;
                break;
            }
            case 6:
            {
                cout << "Exiting..." << endl;
                return 0;
            }
            default:
            {
                cout << "Enter Valid Input" << endl;
                break;
            }
            
            if (exit) {
                break;
            }
            
        }
        cout << mainMenu << endl;
    }
    return 0;
}