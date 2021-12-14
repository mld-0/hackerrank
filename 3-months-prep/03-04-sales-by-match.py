from typing import List
from collections import Counter

def sockMerchant(n: int, arr: List[int]) -> int:
    result = 0
    counts = Counter(arr)
    for k, v in counts.items():
        result += v // 2
    return result


input_values = [ [10,20,20,10,10,30,50,10,20], [1,1,3,1,2,1,3,3,3,3], ]
input_checks = [ 3, 4, ]
assert (len(input_values) == len(input_checks))

for arr, check in zip(input_values, input_checks):
    print("arr=(%s)" % arr)
    result = sockMerchant(0, arr)
    print("arr=(%s)" % arr)
    assert (result == check), "Check comparison failed"
    print()



