import io
from contextlib import redirect_stdout

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


input_values = [ "1234", "91011", "99100", "101103", "010203", "13", "1", ]
input_checks = [ "YES 1", "YES 9", "YES 99", "NO", "NO", "NO", "NO", ]

for s, check in zip(input_values, input_checks):
    print("s=(%s)" % s)

    ss = io.StringIO()
    with redirect_stdout(ss):
        seperateNumbers(s)
    result = ss.getvalue().rstrip()

    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

