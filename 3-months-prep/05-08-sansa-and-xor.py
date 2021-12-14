from typing import List

def sansaXor(arr: List[int]) -> int:
    if len(arr) % 2 == 0:
        return 0
    result = arr[0]
    for i in range(2, len(arr), 2):
        result ^= arr[i]
    return result


input_values = [ [1,2,3], [4,5,7,5], [98,74,12], [50,13,2], ]
input_checks = [ 2, 0, 110, 48, ]

for arr, check in zip(input_values, input_checks):
    print("arr=(%s)" % arr)
    result = sansaXor(arr)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

