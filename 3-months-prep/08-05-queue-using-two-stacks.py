
class StacksQueue:
    inbox = []
    outbox = []
    def enqueue(self, x):
        self.inbox.append(x)
    def dequeue(self):
        #   if outbox is empty, refil from inbox
        self.refill_outbox()
        return self.outbox.pop()
    def print_front(self):
        self.refill_outbox()
        return self.outbox[-1]
    def refill_outbox(self):
        if len(self.outbox) == 0:
            while len(self.inbox) > 0:
                temp = self.inbox.pop()
                self.outbox.append(temp)


input_lines = [ tuple(map(int, x.split())) for x in "1 42\n2\n1 14\n3\n1 28\n3\n1 60\n1 78\n2\n2".rstrip().split('\n') ]
input_checks = [ 14, 14 ]

print("input_lines=(%s)" % input_lines)
queue = StacksQueue()

result = []
for input_split in input_lines:
    if input_split[0] == 1:
        queue.enqueue(input_split[1])
    elif input_split[0] == 2:
        queue.dequeue()
    elif input_split[0] == 3:
        result.append(queue.print_front())

print("result=(%s)" % result)
assert result == input_checks, "Check comparison failed"
print()
   
