import math

def chiefHopper(arr):
    table = [ 0 ]

    for x in arr[::-1]:
        E = (table[-1] + x) / 2
        table.append(E)

    table[:] = table[::-1]

    return math.ceil(max(table))



input_values = [ [2,3,4,3,2], [3,4,3,2,4], [4,4,4], ]
input_checks = [ 3, 4, 4, ]

for arr, check in zip(input_values, input_checks):
    print("arr=(%s)" % arr)
    result = chiefHopper(arr)
    print("result=(%s)" % result)
    assert result == check, "Check comparison failed"
    print()

