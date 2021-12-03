import math

def get_primes_list(n):
    z = n * n + 2
    sieve = [ True for i in range(z+1) ]
    p = 2
    while p <= math.sqrt(z):
        if sieve[p]:
            for i in range(p*p, z+1, p):
                sieve[i] = False
        p += 1
    primes = [ None, ]
    for i in range(2, z+1):
        if sieve[i]:
            primes.append(i)
    return primes


def waiter(number, q):
    answers = []
    A = [ number[:], ]
    B = [ [], ]
    primes_list = get_primes_list(q)
    i = 1
    while i <= q:
        A.append([])
        B.append([])
        nthPrime = primes_list[i]
        while len(A[-2]) > 0:
            temp = A[-2].pop()
            if temp % nthPrime == 0:
                B[-1].append(temp)
            else:
                A[-1].append(temp)
        while len(B[-1]) > 0:
            temp = B[-1].pop()
            answers.append(temp)
        i += 1
    while len(A[-1]) > 0:
        temp = A[-1].pop()
        answers.append(temp)
    return answers



input_values = [ ("3 4 7 6 5", 1), ("3 3 4 4 9", 2), ]
input_checks = [ "4 6 3 7 5", "4 4 9 3 3", ]

for (numbers_str, q), check_str in zip(input_values, input_checks):
    numbers = list(map(int, numbers_str.split()))
    check = list(map(int, check_str.split()))
    print("numbers=(%s), q=(%s)" % (numbers, q))
    result = waiter(numbers, q)
    print("result=(%s)" % result)
    assert result == check, "Check comparison failed"
    print()

