from typing import List

def superDigit(n: int, k: int) -> int:
    test_str = str(n)
    if len(test_str) == 1:
        return int(test_str)
    result = 0
    for x in test_str:
        result += int(x)
    result = result * k
    return superDigit(result, 1)


input_values = [ [148,3], [9875,4], ]
input_checks = [ 3, 8, ]
assert (len(input_values) == len(input_checks))

for (n, k), check in zip(input_values, input_checks):
    print("n=(%s), k=(%s)" % (n, k))
    result = superDigit(n, k)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

