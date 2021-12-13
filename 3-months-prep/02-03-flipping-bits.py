
def flippingBits_i(n: int) -> int:
    A = 0xFFFFFFFF
    return n ^ A

def flippingBits_ii(n: int) -> int:
    A = 2 ** 32 - 1
    return n ^ A


test_functions = [ flippingBits_i, flippingBits_ii, ]

input_values = [ [2147483647, 1, 0], [4,123456], [0,802743475,35601423], ];
input_checks = [ [2147483648, 4294967294, 4294967295], [4294967291, 4294843839], [4294967295,3492223820,4259365872], ];
assert (len(input_values) == len(input_checks))

for test_func in test_functions:
    print(test_func.__name__)
    for (values, checks) in zip(input_values, input_checks):
        assert (len(values) == len(checks))
        for n, check in zip(values, checks):
            print("n=(%s)" % n)
            result = test_func(n)
            print("result=(%s)" % result)
            assert (result == check), "Check comparison failed"
    print()

