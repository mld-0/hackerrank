from typing import List

def gamingArray(arr: List[int]) -> int:
    #   Iterating over the array, left to right, count the number of times a new maximum value is encountered
    max_val = arr[0]
    count = 1
    for i in range(1, len(arr)):
        if arr[i] > max_val:
            max_val = arr[i]
            count += 1
    #   The winner is determined by whether the count is even or odd
    if count % 2 == 0:
        return "ANDY"
    else:
        return "BOB"


input_values = [ [5,2,6,3,4], [3,1], [1,3,5,7,9], [7,4,6,5,9], ]
input_checks = [ "ANDY", "BOB", "BOB", "ANDY", ]

for arr, check in zip(input_values, input_checks):
    print("arr=(%s)" % arr)
    result = gamingArray(arr)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

