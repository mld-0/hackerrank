import pprint
import math

def remove_all_but_two(s: str, c1: str, c2: str) -> str:
    assert len(c1) == 1, "c1 must be 1 char"
    assert len(c2) == 1, "c2 must be 1 char"
    result = ""
    for c in s:
        if c == c1 or c == c2:
            result += c
    return result


def is_alternating(s: str) -> bool:
    if len(s) < 2:
        return False
    first = s[0]
    second = s[1]
    for i in range(len(s)):
        if i % 2 == 0 and s[i] != first:
            return False
        if i % 2 != 0 and s[i] != second:
            return False
    return True


def alternate(s: str) -> int:
    longest_valid = ""

    letters = list(set(s))

    for i in range(len(letters)):
        for j in range(len(letters)):

            if i == j:
                continue

            remainder = remove_all_but_two(s, letters[i], letters[j])
            is_valid = is_alternating(remainder)

            if is_valid and len(remainder) > len(longest_valid):
                longest_valid = remainder

    return len(longest_valid)


input_values = [ "abaacdabd", "beabeefeab", "asvkugfiugsalddlasguifgukvsa", ]
input_checks = [ 4, 5, 0, ]

for s, check in zip(input_values, input_checks):
    print("s=(%s)" % s)
    result = alternate(s)
    print("result=(%s)" % result)
    assert result == check, "Check comparison failed"
    print()

