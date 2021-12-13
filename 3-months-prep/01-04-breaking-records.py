
def breakingRecords(scores):
    record_min = scores[0]
    updateRecordMin = 0
    record_max = scores[0]
    updateRecordMax = 0
    
    for s in scores[1:]:
        if s < record_min:
            record_min = s
            updateRecordMin += 1
        if s > record_max:
            record_max = s
            updateRecordMax += 1
    
    return ( updateRecordMax, updateRecordMin )


input_values = [ [10, 5, 20, 20, 4, 5, 2, 25, 1], [3, 4, 21, 36, 10, 28, 35, 5, 24, 42], ]
input_checks = [ [2, 4], [4, 0], ]
assert (len(input_values) == len(input_checks))


for (scores, check) in zip(input_values, input_checks):
    print("scores=(%s)" % scores)
    check = tuple(check)
    result = breakingRecords(scores)
    print("result=(%s)" % str(result))
    assert (result == check), "Check comparison failed"
    print()


