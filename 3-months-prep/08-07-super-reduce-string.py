import re

def reduceString(s):
    return re.sub(r'([a-z])\1', r'\1', s,)


result = reduceString("aaabccddd")
print(result)

