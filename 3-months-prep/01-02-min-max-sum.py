from typing import List
from contextlib import redirect_stdout
import io

def miniMaxSum(arr: List[int]):
    first = sum(arr) - max(arr)
    second = sum(arr) - min(arr)
    print("%i %i" % (first, second))


input_values = ["1 2 3 4 5\n", "256741038 623958417 467905213 714532089 938071625\n", ]
input_checks = [ "10 14\n", "2063136757 2744467344\n", ]
assert (len(input_values) == len(input_checks))

for (arr, check) in zip(input_values, input_checks):
    arr = list(map(int, arr.rstrip().split(' ')))
    print("arr=(%s)" % arr)

    ss = io.StringIO()

    with redirect_stdout(ss):
        miniMaxSum(arr)
    result = ss.getvalue()
    print("result=(%s)" % result)

    assert (result == check), "Check comparison failed"
    print()

