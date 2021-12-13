from typing import List

def diagonalDifference(arr: List[List[int]]) -> int:
    LR = 0
    RL = 0
    for i in range(len(arr)):
        RL += arr[i][i]
        LR += arr[len(arr)-i-1][i]
    return abs(RL - LR)


input_values = [ [[11,2,4],[4,5,6],[10,8,-12]], [[-1,1,-7,-8],[-10,-8,-5,-2],[0,9,7,-1],[4,4,-2,1]], ]
input_checks = [ 15, 1, ]
assert (len(input_values) == len(input_checks))

for (arr, check) in zip(input_values, input_checks):
    print("arr=(%s)" % arr)
    result = diagonalDifference(arr)
    print("result=(%s)" % result)
    assert (result == check)
    print()

