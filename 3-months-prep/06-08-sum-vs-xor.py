
def sumXor(n: int) -> int:
    #   base case:
    if n == 0:
        return 1
    #   n as a binary number, (without leading '0b')
    n_bin = bin(n)[2:]
    #   count zeros in n
    n_bin_countzero = sum( [ 1 if x == '0' else 0 for x in n_bin ] )
    #   solution is given by:
    return 2 ** n_bin_countzero


input_values = [ 5, 10, ]
input_checks = [ 2, 4, ]
assert (len(input_values) == len(input_checks))

for n, check in zip(input_values, input_checks):
    print("n=(%s)" % n)
    result = sumXor(n)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

