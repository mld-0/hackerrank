
def kangaroo(x1: int, v1: int, x2: int, v2: int) -> str:
    #   y1 = x1 + v1*t and y2 = x2 + v2*t, let y1 = y2:
    #   t = (x1 - x2) / (v2 - v1) 
    if x1 == x2 and v1 == v2:
        return "YES"
    if v2 - v1 != 0 and (x1 - x2) / (v2 - v1) > 0 and int((x1-x2)/(v2-v1)) == (x1-x2)/(v2-v1):
        return "YES"
    return "NO"


input_values = [ [0,3,4,2], [0,2,5,3], [14,4,98,2], [21,6,47,3], [28,8,96,2], ]
input_checks = [ "YES", "NO", "YES", "NO", "NO", ]
assert (len(input_values) == len(input_checks))

for (x1, v1, x2, v2), check in zip(input_values, input_checks):
    print("x1=(%s), v1=(%s), x2=(%s), v2=(%s)" % (x1, v1, x2, v2))
    result = kangaroo(x1, v1, x2, v2)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

