from collections import Counter


def isValid(s):
    #   s_counts[letter] = count-value
    s_counts = Counter(s)
    #   s_counts_counts[count-value] = frequency-of-count-value
    s_counts_counts = Counter(s_counts.values())
    #   Only 1 count-value, word is valid without deletions
    if len(s_counts_counts) == 1:
        return "YES"
    #   More than 2 count-values, word is not valid with any single deletion
    if len(s_counts_counts) > 2:
        return "NO"
    #   s_counts_freq: [ (count-value, frequency-of-count-value), ]
    #   sorted by frequency-of-count-value, descending
    s_counts_freq = [ (count_value, value_frequency) for count_value, value_frequency in sorted(s_counts_counts.items(), key=lambda x: x[1], reverse=True) ]
    #   The less-frequent count-value must occur once, and it must either be 1 (letter disappears with deletion), or 1 more than value of more-frequent count (count-values become same upon deletion)
    if (s_counts_freq[0][0] == s_counts_freq[1][0] - 1 or s_counts_freq[1][0] == 1) and s_counts_freq[1][1] == 1:
        return "YES"
    else:
        return "NO"


def isValid_ii(s):
    #   @author: weilun_x
    hash={}
    for i in s:
        if i in hash:
            hash[i]+=1
        else:
            hash[i]=1
    hash2={}
    for item in hash:
        if hash[item] in hash2:
            hash2[hash[item]]+=1
        else:
            hash2[hash[item]]=1
    print("hash=(%s), hash2=(%s)" % (hash, hash2))
    if len(hash2)==1:
        return('YES')
    if len(hash2)>2:
        return('NO')
    if len(hash2)==2:
        if hash2[max(hash2)]==1 and max(hash2)-min(hash2)==1:
            return('YES')
        elif hash2[min(hash2)]==1:
            return('YES')
        else:
            return('NO')


input_values = [ "aabbc", "aabbcd", "aabbccddeefghi", "abcdefghhgfedecba", ]
input_checks = [ "YES", "NO", "NO", "YES", ]

for s, check in zip(input_values, input_checks):
    result = isValid(s)
    print("result=(%s)" % result)
    assert result == check, "Check comparison failed"
    print()

