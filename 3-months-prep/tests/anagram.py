from collections import Counter

def anagram(s):
    if len(s) % 2 != 0:
        return -1
    a_str = s[:len(s)//2]
    b_str = s[len(s)//2:]
    a = Counter(a_str)
    b = Counter(b_str)
    print("a=(%s)" % a)
    print("b=(%s)" % b)

    #   how many letters do a/b have in common
    shared_values = 0

    #   For the values the counters have in common, what are the min values
    #ab_intersection = Counter()
    #for k in (a.keys() & b.keys()):
    #    ab_intersection[k] = min(a[k], b[k])
    #    shared_values += ab_intersection[k]

    #   alternatively:
    ab_intersection = a & b
    for k, v in ab_intersection.items():
        shared_values += v

    print("ab_intersection=(%s)" % ab_intersection)
    return len(a_str) - shared_values


if __name__ == '__main__':
    input_values = [ "asdfjoieufoa", "fdhlvosfpafhalll", "mvdalvkiopaufl", ]
    input_checks = [ 3, 5, 5, ]
    for value, check in zip(input_values, input_checks):
        result = anagram(value)
        print("result=(%s)" % result)
        assert result == check, "Check comparison failed"
        print()

