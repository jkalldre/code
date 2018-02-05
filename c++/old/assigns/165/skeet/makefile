#####################################################################
# Program:
#     Project 10, Skeet
#     Brother Falin, CS165
# Author:
#     Jacob Alldredge
# Summary:
#     This is Skeet!! Use left and right arrows to manipulate
#     the rifle and press space to fire your gun! Kill those
#     pesky birds who proudly show themselves as circles. Don't
#     you go killing my sacred red star birds though or you will
#     pay for it! 
# Above and Beyond
#      1.I added an ammo clip to limit the trigger happy hunter
#      2.Hold up arrow and after a delay you will reload to continue
#        your hunt!
#      3.Every ten birds you get a free heat seeking missle!! Push
#        down to fire your OP weapon! (it won't chase sacred birds)
#
#####################################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: game.o uiInteract.o uiDraw.o point.o velocity.o rifle.o bullet.o flyingObject.o bird.o normalBird.o toughBird.o sacredBird.o missle.o
	g++ game.o uiInteract.o uiDraw.o point.o velocity.o rifle.o bullet.o flyingObject.o bird.o normalBird.o toughBird.o sacredBird.o missle.o $(LFLAGS)
	tar -j -cf skeet.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h bullet.h rifle.h
	g++ -c game.cpp


#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

rifle.o: rifle.cpp rifle.h uiDraw.h point.h
	g++ -c rifle.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h
	g++ -c bullet.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h
	g++ -c flyingObject.cpp

bird.o: bird.cpp bird.h flyingObject.h
	g++ -c bird.cpp

normalBird.o: normalBird.cpp normalBird.h bird.h
	g++ -c normalBird.cpp

toughBird.o: toughBird.cpp toughBird.h bird.h
	g++ -c toughBird.cpp

sacredBird.o: sacredBird.cpp sacredBird.h bird.h
	g++ -c sacredBird.cpp

missle.o: missle.cpp missle.h bullet.h
	g++ -c missle.cpp
###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o


