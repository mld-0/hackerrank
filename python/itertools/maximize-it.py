
import itertools

def f(values, m):
    S = sum( [ x**2 for x in values ] ) % m
    return S 

k, m = 3, 1000
input_str = """2 5 4
3 7 8 9 
5 5 7 8 9 10 """

k, m = 6, 767
input_str = """2 488512261 423332742
2 625040505 443232774
1 4553600
4 92134264 617699202 124100179 337650738
2 778493847 932097163
5 489894997 496724555 693361712 935903331 518538304"""

input_lists = []
for loop_str in input_str.split('\n'):
    temp = [ int(x) for x in loop_str.split() ][1:]
    input_lists.append(temp)

products = list(itertools.product(*input_lists))
#results = map(lambda x: sum(i**2 for i in x)%m, products)
results = [ f(x,m) for x in products ]
result = max(results)
#print(results)
print(result)

