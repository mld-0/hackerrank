
def subarray_difference_valid(values, n):
    values_set = set(values)
    values_set_list = list(values_set)
    if len(values_set_list) > 1 and abs(values_set_list[0]-values_set_list[1]) > n:
        return False
    if len(values_set) > n+1:
        return False
    return True

def pickingNumbers(a):
    a = sorted(a)
    result = []
    for k in range(1, len(a)):
        for l in range(0, len(a)-k):
            r = l + k
            sub = a[l:r+1]
            if subarray_difference_valid(sub, 1):
                if len(sub) > len(result):
                    result = sub
    print(result)
    return len(result)

#values = 

input_values = [ [4, 6, 5, 3, 3, 1,], [98, 3, 99, 1, 97, 2,], [4, 2, 3, 4, 4, 9, 98, 98, 3, 3, 3, 4, 2, 98, 1, 98, 98, 1, 1, 4, 98, 2, 98, 3, 9, 9, 3, 1, 4, 1, 98, 9, 9, 2, 9, 4, 2, 2, 9, 98, 4, 98, 1, 3, 4, 9, 1, 98, 98, 4, 2, 3, 98, 98, 1, 99, 9, 98, 98, 3, 98, 98, 4, 98, 2, 98, 4, 2, 1, 1, 9, 2, 4,], ]
input_checks = [ 3, 2, 22, ]

for values, check in zip(input_values, input_checks):
    result = pickingNumbers(values)
    print(result)
    assert result == check
    print()

