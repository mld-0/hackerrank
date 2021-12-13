
def timeConversion(s: str) -> str:
    time_period = s[-2:]
    time_H = int(s[0:2])
    time_M = int(s[3:5])
    time_S = int(s[6:8])
    if time_period == "PM" and time_H != 12:
        time_H = time_H + 12
    elif time_period == "AM" and time_H == 12:
        time_H = 0
    result = "%02i:%02i:%02i" % (time_H, time_M, time_S)
    return result


input_values = [ "07:05:45PM", "12:40:22AM", "06:40:03AM", "12:05:39AM", ]
input_checks = [ "19:05:45", "00:40:22", "06:40:03", "00:05:39", ]
assert (len(input_values) == len(input_checks))

for (s, check) in zip(input_values, input_checks):
    print("s=(%s)" % s)
    result = timeConversion(s)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

