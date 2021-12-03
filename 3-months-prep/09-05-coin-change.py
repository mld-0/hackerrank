from typing import List
import pprint


def getWays_DP_TopDown(total: int, coins: List[int]) -> int:
    memo = dict()

    #   number of combinations from 'coins[:m]' that sum to 'total'
    def solve(total, m):
        if (total,m) in memo:
            return memo[(total,m)]

        #   one combination (no coins) sums to zero
        if total == 0:
            return 1

        #   no combinations sum to <0
        if total < 0:
            return 0

        #   no coins, there are no combination that sum to a positive value
        if m < 0 and total > 0:
            return 0

        trial1 = solve(total-coins[m], m)

        trial2 = solve(total, m-1)

        result = trial1 + trial2 
        memo[(total,m)] = result
        return result

    return solve(total, len(coins)-1)


def getWays_DP_BottomUp(total: int, coins: List[int]) -> int:
    #   table[i][j]: number of combinations from 'coins[:i+1]' that sum to 'j'
    table = [ [ None for _ in range(total+1) ] for _ in range(len(coins)) ]

    #   one combination (no coins) gives total=0
    for i in range(len(coins)):
        table[i][0] = 1

    for i in range(len(coins)):
        for j in range(1, total+1):
            trial1, trial2 = 0, 0

            #   how many combinations of 'coins[:i+1]' sum to 'j-coins[i]'
            if j - coins[i] >= 0:
                trial1 += table[i][j-coins[i]]

            #   how many combinations of 'coins[:i]' sum to 'j'
            if i >= 1:
                trial2 += table[i-1][j]

            table[i][j] = trial1 + trial2

    return table[-1][-1]


def getWays_DP_BottomUp_ii(total: int, coins: List[int]) -> int: 
    #   table[j]: number of combinations from 'coins' that sum to 'j'
    table = [ 0 for _ in range(total+1) ]

    #   one combination (no coins) sums to zero
    table[0] = 1

    for i in range(len(coins)):
        for j in range(coins[i], total+1):
            table[j] += table[j-coins[i]]

    return table[total]


test_functions = [ getWays_DP_TopDown, getWays_DP_BottomUp, getWays_DP_BottomUp_ii, ]

input_values = [ (3, [8,3,1,2]), (4, [1,2,3]), ]
input_checks = [ 3, 4, ]

for test_func in test_functions:
    print(test_func.__name__)
    for (total, coins), check in zip(input_values, input_checks):
        print("total=(%s), coins=(%s)" % (total, coins))
        result = test_func(total, coins)
        print("result=(%s)" % result)
        assert result == check, "Check comparison failed"
    print()

