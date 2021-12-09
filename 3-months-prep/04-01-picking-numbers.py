import sys
import math
from collections import Counter


def subarray_difference_valid(values):
    n = 1
    values_set = set(values)
    values_set_list = list(values_set)
    if len(values_set_list) > 1 and abs(values_set_list[0]-values_set_list[1]) > n:
        return False
    if len(values_set) > n+1:
        return False
    return True
 

def pickingNumbers_i(a):
    a = sorted(a)
    result = []
    for k in range(1, len(a)):
        for l in range(0, len(a)-k):
            r = l + k
            sub = a[l:r+1]
            if subarray_difference_valid(sub):
                if len(sub) > len(result):
                    result = sub
    print(result)
    return len(result)
  

def pickingNumbers_ii(a):
    a_counts = Counter(a)
    keys = sorted(a_counts.keys())

    possible_values = dict()
    previous = -math.inf
    for x in keys:
        possible_values[x] = a_counts[x]
        if (x-1 == previous):
            possible_values[(previous, x)] = a_counts[previous] + a_counts[x]
        previous = x

    return max(possible_values.values())


def pickingNumbers_iii(a):
    """Taken from ans, uses counting sort (relying on 0 < a[i] < 100), O(n) since no sorting is involved"""
    max_len = 0
    counters = [0]*101
    for i in range(len(a)):
        counters[a[i]] += 1
    
    for j in range(len(counters)-1):
        length = counters[j+1] + counters[j]
        max_len = max(max_len, length)

    return max_len



input_values = [ [4,6,5,3,3,1], [1,2,2,3,1,2], [98,3,99,1,97,2], [4,2,3,4,4,9,98,98,3,3,3,4,2,98,1,98,98,1,1,4,98,2,98,3,9,9,3,1,4,1,98,9,9,2,9,4,2,2,9,98,4,98,1,3,4,9,1,98,98,4,2,3,98,98,1,99,9,98,98,3,98,98,4,98,2,98,4,2,1,1,9,2,4], [84,43,11,41,2,99,31,32,56,53,42,14,98,27,64,57,16,33,48,21,46,61,87,90,28,12,62,49,29,77,82,70,80,89,95,52,13,19,9,79,35,67,51,39,7,1,66,8,17,85,71,97,34,73,75,6,91,40,96,65,37,74,20,68,23,47,76,55,24,3,30,22,55,5,69,86,54,50,10,59,15,4,36,38,83,60,72,63,78,58,88,93,45,18,94,44,92,81,25,26], [7,12,13,19,17,7,3,18,9,18,13,12,3,13,7,9,18,9,18,9,13,18,13,13,18,18,17,17,13,3,12,13,19,17,19,12,18,13,7,3,3,12,7,13,7,3,17,9,13,13,13,12,18,18,9,7,19,17,13,18,19,9,18,18,18,19,17,7,12,3,13,19,12,3,9,17,13,19,12,18,13,18,18,18,17,13,3,18,19,7,12,9,18,3,13,13,9,7], [66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66], [4,97,5,97,97,4,97,4,97,97,97,97,4,4,5,5,97,5,97,99,4,97,5,97,97,97,5,5,97,4,5,97,97,5,97,4,97,5,4,4,97,5,5,5,4,97,97,4,97,5,4,4,97,97,97,5,5,97,4,97,97,5,4,97,97,4,97,97,97,5,4,4,97,4,4,97,5,97,97,97,97,4,97,5,97,5,4,97,4,5,97,97,5,97,5,97,5,97,97,97], [9,6,13,16,5,18,4,10,3,19,4,5,8,1,13,10,20,17,15,10,6,10,13,20,18,17,7,10,6,5,16,18,13,20,19,7,16,13,20,17,4,17,8,19,12,7,17,1,18,3,16,4,5,3,15,17,6,17,14,11,11,7,11,6,15,15,12,6,17,19,8,6,13,9,10,19,14,18,7,9,11,16,11,20,4,20,10,7,8,4,2,12,11,8,12,13,19,8,8,5], [14,18,17,10,9,20,4,13,19,19,8,15,15,17,6,5,15,12,18,2,18,7,20,8,2,8,11,2,16,2,12,9,3,6,9,9,13,7,4,6,19,7,2,4,3,4,14,3,4,9,17,9,4,20,10,16,12,1,16,4,15,15,9,13,6,3,8,4,7,14,16,18,20,11,20,14,20,12,15,4,5,10,10,20,11,18,5,20,13,4,18,1,14,3,20,19,14,2,5,13], ];
input_checks = [ 3, 5, 2, 22, 3, 30, 100, 50, 13, 15, ];

test_functions = [ pickingNumbers_i, pickingNumbers_ii, ]

for test_func in test_functions:
    print(test_func.__name__)
    for (a, check) in zip(input_values, input_checks): 
        print("a=(%s)" % a)
        print("check=(%s)" % check)
        result = test_func(a)
        print("result=(%s)" % result)
        assert result == check, "Check comparison failed"
    print()


