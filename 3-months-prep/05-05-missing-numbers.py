from collections import Counter
from typing import List

def missingNumbers(arr: List[int], brr: List[int]):
    result = []
    arr_counts = Counter(arr)    
    brr_counts = Counter(brr)
    for k, v in brr_counts.items():
        if k not in arr_counts or v > arr_counts[k]:
            result.append(k)
    return sorted(result)


input_values = [ [[203,204,205,206,207,208,203,204,205,206],[203,204,204,205,206,207,205,208,203,206,205,206,204]], [[11,4,11,7,13,4,12,11,10,14],[11,4,11,7,3,7,10,13,4,8,12,11,10,14,12]], ]
input_checks = [ [204,205,206], [3,7,8,10,12], ]
assert (len(input_values) == len(input_checks))

for (arr, brr), check in zip(input_values, input_checks):
    print("arr=(%s), brr=(%s)" % (arr, brr))
    result = missingNumbers(arr, brr)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

