import re

input_str = """# i#
 @#U"""

#input_str = """Tsi
#h%x
#i #
#sM 
#$a 
##t%
#ir!"""

matrix = []

#for _ in range(n):
for line in input_str.split('\n'):
    matrix_item = line
    matrix.append(matrix_item)
    
words = ''.join([ ''.join(x) for x in list(zip(*matrix)) ])
words = re.sub('(?<=[A-Za-z0-9])[^A-Za-z0-9]+(?=[A-Za-z0-9])', ' ', words)
print(words)

