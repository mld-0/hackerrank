import math
from collections import Counter
from typing import List

def migratoryBirds(arr):
    result_value = -math.inf
    result_index = None
    counts = Counter(arr)
    #for k, v in counts.items():
    for k in sorted(counts.keys()):
        v = counts[k]
        if v > result_value:
            result_index = k
            result_value = v
    return result_index


input_values = [ [1,4,4,4,5,3], [1,2,3,4,5,4,3,2,1,3,4], ]
input_checks = [ 4, 3, ]
assert (len(input_values) == len(input_checks))

for arr, check in zip(input_values, input_checks):
    print("arr=(%s)" % arr)
    result = migratoryBirds(arr)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

