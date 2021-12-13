import itertools
from typing import List

def divisibleSumPairs_i(n: int, k: int, arr: List[int]):
    divisible_pairs = [ x for x in itertools.combinations(arr, 2) if sum(x) % k == 0 ]
    return len(divisible_pairs)


test_functions = [ divisibleSumPairs_i, ]

input_values = [ [3, [1,3,2,6,1,2]], [2, [5,9,10,7,4]], [2, [8,10]], ]
input_checks = [ 5, 4, 1, ]
assert (len(input_values) == len(input_checks))

for test_func in test_functions:
    print(test_func.__name__)
    for ((k, arr), check) in zip(input_values, input_checks):
        n = 0
        print("k=(%s), arr=(%s)" % (k, arr))    
        result = test_func(n, k, arr)
        print("result=(%s)" % result)
        assert (result == check), "Check comparison failed"
    print()



