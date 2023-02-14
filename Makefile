#########################################################
#             HOMEWORK 2: MetroSim Makefile             #
#########################################################

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 


# Metrosim rule - you need to fill in the linking command,
# add any new dependencies, and add target rules for 
# Passenger.o, MetroSim.o, main.o, and any new dependencies.
# Please use the rules provided below for PassengerQueue.o as an example for
# what to do.
# If you add other classes, you'll have to add their .o files as dependencies here.
# Don't forget:  the clang++ command must be indented with a TAB character
# and be all on one line.
MetroSim: main.o MetroSim.o PassengerQueue.o Passenger.o
	$(CXX) $(LDFLAGS) -o MetroSim $^
	


# You can base them on the PassengerQueue.o rule. 

main.o: main.cpp MetroSim.h PassengerQueue.h Passenger.h
	$(CXX) $(CXXFLAGS) -c $<

MetroSim.o: MetroSim.cpp MetroSim.h PassengerQueue.h 
	$(CXX) $(CXXFLAGS) -c $<
# This rule builds PassengerQueue.o
PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h 
	$(CXX) $(CXXFLAGS) -c $<
	
Passenger.o: Passenger.cpp Passenger.h
	$(CXX) $(CXXFLAGS) -c $<
	
unit_test_driver.o: unit_tests.h PassengerQueue.h Passenger.h MetroSim.h
	$(CXX) $(CXXFLAGS) -c unit_test_driver.cpp


# The below rule will be used by unit_test.
# Please add any other .o files that are needed by PassengerQueue,
# and any other .o files you wish to test. 
unit_test: unit_test_driver.o PassengerQueue.o Passenger.o MetroSim.o
	$(CXX) $(CXXFLAGS) $^


# This rule provides your submission 
# NOTE: Don't forget to add any additional files you want to submit to this
#		rule! If you do not add them, they will not be submitted.
provide:
	provide comp15 hw2_MetroSim PassengerQueue.h \
				    PassengerQueue.cpp \
				    Passenger.h Passenger.cpp  \
				    unit_tests.h Makefile README main.cpp \
					MetroSim.h MetroSim.cpp test_commands.txt \
					stations.txt

# remove executables, object code, and temporary files from the current folder 
# -- the executable created by unit_test is called a.out
clean: 
	rm *.o *~ *a.out vgcore* core*
	
