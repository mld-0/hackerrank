from typing import List

def birthday_i(s: List[int], d: int, m: int):
    results = []
    # Write your code here
    for k in range(len(s)-m+1):
        loop_group = s[k:k+m]
        if sum(loop_group) == d:
            results.append(loop_group)
    return len(results)


def birthday_ii(s: List[int], d: int, m: int):
    results = [ s[k:k+1] for k in range(len(s)-m+1) if sum(s[k:k+m]) == d ]
    return len(results)


test_functions = [ birthday_i, birthday_ii, ]

input_values = [ [[1,2,1,3,2], 3,2], [[1,1,1,1,1,1], 3,2], [[4], 4,1], [[2,5,1,3,4,4,3,5,1,1,2,1,4,1,3,3,4,2,1], 18,7], ]
input_checks = [ 2, 0, 1, 3, ];
assert (len(input_values) == len(input_checks))

for test_func in test_functions:
    print(test_func.__name__)
    for (s, d, m), check in zip(input_values, input_checks):
        print("s=(%s), d=(%s), m=(%s)" % (s, d, m))
        result = test_func(s, d, m)
        print("result=(%s)" % result)
        assert (result == check), "Check comparison failed"
    print()

