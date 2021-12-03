

#   Ongoing: 2021-11-13T21:36:05AEDT _hackerrank, 06-test-palindrome-index, solution is still failing 2/15 tests?

def isPalindrome(s):
    return s == s[::-1]

def palindromeIndex(s):
    #   For each pair, starting at beginning/end and progressing inwards, identify first pair which do not match
    l = 0
    r = len(s) - 1
    while l < r and s[l] == s[r]:
        l += 1
        r -= 1

    #   no mismatch pairs found
    if l >= r:
        return -1

    #   If removing r produces a palindrome, return r
    if isPalindrome(s[l:r]):
        return r

    #   If removing l produces a palindrome, return l
    if isPalindrome(s[l+1:r+1]):
        return l

    #   Cannot produce palindrome by removing l or r
    return -1


input_values = [ "aaab", "baa", "aaa",  "quyjjdcgsvvsgcdjjyq", "hgygsvlfwcwnswtuhmyaljkqlqjjqlqkjlaymhutwsnwcflvsgygh", ]
input_checks = [ 3, 0, -1, 1, 8, ]

for s, check in zip(input_values, input_checks):
    print("s=(%s)" % s)
    result = palindromeIndex(s)
    print("result=(%s)" % result)
    assert result == check, "Check comparison failed"
    print()

