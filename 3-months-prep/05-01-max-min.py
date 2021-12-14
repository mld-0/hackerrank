from typing import List

def maxMin(k: int, arr: List[int]) -> int:
    arr = sorted(arr)
    index = 0
    for l in range(1, len(arr)-k+1):
        if arr[l+k-1] - arr[l] < arr[index+k-1] - arr[index]:
            index = l
    return arr[index+k-1] - arr[index]


input_values = [ [3, [10,100,300,200,1000,20,30]], [4, [1,2,3,4,10,20,30,40,100,200]], [2, [1,2,1,2,1]], ]
input_checks = [ 20, 3, 0, ]
assert (len(input_values) == len(input_checks))

for (k, arr), check in zip(input_values, input_checks):
    print("k=(%s), arr=(%s)" % (k, arr))
    result = maxMin(k, arr)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

