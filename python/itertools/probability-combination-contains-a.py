
import itertools

n = 4
a = "a a c d".split()
k = 2

n = 10
a = "a a a a a a a a a a".split()
k = 10

combinations = list(itertools.combinations(a, k))

contains_a = [ 1 if 'a' in x else 0 for x in combinations ]

result = sum(contains_a) / len(combinations)

print(combinations)
print(contains_a)

print(result)


