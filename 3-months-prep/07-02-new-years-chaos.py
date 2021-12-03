import math
import os
import random
import re
import sys

#
# Complete the 'minimumBribes' function below.
#
# The function accepts INTEGER_ARRAY q as parameter.
#

def minimumBribes(q):
    #   Update to begin at 0
    queue = [ x-1 for x in q ]
    bribes = 0

    for i, x in enumerate(queue):
        if x - i > 2:
            return False
        for k in q[:i]:
            if k > x:
                bribes += 1

    return bribes



if __name__ == '__main__':
    input_values = [ [2, 1, 5, 3, 4,], [2, 5, 1, 3, 4,], list(map(int, "5 1 2 3 7 8 6 4".split())), list(map(int, "1 2 5 3 7 8 6 4".split())), ]
    input_checks = [ 3, False, False, 7, ]

    for q, check in zip(input_values, input_checks):
        result = minimumBribes(q)
        print("result=(%s)" % result)
        assert result == check, "Check comparison failed"
        print()

        
