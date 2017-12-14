###############################################################
# Program:
#     Checkpoint 12a, Nonmember Operators
#     Brother Falin, CS165
# Author:
#     Jacob Alldredge
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################


a.out : money.o check08a.o
	g++ money.o check08a.o

money.o : money.h money.cpp
	g++ -c money.cpp

check08a.o : money.h check08a.cpp
	g++ -c check08a.cpp

clean :
	rm *.o *.out
