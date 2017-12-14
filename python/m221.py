from math import sqrt

def cintervals(u, o, n):
    c90 = getME(1.645, o, n)#(1.645 * o) / sqrt(n) 
    c95 = getME(1.960, o, n)#(1.960 * o) / sqrt(n)
    c99 = getME(2.576, o, n)#(2.576 * o) / sqrt(n)
    print "[90: ME|", round(c90,3), "]", (round(u-c90,3), round(u+c90,3))
    print "[95: ME|", round(c95,3), "]", (round(u-c95,3), round(u+c95,3))
    print "[99: ME|", round(c99,3), "]", (round(u-c99,3), round(u+c99,3))
     
def getME(z, o, n):
    """Percent, STD, Size"""
    return (z * o) / sqrt(n) 

def cinterval(z, u, o, n):
    cZ = getME(z, o, n)
    print "[ME|", round(cZ,3), "]", (round(u-cZ,3), round(u+cZ,3))
    
def getN(z, o, m):
    return ((z * o) / m)**2

def sofp (p, n):
    return sqrt((p * (1-p))/n)

def zofp (ph, p, s):
    return (ph - p) / s
