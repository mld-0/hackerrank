import math
import os
import random
import re
import sys


    def counterGame(n):
        count = 0
        while n > 1:
            if math.log2(n) == int(math.log2(n)):
                n = n / 2
            else:
                n -= 2 ** int(math.log2(n))
            count += 1
        if count % 2 == 0:
            return "Richard"
        else:
            return "Louise"

if __name__ == '__main__':
    t = 5
    input_values = [ 1560834904, 1768820483, 1533726144, 1620434450, 1463674015, ]
    input_checks = [ "Richard", "Richard", "Louise", "Richard", "Louise", ]

    for n, check in zip(input_values, input_checks):
        #n = int(input().strip())
        result = counterGame(n)
        print("result=(%s)" % result)
        assert result == check, "Check comparison failed"
        print()

