###############################################################
# Program:
#     Week 01, Vector
#     Brother Helfrich, CS235
# Author:
#     Jacob Alldredge
# Summary:
#     This assignment is the recreation of the vector class
#     to help us understand how they work and i guess appreciate
#     them better :)
# Time:
#     about 6 hours..
###############################################################

##############################################################
# The main rule
##############################################################
a.out: vector.h week01.o
	g++ -o a.out week01.o 
	tar -cf week01.tar vector.h week01.cpp makefile

##############################################################
# The individual components
#      week01.o     : the driver program
##############################################################
week01.o: vector.h week01.cpp
	g++ -c week01.cpp
