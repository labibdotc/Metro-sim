/* Oct 8th
 * Name: Abdulrahman (Labib) Afia
 *
 * Implementation of a queue data structure that uses vectors of Passenger
 * objects.
 */

#ifndef _PASSENGER_QUEUE_H_
#define _PASSENGER_QUEUE_H_

#include "Passenger.h"
#include <vector>
#include <fstream>


class PassengerQueue {
    
public:
    

    Passenger front(); //returns first element but doesn't remove it
    void dequeue(); //removes element at front of the queue
    void enqueue(const Passenger &passenger); //inserts one element at end
    int size(); //returns size of queue 
    void print (std::ostream &output);
    
    
    
private:
    //Helper functions/variables
    std::vector <Passenger> data;
};

#endif