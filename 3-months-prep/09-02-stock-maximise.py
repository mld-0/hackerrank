import math
import os
import random
import re
import sys

def stockmax(prices):
    #   for each given day, what is the maximum price that will be seen by the end
    day_futures = []
    max_seen = -math.inf
    for cur in prices[::-1]:
        max_seen = max(cur, max_seen)
        day_futures.append(max_seen)
    day_futures = day_futures[::-1]


    #   for each given day, what is the profit that can be made by purchasing 1 share
    day_profit = [ day_futures[i] - prices[i] for i in range(len(prices)) ]

    #   result is sum of the positive elements of 'profit'
    result = sum(map(lambda x: x if x > 0 else 0, day_profit))

    return result
    


input_values = [ [5,3,2], [1,2,100], [1,3,1,2], [1,2,3,4], [5,4,3,4,5], ]
input_checks = [ 0, 197, 3, 6, 4, ]

for prices, check in zip(input_values, input_checks):
    print("prices=(%s)" % prices)
    result = stockmax(prices)
    print("result=(%s)" % result)
    assert result == check, "Check comparison failed"
    print()

