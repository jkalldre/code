class Node:
    def __init__(self, t=None,p=None,n=None):
        self.data = t
        self.prev = p
        self.next = n

class List:
    def __init__(self):
        self.phead = None
        self.ptail = None
        self.size  = 0

    def push_front(self, t=None):
        '''Insert on front of list'''
        newNode = Node(t,None,self.phead)
        if self.phead:
            self.phead.prev = newNode
        self.phead = newNode
        if self.size == 0:
            self.ptail = newNode
        self.size = self.size + 1
        return newNode

    def push_back(self, t=None):
        '''Insert on end of list'''
        newNode = Node(t,self.ptail,None)
        if self.ptail:
            self.ptail.next = newNode
        self.ptail = newNode
        if self.size == 0:
            self.phead = newNode
        self.size = self.size + 1
        return newNode

    def insertI(self,t,index):
        '''If index is outside list then push_back is called
           else value is inserted at index'''
        if index > self.size:
            self.push_back(t)
        else:
            nIt = self.phead
            count = 0
            while count != index:
                count = count + 1
                nIt = nIt.next
                newNode = Node(t,nIt.prev,nIt)
                if nIt.prev:
                    nIt.prev.next = newNode
                else:
                    self.phead = newNode
                nIt.prev = newNode
                return newNode

    def insertP(self,t,nIt):
        '''Insert value at given address'''
        newNode = Node(t,nIt.prev,nIt)
        if nIt.prev:
            nIt.prev.next = newNode
        else:
            self.phead = newNode
        nIt.prev = newNode
        return newNode

    def display(self):
        '''Display head and tail, then whole list'''
        if self.phead:
            print "phead: ", self.phead.data
        else:
            print "Null"
        if self.ptail:
            print "ptail: ", self.ptail.data
        else:
            print "Null"

        nIt = self.phead
        while nIt:
            print nIt.data
            nIt = nIt.next
