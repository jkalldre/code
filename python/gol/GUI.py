import Tkinter
from Unit   import *
from tkFont import Font

class GUI:
    def __init__(self, ngrid=10,h=250, w=250):
        self.top    = Tkinter.Tk()
        self.grid = ngrid
        self.top.title('Game of Life')
        self.top.resizable(width=False, height=False)
        self.buttons = []
        self.font = Font(family="Helvetica", size=8)
        for y in range(ngrid):
            self.buttons.append([])
            for x in range(ngrid):
                handler = lambda x=x, y=y: self.invertLife(x,y)
                button = Unit(self.top, handler, self.font)
                button.button.grid(row=y, column=x)
                self.buttons[y].append(button)
        self.canvas = Tkinter.Canvas(self.top, bg="gray", height=h, width=w)
        self.running = False
        handler = lambda: self.reset()
        button = Tkinter.Button(self.top, text='Reset', command=handler)
        button.grid(row=len(self.buttons)+2, column=0, columnspan=len(self.buttons), sticky="WE")
        handler = lambda: self.start_stop()
        button = Tkinter.Button(self.top, text='Start/Stop', command=handler)
        button.grid(row=len(self.buttons)+3, column=0, columnspan=len(self.buttons), sticky="WE")
        self.inpbox = Tkinter.Entry(self.top)
        self.inpbox.insert(0,.1)
        self.inpbox.grid(row=len(self.buttons)+1, column=0, columnspan=len(self.buttons), \
                         sticky="WE")

    def invertLife(self,x,y):
        """This will make a cell activate or die"""
        self.buttons[y][x].invertLife()


    def checkLeft (self,x,y):
        if x != 0:
            if self.buttons[y][x-1].isAlive():
                return 1
        else:
            if self.buttons[y][self.grid-1].isAlive():
                return 1
        return 0

    def checkRight(self,x,y):
        if x != (self.grid-1):
            if self.buttons[y][x+1].isAlive():
                return 1
        else:
            if self.buttons[y][0].isAlive():
                return 1
        return 0

    def checkUp   (self,x,y):
        if y != 0:
            if self.buttons[y-1][x].isAlive():
                return 1
        else:
            if self.buttons[self.grid-1][x].isAlive():
                return 1
        return 0

    def checkDown (self,x,y):
        if y != (self.grid-1):
            if self.buttons[y+1][x].isAlive():
                return 1
        else:
            if self.buttons[0][x].isAlive():
                return 1
        return 0

    def checkUpLeft   (self,x,y):
        if x != 0 and \
           y != 0:
            if self.buttons[y-1][x-1].isAlive():
                return 1
        elif x == 0 and \
             y != 0:
            if self.buttons[y-1][self.grid-1].isAlive():
                return 1
        elif x != 0 and \
             y == 0:
            if self.buttons[self.grid-1][x-1].isAlive():
                return 1
        else:
            if self.buttons[self.grid-1][self.grid-1].isAlive():
                return 1
        return 0

    def checkUpRight  (self,x,y):
        if x != (self.grid-1) and \
           y != 0:
            if self.buttons[y-1][x+1].isAlive():
                return 1
        elif x == (self.grid-1) and \
             y != 0:
            if self.buttons[y-1][0].isAlive():
                return 1
        elif x != (self.grid-1) and \
             y == 0:
            if self.buttons[self.grid-1][x+1].isAlive():
                return 1
        else:
            if self.buttons[self.grid-1][0].isAlive():
                return 1
        return 0

    def checkDownLeft (self,x,y):
        if x != 0 and \
           y != (self.grid-1):
            if self.buttons[y+1][x-1].isAlive():
                return 1
        elif x == 0 and \
             y != (self.grid-1):
            if self.buttons[y+1][self.grid-1].isAlive():
                return 1
        elif x != 0 and \
             y == (self.grid-1):
            if self.buttons[0][x-1].isAlive():
                return 1
        else:
            if self.buttons[0][self.grid-1].isAlive():
                return 1
        return 0

    def checkDownRight(self,x,y):
        if x != (self.grid-1) and \
           y != (self.grid-1):
            if self.buttons[y+1][x+1].isAlive():
                return 1
        elif x == (self.grid-1) and \
             y != (self.grid-1):
            if self.buttons[y+1][0].isAlive():
                return 1
        elif x != (self.grid-1) and \
             y == (self.grid-1):
            if self.buttons[0][x+1].isAlive():
                return 1
        else:
            if self.buttons[0][0].isAlive():
                return 1
        return 0

    def checkNeighbors(self,x,y):
        count = 0
        count += self.checkLeft     (x,y)
        count += self.checkRight    (x,y)
        count += self.checkUp       (x,y)
        count += self.checkDown     (x,y)
        count += self.checkUpLeft   (x,y)
        count += self.checkUpRight  (x,y)
        count += self.checkDownLeft (x,y)
        count += self.checkDownRight(x,y)
        self.buttons[y][x].neighbors = count

    def decideFate(self,x,y):
        if not self.buttons[y][x].isAlive():
            if self.buttons[y][x].neighbors == 3:
                self.buttons[y][x].lazarus()
        else:
            if self.buttons[y][x].neighbors < 2 or \
               self.buttons[y][x].neighbors > 3:
                self.buttons[y][x].kill()


    def advance(self):
        for y in range(self.grid):
            for x in range(self.grid):
                self.checkNeighbors(x,y)
        for y in range(self.grid):
            for x in range(self.grid):
                self.decideFate(x,y)

    def reset(self):
        for y in range(self.grid):
            for x in range(self.grid):
                self.buttons[y][x].kill()

    def start_stop(self):
        self.running = not self.running
