
def DoublyLinkedListNode:
    def __init__(self, data, _next=None, _prev=None):
        self.data = data
        self.next = _next
        self.prev = _prev

#   Reverse a singly linked list:
#       def reverse(llist):
#           prev = None
#           curr = llist
#           while curr is not None:
#               temp = curr.next
#               curr.next = prev
#               prev = curr
#               curr = temp
#           return prev


def reverse(llist):
    if llist is None:
        return None
    prev = None
    curr = llist
    while curr is not None:
        temp = curr.next
        curr.prev = curr.next
        curr.next = prev
        prev = curr
        curr = temp
    return prev

