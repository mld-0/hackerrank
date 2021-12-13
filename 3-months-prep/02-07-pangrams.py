from collections import Counter

def pangrams(s: str) -> str:
    s = s.lower()
    letters_count = Counter(s)
    for x in range(ord('a'), ord('z')+1):
        if not chr(x) in letters_count:
            return "not pangram"
    return "pangram"


input_values = [ "We promptly judged antique ivory buckles for the next prize", "We promptly judged antique ivory buckles for the prize", ]
input_checks = [ "pangram", "not pangram", ]
assert (len(input_values) == len(input_checks)), "Check comparison failed"

for (s, check) in zip(input_values, input_checks):
    print("s=(%s)" % s)
    result = pangrams(s)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

