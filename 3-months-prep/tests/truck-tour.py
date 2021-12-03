

#   Ongoing: 2021-12-03T21:14:27AEDT storing/reusing calculations from previous call to isValid() -> O(n) solution (this being O(n**2)?)
#   must travel from petrolpumps[a] -> petrolpumps[n] -> petrolpumps[a-1], (clockwise)?
def isValid(petrolpumps, start_index):
    """Determine whether the end can be reached, without running out of fuel, starting from a given index, moving to increasing indexes (then wrapping back to the beginning), adding fuel 'qty' and subtracting fuel 'dist' at each stage"""
    total_qty = 0
    i = start_index
    end_index = start_index - 1
    if end_index < 0:
        end_index += len(petrolpumps)
    while i != end_index:
        qty, dist = petrolpumps[i]
        total_qty += qty
        if total_qty < dist:
            return False
        total_qty -= dist
        i += 1
        if i >= len(petrolpumps):
            i -= len(petrolpumps)
    return True


def truckTour(petrolpumps):
    for i in range(0, len(petrolpumps)):
        if isValid(petrolpumps, i):
            return i
    return -1



#   petrolpumps: [ [(qty, distance), ...] ]
input_values = [ [(1,5), (10,3), (3,4)], ]
input_checks = [ 1, ]

for petrolpumps, check in zip(input_values, input_checks):
    print("petrolpumps=(%s)" % petrolpumps)
    result = truckTour(petrolpumps)
    print("result=(%s)" % result)
    assert result == check, "Check comparison failed"
    print()

