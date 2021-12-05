


def allUCSWeights(s):
    l = 0
    r = 0
    result = set()
    while l < len(s):
        r = l
        while r < len(s) and s[l] == s[r]:
            loop_substr = s[l:r+1]
            loop_code = (ord(loop_substr[0]) - ord('a') + 1) * len(loop_substr)
            result.add(loop_code)
            r += 1
        l = r
    return result

def weightedUniformStrings_ii(s, queries):
    all_weights = allUCSWeights(s)
    result = []
    for x in queries:
        if x in all_weights:
            result.append('Yes')
        else:
            result.append('No')
    return result



input_values = [ ('abbcccdddd', [1,7,5,4,15]), ('aaabbbbcccddd', [9,7,8,12,5]), ('l', [1,12]) ]
input_checks = [ ['Yes', 'No', 'No', 'Yes', 'No'], ['Yes', 'No', 'Yes', 'Yes', 'No'], ['No', 'Yes'], ]

for (s, queries), check in zip(input_values, input_checks):
    print("s=(%s), queries=(%s)" % (s, queries))
    result = weightedUniformStrings_ii(s, queries)
    print("result=(%s)" % result)
    assert result == check, "Check comparison failed"
    print()

