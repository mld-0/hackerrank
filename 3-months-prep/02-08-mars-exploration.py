
def marsExploration(s: str) -> int:
    result = 0
    expected = "SOS" * (len(s) // 3)
    assert len(s) == len(expected), "Invalid length message"
    for c, x in zip(s, expected):
        if c != x:
            result += 1
    return result


input_values = [ "SOSSPSSQSSOR", "SOSSOT", "SOSSOSSOS", ]
input_checks = [ 3, 1, 0, ]


for (s, check) in zip(input_values, input_checks):
    print("s=(%s)" % s)
    result = marsExploration(s)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

