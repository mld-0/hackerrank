
def minimumNumber(n: int, password: str) -> int:
    """Return the minimum number of characters needed to make the password strong"""
    numbers = "0123456789"
    lower_case = "abcdefghijklmnopqrstuvwxyz"
    upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    special_characters = "!@#$%^&*()-+"

    #   length at least 6
    needed_length = 6 - n

    needs_digit = True
    needs_lower = True
    needs_upper = True
    needs_special = True

    #   at least 1 digit
    for c in numbers:
        if c in password:
            needs_digit = False
    #   at least 1 lower
    for c in lower_case:
        if c in password:
            needs_lower = False
    #   at least 1 upper
    for c in upper_case:
        if c in password:
            needs_upper = False
    #   at least 1 special
    for c in special_characters:
        if c in password:
            needs_special = False

    needed_categories = 0

    if needs_digit:
        needed_categories += 1
    if needs_lower:
        needed_categories += 1
    if needs_upper:
        needed_categories += 1
    if needs_special:
        needed_categories += 1

    result = max(needed_length, needed_categories)
    return result


input_values = [ [3,"Ab1"], [11, "#HackerRank"], [1, "9"], [1, 'z'], [1, 'A'], [3, "0H2"], [3, "a4A"], [5, "A98#+"], [100, "espUIjGnwLfHyiCqATSqBzkTOGNZTzbVCewFJrguXzjFzjChkpqZUXntPqxVAZTvkydYHYvXdVFIYxfxHwjvAFNyrJZpjBCYSCto", ], [100, "DZ*1G!#0%(73$7599@851K#208M5+0JQ-P8!*07B1YL89$31$21B(0*K0X))LFK2)Q0&X0VPT974X68@3%9Z!DUQ2LH-&3G1+9&5"], ]
input_checks = [ 3, 1, 5, 5, 5, 3, 3, 1, 2, 1, ]
assert (len(input_values) == len(input_checks))

for (n, password), check in zip(input_values, input_checks):
    print("n=(%s), password=(%s)" % (n, password))
    result = minimumNumber(n, password)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

