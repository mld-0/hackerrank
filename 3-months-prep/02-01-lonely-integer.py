#!/usr/bin/env perl
#   VIM SETTINGS: {{{3
#   vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
#   vim: set foldlevel=2 foldcolumn=2:
#   }}}1
from collections import Counter

def lonelyinteger(a):
    c = Counter(a)
    for k, v in c.items():
        if v == 1:
            return k
    return -1


input_values = [ [1], [1,1,2], [0,0,1,2,1], ];
input_checks = [ 1, 2, 2, ];
assert len(input_values) == len(input_checks)

for a, check in zip(input_values, input_checks):
    print("a=(%s)" % a)
    result = lonelyinteger(a)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

