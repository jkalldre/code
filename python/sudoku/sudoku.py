##########################
# imports                #
import help as h
from objects import Board
##########################

msg = ""

# instructions :: The program's user input handler #
def instructions(board):
    ins = raw_input("\nGive command: \n" \
                    "I: To insert an item.\n" \
                    "D: To check your solution\n" \
                  #  "C: To clear the screen\n" \
                    "H: To see possible values for a square\n" \
                    "Q: To quit program\n\n>").lower()
    while True:
        if ins == 'q':
            return False
        if ins == 'd':
            cond = False
            cond == gameover(board)
            if cond == -3:
                return True
            else:
                return False
        if ins == "i":
            insert(board)
            return True
        if ins == 'h':
            hint(board)
            return True

        ins = raw_input(">")

def gameover(board):
    global msg
    cond = board.chkGame()
    if cond:
        msg = "You Win!!"
    elif cond == -3:
        msg = "You aren't done yet!"
    else:
        msg = "You Lose!! Better luck next time!"
    return cond

# hint :: gives possible values for square #
def hint(board):
    global msg
    inpu = getCoords()
    chk = board.hint(inpu[0],inpu[1])
    msg = "Test"
    if chk == -1:
        error1()
    elif chk == -2:
        error2()
    else:
        msg = "Possible Values:"
        for i in chk:
            msg = msg + " " + str(i)

# insert :: insert into desired coord (with error handling) #
def insert(board):
    global msg
    inpu = getCoords()
    inpu1 = getVal()

    chk = board.checkSpc(inpu1, inpu[0],inpu[1])
    if chk == 1:
        board.insert(inpu[0],inpu[1],inpu1)
        msg = ""
    elif chk == -2:
        error2()
    else:
        error1()

# getVal :: gets the value #
def getVal():
    inpu = -1
    while inpu == -1:
        inpu = chkVal()
        if inpu == -1:
            print "Please enter valid value (e.g. 1-9): "
    return inpu

# chkVal :: checks value to enter square #
def chkVal():
    inpu = raw_input("Enter Value: ")
    # check for invalid input
    if len(inpu) != 1:
        return -1
    inpu = ord(inpu)
    # check for valid input
    if inpu < 49 or inpu > 57:
        return -1

    return (inpu - ord('0'))

# getCoords :: retrieves valid coords # ******coords returned as [x, y] 
def getCoords():
    inpu = -1
    while inpu == -1:
        inpu = chkCoords()
        if inpu == -1:
            print "Please enter vaild coords (e.g. E4): "
    return inpu

# chkCoords :: checks valid coords #
def chkCoords():
    inpu = raw_input("Enter Coord: ")

     # check for wrong number inputs
    if len(inpu) != 2:
        return -1

    fInpu = [ord(inpu[0].lower()), ord(inpu[1].lower())]

    # convert user input
    if isLetter(fInpu[0]) \
       and isDigit(fInpu[1]):
        return [(fInpu[0] - ord('a')), (fInpu[1] - ord('1'))]

    # check for inverted input and convert
    if isLetter(fInpu[1]) \
       and isDigit(fInpu[0]):
        return [(fInpu[1] - ord('a')), (fInpu[0] - ord('1'))]

    # check for input outside of range
    if (not isDigit(fInpu[0]) and not isLetter(fInpu[0])) \
       or (not isDigit(fInpu[1]) and not isLetter(fInpu[1])):
        return -1

    # check if both are letters or both are numbers
    if (isLetter(fInpu[0]) \
        and isLetter(fInpu[0])) \
        or (isDigit(fInpu[1]) \
            and isDigit(fInpu[0])):
        return -1

    return inpu

# Error messages to print #
def error1():
    global msg
    msg ="Value doesn't work here!"

def error2():
    global msg
    msg = "Space already filled!"
###########################

# isLetter :: tests to see if input is letter #
def isLetter(test):
    if test >= 97 and test <= 105:
        return True
    else:
        return False

# isDigit :: tests to see if input is digit #
def isDigit(test):
    if test >= 49 and test <= 57:
        return True
    else:
        return False

# main :: controls program #
def main():
    cont = True
    h.clr()
    board = Board()
    board.reset()
    board.read()
    while cont:
        h.clr()
        print msg
        board.display()
        cont = instructions(board)

main()
