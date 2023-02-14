/* Oct 8th
 * Name: Abdulrahman (Labib) Afia
 *
 * A program that simulates a train system of different stations. Takes in 
 * stations in an input file and posts a passengers log into an output file 
 * given by user. Uses MetroSim.h.
 *
 */
 
#include <cassert>

#include <iostream>
#include <istream>
#include <fstream>
#include <string>

#include "MetroSim.h"

using namespace std;

// Usage message for wrong run code
const string USAGE = 
"Usage: ./MetroSim stationsFile outputFile [commandsFile]"; 

const string ERROR =
"Error : could not open file ";

const string THANKS =
"Thanks for playing MetroSim. Have a nice day!\n";


void askCommand(MetroSim train, istream &input,
     ofstream &stream);
void reRun(MetroSim train, istream &input, ofstream &stream);

int main(int argc, char *argv[]) {
    MetroSim train;
    //not enough or more than needed
    if ((argc < 3) or (argc > 4)) {
        train.abort(USAGE);
    //Usage : ./ MetroSim stationsFile outputFile 
    } else if (argc == 3) {
        //sets up station array of structs of their names and passengerQueues
        train.openStations(argv[1]);
        //opens output file
        ofstream output;
        output.open(argv[2]);
        if (not output.is_open()) {
            string filename = argv[2];
            train.abort(ERROR + filename);
        }
        train.printSim();
        //prompts and takes reponse from user through cin
        askCommand(train, cin, output);
        //closes output file
        output.close();

    //Usage : ./ MetroSim stationsFile outputFile commandsFile
    } else if (argc == 4) {
        train.openStations(argv[1]);
        train.printSim();
        //opens output file
        ofstream output;
        output.open(argv[2]);
        if (not output.is_open()) {
            string filename = argv[2];
            train.abort(ERROR + filename);
        }
        
        ifstream input;
        //open or die function, only for ifstreams
        train.open_or_die(input, argv[3]);
        //prompt and takes response from input file
        askCommand(train, input, output);
        input.close();
        output.close();

    }
    return 0;
    
}






// 
// Purpose: takes in input commands and decide what action to take
//          and which function to call
//
// Parameters: MetroSim train: MetroSim instance used in main
//             istream &input: flow of data (input) either cin or testcommands
//             ofstream &stream: flow of data (output) to the output log file
// 
//
void askCommand(MetroSim train, istream &input, 
    ofstream &stream) {
    char cmd;
    input >> cmd;
    //Command case 1: p Arrival Departure
    if (cmd == 'p') {
        int from, to;
        input >> from >> to;
        train.enqueuePassenger(from, to);
        reRun(train, input, stream);
    //Command cases 2 and 3: mm and mf
    } else if (cmd == 'm') {
        char cmd2;
        input >> cmd2;
        if (cmd2 == 'm') {
            train.move(stream);// train moves
            reRun(train, input, stream);
        } else if (cmd2 == 'f') {
            cout << THANKS;
            return;
    //re-ask for command when input is not mf
        } else {
            //a function that calls back on this askCommand(..) function
            reRun(train, input, stream);
        }
    } else {
        reRun(train, input, stream);
    }
    
}

// 
// Purpose: Keeps sim going by reprinting new sim state and retaking data in
//
// Parameters: MetroSim train: MetroSim instance used in main
//             istream &input: flow of data (input) either cin or testcommands
//             ofstream &stream: flow of data (output) to the output log file
//
void reRun(MetroSim train, istream &input, ofstream &stream) {
    //prints train and stations layout
    train.printSim();
    //retake in commands
    askCommand(train, input, stream);
}

