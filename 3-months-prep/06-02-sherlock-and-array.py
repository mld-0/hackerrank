from typing import List

def balancedSums(arr: List[int]) -> int:
    if sum(arr[1:]) == 0:
        return "YES"
    if sum(arr[:-1]) == 0:
        return "YES"
    sum_l = 0
    sum_r = sum(arr[1:])
    for i in range(1, len(arr)-1):
        sum_l += arr[i-1]
        sum_r -= arr[i]
        if sum_l == sum_r:
            return "YES"
    return "NO"


input_values = [ [1,2,3], [1,2,3,3], [1,1,4,1,1], [2,0,0,0], [0,0,2,0], ]
input_checks = [ "NO", "YES", "YES", "YES", "YES", ]
assert (len(input_values) == len(input_checks))

for arr, check in zip(input_values, input_checks):
    print("arr=(%s)" % arr)
    result = balancedSums(arr)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

