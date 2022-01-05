
class StacksQueue:
    def __init__(self):
        self.inbox = []
        self.outbox = []
    def enqueue(self, x):
        self.inbox.append(x)
    def dequeue(self):
        self.refill_outbox()
        self.outbox.pop()
    def print_front(self):
        self.refill_outbox()
        return self.outbox[-1]
    def refill_outbox(self):
        if len(self.outbox) == 0:
            while len(self.inbox) > 0:
                temp = self.inbox.pop()
                self.outbox.append(temp)


input_values = [ "1 42\n2\n1 14\n3\n1 28\n3\n1 60\n1 78\n2\n2", "1 76\n1 33\n2\n1 23\n1 97\n1 21\n3\n3\n1 74\n3" ]
input_checks = [ [14,14], [33,33,33], ]
assert len(input_values) == len(input_checks)

for lines, check in zip(input_values, input_checks):
    queue = StacksQueue()
    result = []
    values = [ list(map(int, x.split(" "))) for x in lines.split("\n") ]
    print("values=(%s)" % values)
    for item in values:
        print("item=(%s)" % item)
        if item[0] == 1:
            queue.enqueue(item[1])
        elif item[0] == 2:
            queue.dequeue()
        elif item[0] == 3:
            result.append(queue.print_front())
    print("result=(%s)" % result)
    assert result == check, "Check comparison failed"
    print()

