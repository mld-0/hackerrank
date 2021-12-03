import math

def maxSubArray(arr):
    """Find max sum of: 1) nonempty subarray, 2) nonempty contigous subarray"""

    result_subsequence = sum( [ x if x > 0 else 0 for x in arr ] )
    if result_subsequence == 0:
        result_subsequence = max(arr)

    result_continuous_subsequence = -math.inf
    curr = -math.inf
    for i in arr:
        curr = max(i, curr+i)
        result_continuous_subsequence = max(curr, result_continuous_subsequence)

    return ( result_continuous_subsequence, result_subsequence )


input_values = [ [1,2,3,4], [2,-1,2,3,4,-5], [-2,-3,-1,-4,-6], ]
input_checks = [ (10, 10), (10, 11), (-1, -1), ]

for arr, check in zip(input_values, input_checks):
    print("arr=(%s)" % arr)
    result = maxSubArray(arr)
    print("result=(%s)" % list(result))
    assert list(result) == list(check), "Check comparison failed"
    print()

