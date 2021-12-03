
def fibonacciModified_recursive(t1, t2, n):
    memo = dict()
    memo[1] = t1
    memo[2] = t2
    def fib(n):
        if n in memo:
            return memo[n]
        result = fib(n-1)**2 + fib(n-2)
        memo[n] = result
        return result
    return fib(n)

def fibonacciModified_iterative(t1, t2, n):
    for i in range(3, n+1):
        t1, t2 = t2, t1 + t2**2
    return t2


if __name__ == '__main__':
    input_values = [ (0,1,5), (0,1,6), ]
    for t1, t2, n in input_values:
        result = fibonacciModified_iterative(t1, t2, n)
        check = fibonacciModified_recursive(t1, t2, n)
        print("result=(%s)" % result)
        print("check=(%s)" % check)
        assert result == check, "Check comparison failed"
        print()

