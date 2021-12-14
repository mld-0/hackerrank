from contextlib import redirect_stdout
import io
from typing import List

def countSort(arr: List[int]):
    for i in range(len(arr)//2):
        arr[i][1] = '-' 
    arr = sorted(arr, key=lambda x: int(x[0]))
    for c, x in arr:
        print(x, end=' ')


input_values = [ [[1,"e"], [2,"a"], [1,"b"], [3,"a"], [4,"f"], [1,"f"], [2,"a"], [1,"e"], [1,"b"], [1,"c"]], [[0,"ab"], [6,"cd"], [0,"ef"], [6,"gh"], [4,"ij"], [0,"ab"], [6,"cd"], [0,"ef"], [6,"gh"], [0,"ij"], [4,"that"], [3,"be"], [0,"to"], [1,"be"], [5,"question"], [1,"or"], [2,"not"], [4,"is"], [2,"to"], [4,"the"]], ]
input_checks = [ "- - f e b c - a - -", "- - - - - to be or not to be - that is the question - - - -", ]
assert (len(input_values) == len(input_checks))

for arr, check in zip(input_values, input_checks):
    print("arr=(%s)" % arr)
    ss = io.StringIO()
    with redirect_stdout(ss):
        countSort(arr)
    result = ss.getvalue().rstrip()
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

