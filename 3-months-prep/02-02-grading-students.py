#!/usr/bin/env perl
#   VIM SETTINGS: {{{3
#   vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
#   vim: set foldlevel=2 foldcolumn=2:
#   }}}1
from collections import Counter

def roundGrade(grade):
    if grade < 38:
        return grade
    nearest_multiple_5 = grade
    while nearest_multiple_5 % 5 != 0:
        nearest_multiple_5 += 1
    if nearest_multiple_5 - grade < 3:
        return nearest_multiple_5
    else:
        return grade
    

def gradingStudents(grades):
    result = [ roundGrade(x) for x in grades ]
    return result


input_values = [ [73, 67, 38, 33], [37, 38], [80, 96, 18, 73, 78, 60, 60, 15, 45, 15, 10, 5, 46, 87, 33, 60, 14, 71, 65, 2, 5, 97, 0], ];
input_checks = [ [75, 67, 40, 33], [37, 40], [80, 96, 18, 75, 80, 60, 60, 15, 45, 15, 10, 5, 46, 87, 33, 60, 14, 71, 65, 2, 5, 97, 0], ];
assert (len(input_values) == len(input_checks)), "Check comparison failed"

for (grades, check) in zip(input_values, input_checks):
    print("grades=(%s)" % grades)
    result = gradingStudents(grades)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

