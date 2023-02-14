/* Oct 8th
 * Name: Abdulrahman (Labib) Afia
 *
 * Organize data into a structure of queues of Passenger objects
 *
 */
#include "PassengerQueue.h"
//#include <iostream>
//#include <string>
#include <vector>




 //returns first element but doesn't remove it
Passenger PassengerQueue::front() {
    return data.front();
}


 //removes element at front of the queue
void PassengerQueue::dequeue() {
    if(data.size() > 0){
        data.erase(data.begin());
    }
}
// 
 //inserts one element at end
void PassengerQueue::enqueue(const Passenger &passenger) {
    data.push_back(passenger);
}
// 
// 
// //returns size of queue 
int PassengerQueue::size() {
    return data.size();
}
// 
// //prints 
void PassengerQueue::print (std::ostream &output) {
    for (unsigned long i = 0; i < data.size(); i++){
        data[i].print(output);
    }
}