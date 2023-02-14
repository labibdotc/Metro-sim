/* Oct 8th
 * Name: Abdulrahman (Labib) Afia
 *
 * An implementation of a train simulation. Stores and organizes
 * PassengerQueue objects (and Passenger objects.)
 *
 */

#include "MetroSim.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;





// Purpose: Initializes an empty train
//

MetroSim::MetroSim() {
    nextId = 1; //first id num wil be 1
    currStation = 0; // means train still didn't move from station 1 
}

// 
// Purpose: opens file, gets station names and construct queues both on train
// and stations for them, and then closes it
// Parameters: string stationsFile is the name of the file that has stations
//
void MetroSim::openStations(string stationsFile) {
    ifstream instream;
    
    open_or_die(instream, stationsFile);
    string stationName;
    int i = 0;
    while(getline(instream, stationName)){
        Station newStation;
        newStation.name = stationName;
        stations.push_back(newStation);
        QueueOnTrain newQueue;
        newQueue.to = i + 1;
        train.push_back(newQueue);
        i++;
    }
    instream.close();
}
//

// 
// Purpose: Opens an ifstream file or abort an error message
// Parameters: ifstream &stream is the stream of data in interest
//             , string filename is the name of the file to be opened
//
void MetroSim::open_or_die(ifstream &input, string file_name) {
    input.open(file_name);
    if (not input.is_open()){
        abort("Error : could not open file " + file_name);
    }
    
}

// 
// Purpose: prints error message and exits by exit(EXIT_FAILURE)
// Parameters: string error is the message to be printed
// 
//
void MetroSim::abort(string error) {
    cerr << error << '\n';
    exit(EXIT_FAILURE);
}

// 
// Purpose: prints one simulation state
// Parameters: none.
//
void MetroSim::printSim() {
    cout << "Passengers on the train: {";
    //loops num of PassengerQueues on station times
    for (int i = 0; i < numQueues(); i++){
        //prints PassengerQueue at a time
        train[i].queue.print(cout);
    }
    cout << "}\n";
    //prints the stations part
    printStations();
    cout << "Command? ";
}

// 
// Purpose: prints the stations part and keep track of where the train is
// 
//
void MetroSim::printStations() {
    //prints all stations up until the station where the train is at
    for (int i = 0; i < currStation; i++) {
        cout << "       [" << (i + 1) << "] " << stations[i].name 
                  << " {";
        stations[i].queue.print(cout);
        cout << "}\n";
    }
    cout << "TRAIN: ";
    //prints the station where the train is at up until the last one
    for (int i = currStation; i < numStations(); i++) {
        if (i == currStation){
            cout << "[" <<  (i + 1) << "] " << stations[i].name << " {";
        } else {
            cout << "       [" << (i + 1) << "] " << stations[i].name 
                      << " {";
        }
        stations[i].queue.print(cout);

        cout << "}\n";
    }
}

// 
// Purpose: runs backend of the p ARRIVAL DEPARTURE by adding passenger to
//          to station ARRIVAL
// Paramaters: int arrivalStation: station the passenger is put at
//             int departureStation: station the passenger leaves at
//
void MetroSim::enqueuePassenger (int arrivalStation, int departureStation) {
    Passenger newPassenger(nextId, arrivalStation, departureStation);
    stations[arrivalStation-1].queue.enqueue(newPassenger);
    nextId++;
}

// 
// Purpose: runs backend of 'mm' by moving passengers from stations train is
//          leaving to train and pushing passengers off at station DEPARTURE
//          
// Parameters: ofstream &stream a stream of data of output to the output log 
//             file

void MetroSim::move (ofstream &stream) {
    //number of passengers on the curr station queue
    int boardSize = stations[currStation].queue.size();

    QueueOnTrain newQueue;
    int board;//index where passeger go on vector train det by (PASSENGER.to-1)
    
    //one passenger boards train and leaves station at a time
    for (int i = 0; i < boardSize; i++) {
        board = stations[currStation].queue.front().to - 1;
        newQueue.queue.enqueue(stations[currStation].queue.front());
        train[board].queue.enqueue(stations[currStation].queue.front());
        stations[currStation].queue.dequeue();
    }
    
    currStation += 1;
    //makes train starts go back to station 1 when it hits the end
    if (currStation == numStations()) {
        currStation = 0;
    } 
    //deletes passengers from the train once they arrive and print (stream) 
    //that
    exitTrain(stream);
}

// 
// Purpose: deletes passengers from train as they arrive to their
//          destination and prints that (stream)
// Parameters: ofstream &stream flow of data to the output log file
// 
//
void MetroSim::exitTrain(ofstream &stream) {
    
    //amount of people exiting
    int leavingFolks = train[currStation].queue.size();
    
    //removes one passenger from train at a time,   and logs that
    for (int i = 0; i < leavingFolks; i++) {
        
        int id = train[currStation].queue.front().id;
        string station = stations[currStation].name;
        stream << "Passenger " << id << " left train at station " << station
               << "\n";
        train[currStation].queue.dequeue();
    }
}

// 
// Purpose: returns number of passengerQueue objects on train
//          helps with working with ints instead of unsigned longs
//
int MetroSim::numQueues() {
    return train.size();
}

// 
// Purpose: returns number of stations in the  simulation
//          helps with working with ints instead of unsigned longs
//
int MetroSim::numStations() {
    return stations.size();
}

