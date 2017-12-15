import Tkinter
from random import randint

class Unit:
    def __init__(self, top, handler, font):
        self.button = Tkinter.Button(top, command=handler,bg="light gray",\
                                     font=font, width=1, height=1)
        self.alive = randint(0,1)
        self.neighbors = 0
        self.invertLife()

    def invertLife(self):
        self.alive = not self.alive
        if self.alive:
            self.button.configure(bg = "yellow")
        else:
            self.button.configure(bg = "light gray")

    def isAlive(self):
        return self.alive

    def kill(self):
        if self.alive:
            self.alive = False
            self.button.configure(bg = "light gray")

    def lazarus(self):
        if not self.alive:
            self.alive = True
            self.button.configure(bg = "yellow")
