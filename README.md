# Metro Simulation

This project simulates a running train to accommodate
passengers arriving/departing a metro. The objective is to learn how to design and
modularize code and work with documented libraries.

# Setup
fork the repository
```
git clone <https code of your repository>
cd Metro-sim
make MetroSim
./MetroSim stationsFile OuputLogFile [commands file]
```
# Simulation
<img width="285" alt="Screenshot 2023-02-14 at 12 47 16 PM" src="https://user-images.githubusercontent.com/98433990/218817020-5c697fd8-ce33-492f-a39f-e113c706f533.png">


# More details
/**********************************************************
* HW2: Metro Simulator
* Comp 15
* README
[Abdulrahman (Labib) Afia]                                         
[9/11/2021]          
*********************************************************/

Compile/run:
     - Compile using
            make MetroSim
     - run executable with
            ./MetroSim stationsFile passFile [commands]


Program Purpose:

This homework assignment simulates a running train to accommodate
passengers arriving/departing a metro.  Learn how to design and
modularize code and work with documented libraries.


Acknowledgements: 
This program was driven by a lot of efforts from my peers (Angel and Justin)
who I discussed concepts with and drawn diagram to better understand code.
Thanks also go to the TA's in the office hours who all were very helpful
and knowledgeable about pointers. It is the quick diagrams drawn instantly by
TAs when in confusion that makes everything really fit in place conceptually 
and gets the brain running. So big thank you to them.

Files: 

main.cpp:
     Main file should be short and handle simple driver
     functions such as reading in files.

MetroSim.cpp:
     Implementation of MetroSim class.  Main
     functionality of running the Metro Simulation, should be able to
     move trains and deal with passengers going on/off the train.

MetroSim.h:
     Interface of MetroSim class.

stations.txt:
     an example file containing a list of stations.

test_commands.txt:
     sample list of commands that you could give to the simulator

the_metroSim:
     reference implementation for students to see how 

README:
     "this file"


Note:  the program should handle all cases.

Data Structures:

Data structures used in this assignment were vectors as they are easy to 
deal with when it comes to needing to worry less about memory leak, pointers
assignment and reassignment, etc. making this project a lot easier and More
focused on mastering its actual purpose. 

Vectors of structs were used in different parts of metroSim to produce a 
list that always have a label on it either its name or for on trains
a label of where people are leaving.

Vectors of Passengers where used as private member variables in PassengerQueue.
vectors are like arrayLists pretty much except for the fact ond don't need to
worry about initializing it, resizing, etc. It does that for us in the 
background.

Accessing for vectors is pretty easy but deleting and inserting away from the
back can be very time inefficient

Testing:

Here describe the following: process of testing (unit tests)

Bugs encountered:

Passengers on my train in different order than passengers on the_MetroSim:
because I initialize my first passengerQueue based off of what the first
passenger.to is and so on. I used to have a different sequence of structuring
and organizing my data. So I had to initialize it in an order instead
that goes in line with the_MetroSim.

output file doesn't print: I used to open the file inside my mm function 
which is like opening and closing it and opening and closing it for every 
input, making it eventually empty.

Where my loops stop sometimes was off by +/- 1: I had to recheck my conditions
of for loops to make sure it stops at the index needed not 1 less or more
as that's not desirable for our program.

my loop where I remove people from train used to stop before removing all
to be removed. As it was (int i = 0; i < train[j].queue.size(); i++) such 
that j is the desired index of where passengers going off are. but inside 
the loop size was decreasing by 1 everytime I dequeue and i was increased by
i++. so it looped only half the desired amount.

Size_t and int warnings: as size() function for vector doesn't return an int
it took me a while to realize the idea that I might just use an int function
that returns that value now in int.

Testing: 


I started testing by using only p ARRIVAL DEPARTURE as that was what I got 
done initially. I then started using mm as my move function started working
but stopped at the limit where my mm caused the train to come back to zero
this was clearly because I didn't figure out yet my train going back to 
first station once it completes a cycle. 

For edge cases, it was really important to consider what the private member
variable currStation saves right before train restarting and once it goes back
it didn't go well initially and was off by +/- 1. Also seeing if passengers
arriving at station i and departing at i+1 and tracking them. a couple of 
cout statements for this assignment was really helpful.

cout statements were written before any loop to see what is the upper limit of
these loops are and double check. It helped catching a debug like the one when
size was shrinking. It is not usually of a desire to loop with an upperlimit
variables that changes value within the loop. 

istream and ifstream took a while of trial and error tests. istream can take in
both files and cin. That's why it was used in the askCommand function in the 
main. 

A general rule of thumb for going about all of that for me was by following 
a methodical testing approach that goes down up. The passengerQueue functions 
were initially tested to make sure it is working! 

Big part of what's after is going on in the main and depends on handing 
the many different inputs. For that, I relied mostly on couts of variables,
diff-ing, and repeat. It is this rigorous process that eventually gave me a 
solid working code. So yeah!


Part that you found most difficult: 
The challenging part of this assignment
is definitely how open ended it is initially. How to think of choosing 
structs and then create a vector of that struct is a very challenging 
thing to think about without a prompt to trigger it. Things after that went 
smooth!

