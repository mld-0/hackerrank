
class SinglyLinkedListNode:
    def __init__(self, data, _next=None):
        self.data = data
        self.next = _next
    def to_list(self):
        result = []
        p = self
        while p is not None:
            result.append(p.data)
            p = p.next
        return result


#   Ongoing: 2021-11-28T21:35:03AEDT _hackerrank, (test), linked-list-remove-duplicates, for the solution (see below), why 'prev = cur' must be placed in else condition? (fails to delete multiple subisiquent duplicates otherwise?)
def removeDuplicates(llist):
    seen = set()
    head = llist
    cur = head
    prev = None
    while cur is not None:
        if cur.data in seen:
            prev.next = cur.next
        else:
            seen.add(cur.data)
            prev = cur
        cur = cur.next
    prev.next = None
    return head
       

def removeDuplicates_i(llist):
    seen = set()
    head = llist
    seen.add(head.data)
    current = head
    while current.next is not None:
        if current.next.data in seen:
            current.next = current.next.next
        else:
            seen.add(current.next.data)
            current = current.next
    return head



head = SinglyLinkedListNode(3)
p = head

p.next = SinglyLinkedListNode(3)
p = p.next

p.next = SinglyLinkedListNode(3)
p = p.next

p.next = SinglyLinkedListNode(4)
p = p.next

p.next = SinglyLinkedListNode(5)
p = p.next

p.next = SinglyLinkedListNode(5)
p = p.next

result = removeDuplicates(head)
print(result.to_list())


