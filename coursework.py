initialised = False

class Pseudo:
    def __init__(self):
        self.modulus = 2**32
        self.a = 1664525
        self.c = 1013904223
        self.seed = 1234567

    def next(self, limit):
        self.seed = (self.a * self.seed + self.c) % self.modulus
        return self.seed % limit

p = Pseudo()

def nextNumber():
    global initialised, p
    if (not initialised):
        number = input("Please enter your student number: ")
        p.seed = int(number)
        initialised = True
    return p.next(1000)

#####################################################################
## DO NOT CHANGE THE CODE ABOVE THIS BOUNDARY
#####################################################################

## WRITE YOUR CODE HERE
x = set()
y = set()

for i in range(100):
    n = nextNumber()
    if n in x:
        y.add(n)
    else:
        x.add(n)
u = len(x)
d = len(y)
print("list of ",u,"unique number:")
print(x)
print("list of ",d,"duplicate number:")
print(y)



