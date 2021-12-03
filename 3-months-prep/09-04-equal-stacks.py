from collections import deque


#   runtime: TLE
#def equalStacks(h1, h2, h3):
#    i = 0
#    j = 0
#    k = 0
#    while sum(h1[i:]) != sum(h2[j:]) and sum(h2[j:]) != sum(h3[k:]):
#        if sum(h1[i:]) >= sum(h2[j:]) and sum(h1[i:]) >= sum(h3[k:]):
#            i += 1
#        elif sum(h2[j:]) >= sum(h1[i:]) and sum(h2[j:]) >= sum(h3[k:]):
#            j += 1
#        elif sum(h3[k:]) >= sum(h1[i:]) and sum(h3[k:]) >= sum(h2[j:]):
#            k += 1
#    return sum(h1[i:])


def equalStacks(h1, h2, h3):
    h1 = deque(h1)
    h2 = deque(h2)
    h3 = deque(h3)

    t1 = sum(h1)
    t2 = sum(h2)
    t3 = sum(h3)

    minStack = min(t1, t2, t3)

    while (t1 != t2 or t1 != t3):

        while t1 > minStack:
            t1 -= h1.popleft()
        minStack = min(t1, t2, t3)

        while t2 > minStack:
            t2 -= h2.popleft()
        minStack = min(t1, t2, t3)

        while t3 > minStack:
            t3 -= h3.popleft()
        minStack = min(t1, t2, t3)

    return minStack



input_values = [ ([3,2,1,1,1], [4,3,2], [1,1,4,1]), ([1,1,1,1,1], [3,2], [1,3,1]), ([1], [1], [1]), ([1,1,1,1,2], [3,7], [1,3,1]), ]
input_checks = [ 5, 5, 1, 0, ]

for (h1, h2, h3), check in zip(input_values, input_checks):
    print("h1=(%s), h2=(%s), h3=(%s)" % (h1, h2, h3))
    result = equalStacks(h1, h2, h3)
    print("result=(%s)" % result)
    assert result == check, "Check comparison failed"
    print()

