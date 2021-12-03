

def isBalanced(s: str) -> str:
    if len(s) % 2 != 0:
        return "NO"

    opening_bracket = { ')': '(', ']': '[', '}': '{' }
    stack = []

    for c in s:
        if c in ( '(', '[', '{' ):
            stack.append(c)
        elif c in ( ')', ']', '}' ):
            if len(stack) > 0 and stack[-1] == opening_bracket[c]:
                stack.pop()
            else:
                return "NO"

    if len(stack) > 0:
        return "NO"

    return "YES"


input_values = [ "{[()]}", "{[(])}", "{{[[(())]]}}", ]
input_checks = [ "YES", "NO", "YES", ]

for s, check in zip(input_values, input_checks):
    print("s=(%s)" % s)
    result = isBalanced(s)
    print("result=(%s)" % result)
    assert result == check, "Check comparison failed"
    print()

