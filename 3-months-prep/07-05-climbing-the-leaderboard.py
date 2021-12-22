from typing import List
import bisect

def climbingLeaderboard_LinearSearch(ranked: List[int], player: List[int]) -> List[int]:
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


def climbingLeaderboard_BisectRight(ranked: List[int], player: List[int]) -> List[int]:
    result = []
    ranked_unique = list(sorted(set(ranked)))
    for score in player:        
        index = len(ranked_unique) - bisect.bisect_right(ranked_unique, score) + 1
        result.append(index)
    return result


def climbingLeaderboard_BinarySearch(ranked: List[int], player: List[int]) -> List[int]:
    result = []
    ranked_unique = list(sorted(set(ranked)))
    for score in player:        
        low = 0
        high = len(ranked_unique) - 1
        while low <= high:
            mid = (low + high) // 2
            if (ranked_unique[mid] > score):
                high = mid - 1
            else:
                low = mid + 1
        index = len(ranked_unique) - low + 1
        result.append(index)
    return result


def climbingLeaderboard_TwoPointers(ranked: List[int], player: List[int]) -> List[int]:
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


def climbingLeaderboard_Stack(ranked: List[int], player: List[int]) -> List[int]:
    result = []
    ranked_unique = list(sorted(set(ranked), reverse=True))
    assert (sorted(player) == player)
    for score in player:
        while ranked_unique and score >= ranked_unique[-1]:
            ranked_unique.pop()
        result.append(len(ranked_unique)+1)
    return result


test_functions = [ climbingLeaderboard_LinearSearch, climbingLeaderboard_BisectRight, climbingLeaderboard_BinarySearch, climbingLeaderboard_TwoPointers, climbingLeaderboard_Stack, ]

input_values = [ [[100,100,50,40,40,20,10], [5,25,50,120]], [[100,90,90,80,75,60], [50,65,77,90,102]],[[295,294,291,287,287,285,285,284,283,279,277,274,274,271,270,268,268,268,264,260,259,258,257,255,252,250,244,241,240,237,236,236,231,227,227,227,226,225,224,223,216,212,200,197,196,194,193,189,188,187,183,182,178,177,173,171,169,165,143,140,137,135,133,130,130,130,128,127,122,120,116,114,113,109,106,103,99,92,85,81,69,68,63,63,63,61,57,51,47,46,38,30,28,25,22,15,14,12,6,4], [5,5,6,14,19,20,23,25,29,29,30,30,32,37,38,38,38,41,41,44,45,45,47,59,59,62,63,65,67,69,70,72,72,76,79,82,83,90,91,92,93,98,98,100,100,102,103,105,106,107,109,112,115,118,118,121,122,122,123,125,125,125,127,128,131,131,133,134,139,140,141,143,144,144,144,144,147,150,152,155,156,160,164,164,165,165,166,168,169,170,171,172,173,174,174,180,184,187,187,188,194,197,197,197,198,201,202,202,207,208,211,212,212,214,217,219,219,220,220,223,225,227,228,229,229,233,235,235,236,242,242,245,246,252,253,253,257,257,260,261,266,266,268,269,271,271,275,276,281,282,283,284,285,287,289,289,295,296,298,300,300,301,304,306,308,309,310,316,318,318,324,326,329,329,329,330,330,332,337,337,341,341,349,351,351,354,356,357,366,369,377,379,380,382,391,391,394,396,396,400]], ]
input_checks = [ [6,4,2,1], [6,5,4,2,1], [88,88,87,85,84,84,83,82,81,81,80,80,80,80,79,79,79,79,79,79,79,79,77,75,75,74,73,73,73,71,71,71,71,71,71,70,70,69,69,68,68,68,68,67,67,67,66,66,65,65,64,64,62,61,61,60,59,59,59,59,59,59,58,57,56,56,55,55,53,52,52,51,51,51,51,51,51,51,51,51,51,51,51,51,50,50,50,50,49,49,48,48,47,47,47,45,43,42,42,41,38,36,36,36,36,35,35,35,35,35,35,34,34,34,33,33,33,33,33,32,30,28,28,28,28,27,27,27,26,23,23,22,22,20,20,20,18,18,15,15,14,14,13,13,11,11,10,10,8,8,7,6,5,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], ]
assert (len(input_values) == len(input_checks))

for test_func in test_functions:
    print(test_func.__name__)
    for (ranked, player), check in zip(input_values, input_checks):
        print("ranked=(%s), player=(%s)" % (ranked, player))
        result = test_func(ranked, player)
        print("result=(%s)" % result)
        assert result == check, "Check comparison failed"
    print()

