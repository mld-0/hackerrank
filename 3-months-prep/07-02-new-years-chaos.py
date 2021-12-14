from typing import List, Union

def minimumBribes(q: List[int]) -> Union[int, bool]:
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


input_values = [ [2,1,5,3,4,], [2,5,1,3,4,], [5,1,2,3,7,8,6,4], [1,2,5,3,7,8,6,4], ]
input_checks = [ 3, False, False, 7,]

for q, check in zip(input_values, input_checks):
    print("q=(%s)" % q)
    result = minimumBribes(q)
    print("result=(%s)" % result)
    assert result == check, "Check comparison failed"
    print()

    
