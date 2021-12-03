

def climbingLeaderboard(ranked, player):
    result = []
    ranked_unique = list(sorted(set(ranked), reverse=True))
    for score in player:        
        index = 0
        for i in range(len(ranked_unique)):
            index += 1
            if ranked_unique[i] <= score:
                break
        if score < ranked_unique[-1]:
            index += 1
        result.append(index)
    return result

def climbingLeaderboard_BinarySearch(ranked, player):
    result = []
    ranked_unique = list(sorted(set(ranked), reverse=True))
    for score in player:        
        index = 0
        #   TODO: 2021-11-22T13:27:10AEDT binary search for position-to-be-inserted
        #for i in range(len(ranked_unique)):
        #    index += 1
        #    if ranked_unique[i] <= score:
        #        break
        #if score < ranked_unique[-1]:
        #    index += 1
        result.append(index)
    return result


def climbingLeaderboard_TwoPointers(ranked, player):
    result = []
    ranked_unique = list(sorted(set(ranked), reverse=True))

    #   position in 'player'
    i = 0

    #   position in 'ranked_unique'
    j = len(ranked_unique) - 1

    while i < len(player):
        if j < 0:
            result.append(1)
            i += 1
        elif player[i] < ranked_unique[j]:
            result.append(j+2)
            i += 1
        elif player[i] > ranked_unique[j]:
            j -= 1
        else:
            result.append(j+1)
            i += 1

    return result


def climbingLeaderboard_ii(ranked, player):
    result = []
    ranked_unique = list(sorted(set(ranked), reverse=True))
    for score in player:
        while ranked_unique and score >= ranked_unique[-1]:
            ranked_unique.pop()
        result.append(len(ranked_unique)+1)
    return result



input_values = [ (list(map(int, "100 100 50 40 40 20 10".split())), list(map(int, "5 25 50 120".split()))), (list(map(int, "100 90 90 80 75 60".split())), list(map(int, "50 65 77 90 102".split()))), ]
input_checks = [ [6,4,2,1], [6,5,4,2,1], ]

for (ranked, player), check in zip(input_values, input_checks):
    #result = climbingLeaderboard_TwoPointers(ranked, player)
    result = climbingLeaderboard_ii(ranked, player)
    print("result=(%s)" % result)
    assert result == check, "Check comparison failed"
    print()

