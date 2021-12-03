#!/usr/bin/env python3
import math
import os
import random
import re
import sys
import io

def check_valid(number: str, trailing: str):
    if len(trailing) == 0:
        return True
    next_number = int(number) + 1
    if not trailing.startswith(str(next_number)):
        return False
    next_trailing = trailing[len(str(next_number)):]
    return check_valid(next_number, next_trailing)

def seperateNumbers(s: str):
    for k in range(1, len(s)-1):
        leading = s[:k]
        trailing = s[k:]
        if check_valid(leading, trailing):
            print("YES %i" % int(leading))
            return
    print("NO")


if __name__ == '__main__':
    _stdout = sys.stdout
    sys.stdout = io.TextIOWrapper(io.BytesIO(), sys.stdout.encoding)

    input_values = [ "1234", "91011", "99100", "101103", "010203", "13", "1", ]
    expected_output = "YES 1\nYES 9\nYES 99\nNO\nNO\nNO\nNO\n"
    for value in input_values:
        seperateNumbers(value)

    sys.stdout.seek(0)
    result = sys.stdout.read()
    sys.stdout.close()
    sys.stdout = _stdout

    print("result=(%s)" % result)
    assert result == expected_output, "Check comparison failed"
    
