from typing import List
from contextlib import redirect_stdout
import io

def plusMinus(arr: List[int]):
    count_positive = sum( [ 1 if x > 0 else 0 for x in arr ] )
    count_negative = sum( [ 1 if x < 0 else 0 for x in arr ] )
    count_zero = len(arr) - (count_positive + count_negative)
    ratio_positive = count_positive / len(arr)
    ratio_negative = count_negative / len(arr) 
    ratio_zero = count_zero / len(arr)
    print("%.6f" % ratio_positive)
    print("%.6f" % ratio_negative)
    print("%.6f" % ratio_zero)


input_values = [ "6\n-4 3 -9 0 4 1\n", "8\n1 2 3 -1 -2 -3 0 0\n", ];
input_checks = [ "0.500000\n0.333333\n0.166667\n", "0.375000\n0.375000\n0.250000\n", ];
assert (len(input_values) == len(input_checks))

for value, check in zip(input_values, input_checks):
    loop_value_lines = value.split('\n')

    n = int(loop_value_lines[0])
    arr = list(map(int, loop_value_lines[1].split(' ')))
    print("arr=(%s)" % arr)

    ss = io.StringIO()

    with redirect_stdout(ss):
        plusMinus(arr)
    result = ss.getvalue()
    print("result=(%s)" % result)

    assert (result == check), "check comparison failed"

