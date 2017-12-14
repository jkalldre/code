# coding=UTF8
from copy   import deepcopy
from time   import sleep
from GUI    import *
import sys

def main():
    size = 500
    if len(sys.argv) == 2:
        slp = float(sys.argv[1])/10
    else:
        slp = .5
    print slp
    gui = GUI(20,size,size)
    while True:
        gui.top.update()
        gui.top.update_idletasks()
        if gui.running:
            gui.advance()
        slp = float(gui.inpbox.get())
        sleep(slp)

if __name__ == "__main__":
    main()
