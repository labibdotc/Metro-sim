/* Oct 8th
 * Name: Abdulrahman (Labib) Afia
 *
 * Unit test functions for MetroSim.h PassengerQueue.h Passenger.h
 *
 */
 
#include <cassert>
#include "PassengerQueue.h"
#include "Passenger.h"
#include "MetroSim.h"


//Unit tests for Passenger 


void print_P(){
    Passenger P1(1, 1, 2);
    P1.print(std::cout);
}

//Unit tests for PassengerQueue

//tests front(), enqueue(), size()
void front_PQ(){
    Passenger P1(1, 2, 3);
    PassengerQueue Q1;
    Q1.enqueue(P1);
    //std:: cerr << "size is " << Q1.size();
    assert(Q1.front().id == P1.id);
    assert(Q1.front().from == P1.from);
    assert(Q1.front().to == P1.to);
    
    Q1.enqueue(P1);
    assert(Q1.size() == 2);

}

//tests print(ostream &output)
void print_PQ(){
    Passenger P1(1, 1, 2);
    PassengerQueue Q1;
    Q1.enqueue(P1);
    Q1.print(std::cout);
}

void enqueue_PQ(){
    Passenger P1(1, 2, 3);
    PassengerQueue Q1;
    Q1.enqueue(P1);
    assert(Q1.size() == 1);
    assert(Q1.front().id == P1.id);
    assert(Q1.front().from == P1.from);
    assert(Q1.front().to == P1.to);
    Passenger P2 (2, 2, 4);
    Q1.enqueue(P2);
    assert(Q1.front().id == P1.id);
    assert(Q1.front().from == P1.from);
    assert(Q1.front().to == P1.to);
    assert(Q1.size() == 2);
}

void print2_PQ(){
    Passenger P1(1, 2, 3);
    PassengerQueue Q1;
    Q1.enqueue(P1);
    Passenger P2 (2, 2, 4);
    Q1.enqueue(P2);
    Q1.enqueue(P2);
    Q1.enqueue(P1);
    Q1.print(std::cout);
}

void dequeue_PQ(){
    PassengerQueue Q1;
    Passenger P2 (2, 2, 4);
    Q1.enqueue(P2);
    assert(Q1.front().id == P2.id);
    assert(Q1.front().from == P2.from);
    assert(Q1.front().to == P2.to);
    Q1.print(std::cout);
    
    Q1.dequeue();
    assert(Q1.size() == 0);
    Q1.print(std::cout);
    
}




