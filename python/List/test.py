####
from objects import Node
from objects import List
####


def test1():
    node4 = Node(4)
    node3 = Node(3, node4)
    node2 = Node(2, node3)
    node1 = Node(1, node2)

    nIt = node1
    while nIt != None:
        print nIt.data
        nIt = nIt.next

    #node1.next = node2
    #print node1.next.data

class Counter:
    def __init__(self,v=0):
        self.value = v
    def nextVal(self):
        self.value = self.value + 1
        return self.value

def main():
    tmp = List()
    c = Counter()
    tmp.push_back(c.nextVal())
    tmp.push_back(c.nextVal())
    n = tmp.push_back(c.nextVal())
    tmp.insertI(c.nextVal(),1)
    tmp.insertP(c.nextVal(),n)
    tmp.push_back(c.nextVal())
    tmp.insertI(c.nextVal(),6)
    tmp.display()

main()
