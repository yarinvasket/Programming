class Node:
    def __init__(self, dataval=None):
        self.dataval = dataval
        self.nextval = None

class LinkedList:
    def __init__(self):
        self.headval = None

print(2)
print(3)

primes = LinkedList()
primes.headval = Node(3)

i = 5
while True:
    curr = primes.headval
    while True:
        if curr.nextval == None:
            if i % curr.dataval != 0:
                curr.nextval = Node(i)
                print(i)
            break
        if i % curr.dataval == 0:
            break
        curr = curr.nextval
    i += 2