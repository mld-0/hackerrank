
def countingValleys(steps: int, path: str) -> int:
    count_valleys = 0
    current_height = 0
    for x in path:
        previous_height = current_height
        if x == 'D':
            current_height -= 1
        elif x == 'U':
            current_height += 1
        if previous_height == 0 and current_height < 0:
            count_valleys += 1
    return count_valleys


input_values = [ [8,"UDDDUDUU"], [12,"DDUUDDUDUUUD"], ]
input_checks = [ 1, 2, ]
assert (len(input_values) == len(input_checks))

for ((steps, path), check) in zip(input_values, input_checks):
    print("steps=(%s), path=(%s)" % (steps, path))
    result = countingValleys(steps, path)
    print("result=(%s)" % result)
    assert (result == check)
    print()

