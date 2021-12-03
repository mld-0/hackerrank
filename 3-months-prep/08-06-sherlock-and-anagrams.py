from collections import Counter

def sherlockAndAnagrams(s):
    result = []
    for i in range(0, len(s)):
        for L in range(1, len(s)):
            a = s[i:i+L]
            for j in range(i+1, len(s)-L+1):
                b = s[j:j+L]
                if Counter(a) == Counter(b):
                    result.append( (a,b) )
                
    #print()
    return len(result)



input_values = [ "abba", "abcd", "ifailuhkqq", "kkkk", "cdcd", ]
input_checks = [ 4, 0, 3, 10, 5, ]

for s, check in zip(input_values, input_checks):
    print("s=(%s)" % s)
    result = sherlockAndAnagrams(s)
    print("result=(%s)" % result)
    assert result == check, "Check comparison failed"
    print()

