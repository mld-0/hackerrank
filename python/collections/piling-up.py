from collections import deque

def can_stack(blocks):
    result = []
    L = blocks[0]
    R = blocks[-1]
    if L > R:
        blocks.popleft()
        result.append(L)
    else:
        blocks.pop()
        result.append(R)
    while len(blocks) > 0:
        L = blocks[0]
        R = blocks[-1]
        #   Choose the larger of L/R that is smaller than result[-1]
        if L > R and L <= result[-1]:
            blocks.popleft()
            result.append(L)
        elif L <= R and R <= result[-1]:
            blocks.pop()
            result.append(R)
        else:
            return "No"
    return "Yes"
       

blocks = deque([ 1000000842, 1000000721, 1000000671, 1000000663, 1000000626, 1000000520, 1000000126, 999999978, 1000000266, 1000000501, ])
result = can_stack(blocks)
print("result=(%s)" % result)

blocks = deque([ 105965242, 494136789, 450676517, 36179826, 473818721, 461541657, 144408199, 760779501, 863646256, 76190127, ])
result = can_stack(blocks)
print("result=(%s)" % result)

blocks = deque([ 427731488, 922935208, 973233245 ])
result = can_stack(blocks)
print("result=(%s)" % result)
