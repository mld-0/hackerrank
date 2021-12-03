import re

s = '__commit__'
m = re.search(r'([a-zA-Z0-9])\1+', s)
if m is not None:
    print(m.groups()[0])
else:
    print(-1)

