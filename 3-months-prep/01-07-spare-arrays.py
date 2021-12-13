from collections import Counter
from typing import List

def matchingStrings(strings: List[str], queries: List[str]):
    strings_counter = Counter(strings)
    result = [ strings_counter[x] for x in queries ]
    return result


input_values = [ "4\naba\nbaba\naba\nxzxb\n3\naba\nxzxb\nab\n", "3\ndef\nde\nfgh\n3\nde\nlmn\nfgh", "13\nabcde\nsdaklfj\nasdjf\nna\nbasdn\nsdaklfj\nasdjf\nna\nasdjf\nna\nbasdn\nsdaklfj\nasdjf\n5\nabcde\nsdaklfj\nasdjf\nna\nbasdn\n", ]
input_checks = [ "2\n1\n0\n", "1\n0\n1\n", "1\n3\n4\n3\n2\n", ]
assert (len(input_values) == len(input_checks))


for (values, checks) in zip(input_values, input_checks):
    values_split = values.rstrip().split('\n')
    strings_count = int(values_split[0])
    strings = values_split[1:strings_count+1]
    queries_count = int(values_split[strings_count+1])
    queries = values_split[strings_count+2:strings_count+queries_count+2]
    check = list(map(int, checks.rstrip().split('\n')))

    print("strings_count=(%s)" % strings_count)
    print("strings=(%s)" % strings)
    print("queries_count=(%s)" % queries_count)
    print("queries=(%s)" % queries)

    result = matchingStrings(strings, queries)
    print("result=(%s)" % result)

    assert (result == check), "Check comparison failed"
    print()

