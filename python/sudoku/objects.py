class Board:

    def __init__(self):
        self.reset()

    def reset(self):
        self.b = [[0 for x in range(9)] for y in range(9)]
        self.const = [[0 for x in range(9)] for y in range(9)]

    def display(self):
        # Display the set up board #
        print("\n    A B C     D E F     G H I")
        for i in range(0,9):
            for j in range(0,9):
                if i % 3 == 0 and \
                   i != 0 and j == 0:
                    print "    -------+---------+-------"
                if j % 3 == 0 and \
                   j != 0:
                    print " | " , self.b[i][j],
                elif j == 8:
                    print self.b[i][j]
                elif j == 0:
                    print " ", i + 1, self.b[i][j],
                else:
                    print self.b[i][j],

    def read(self):
        # Read in the given file #
        count = 0
        with open(raw_input("Open file: "), 'r') as data:
            for line in data:
                temp = map(int, line.split())
                self.b[count] = temp
                self.const[count] = temp
                count += 1

    def insert(self, x=0, y=0, data=0):
        # insert data at specified location #
        self.b[y][x] = data

    def checkSpc(self, inpu, x=0,y=0):
        # verify that location is valid #
        sY = ((y / 3) * 3)
        sX = ((x / 3) * 3)

        if self.b[y][x] == 0:
            for i in range(0,9):
                if inpu == self.b[i][x] and y != i:
                    return -1
                for j in range(0,9):
                    if inpu == self.b[y][j] and x != j:
                        return -1
                    for i in range(sY,(sY + 3)):
                        for j in range(sX,(sX + 3)):
                            if inpu == self.b[i][j] and i != y and j != x:
                                return -1
        else:
            return -2
        return 1

    def hint(self, x, y):
        possible = []
        for i in range(1,10):
            res = self.checkSpc(i,x,y)
            if res == -2:
                return -2
            if res != -1:
                possible.append(i)
        if len(possible) > 0:
            return possible
        else:
            return -2

    def isComplete(self):
        for i in range(0,9):
            if 0 in self.b[i]:
                return False
        return True

    def chkGame(self):
        if self.isComplete():
            for i in range(0,10):
                for j in range(0,10):
                    self.checkSpc(self.b[i][j],i,j)
        else:
            return -3
