/* Oct 8th
 * Name: Abdulrahman (Labib) Afia
 *
 * A simulation of a train system. Uses PassengerQueue objects
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "PassengerQueue.h"

using namespace std;

class MetroSim
{
public:
    
    //constructor for int members
    MetroSim();
    //Oct 10th work
    void open_or_die(ifstream &stream, string file_name);
    void openStations(string stationsFile);
    void abort(string error);
    
    void printSim();
    //what happens when p ARRIVAL DEPARTURE command runs
    void enqueuePassenger (int arrivalStation, int departureStation);
    
    //what happens when mm command runs
    void move(ofstream &stream);

private:
    struct QueueOnTrain {
        int to;
        PassengerQueue queue;
    };
    vector <QueueOnTrain> train;
    
    int nextId; // stores next id number of passengers
    int currStation; // stores 0 at station 1, 1 at station 2 and so on
    
    struct Station {
        string name;
        PassengerQueue queue;
    };
    
    vector <Station> stations;
    
    //helper function
    
    void printStations();
    void exitTrain(ofstream &stream);
    
    //sizes to help with changing unsigned long size() vector function to int
    int numStations();
    int numQueues();
};

#endif
