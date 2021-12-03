from collections import deque
import time


def truckTour_i(petrolpumps):
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
            print("(qty, dist)=(%s, %s)" % (qty, dist))
            total_qty += qty
            if total_qty < dist:
                return False
            total_qty -= dist
            i += 1
            if i >= len(petrolpumps):
                i -= len(petrolpumps)
        return True

    for i in range(0, len(petrolpumps)):
        if isValid(petrolpumps, i):
            return i
    return -1


#   Ongoing: 2021-12-03T21:45:33AEDT is truckTour_ii actually appreciably faster than truckTour_i? -> not for a very small input / as determined by (difference in) time.time()? -> same number of loop iterations? (number of times each petrolpumps[i]=(qty, dist) visited?)
def truckTour_ii(petrolpumps):
    N = len(petrolpumps)
    start_index = 0
    total_qty = 0
    petrolpumps = deque(petrolpumps)

    for i in range(N):
        qty, dist = petrolpumps.popleft()
        print("(qty, dist)=(%s, %s)" % (qty, dist))
        total_qty += qty

        if total_qty >= dist:
            total_qty -= dist 
        else:
            total_qty = 0
            start_index = i + 1

        petrolpumps.append( (qty, dist) )

    return start_index



#   petrolpumps: [ [(qty, distance), ...] ]
input_values = [ [(1,5), (10,3), (3,4)], ]
input_checks = [ 1, ]

for petrolpumps, check in zip(input_values, input_checks):
    print("petrolpumps=(%s)" % petrolpumps)
    time_start = time.time()
    #result = truckTour_ii(petrolpumps)
    result = truckTour_i(petrolpumps)
    time_end = time.time()
    time_delta = time_end - time_start
    print("result=(%s)" % result)
    print("time_delta=(%s)" % time_delta)
    assert result == check, "Check comparison failed"
    print()

