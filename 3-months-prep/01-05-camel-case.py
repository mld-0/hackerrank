
def inputLineSplit(kind: chr, s: str) -> str:
    #   remove trailing parenthesis from method
    if kind == 'M':
        s = s[:-2]
    #   split camel case words into list, de-capitalizing
    words = []
    loop_word = s[0].lower()
    for x in s[1:]:
        #   begin new word upon uppercase letter
        if x.isupper():
            words.append(loop_word)
            loop_word = x.lower()
        else:
            loop_word += x
    words.append(loop_word)
    #   combine words as sentence 
    result = ' '.join(words)
    return result

    
def inputLineCombine(kind: chr, s: str) -> str:
    #   split words into list
    words = s.split(' ')
    #   capitalize first letter of each word, only including the first for classes
    if kind == 'C':
        words[0] = words[0][0].upper() + words[0][1:]
    for i in range(1, len(words)):
        words[i] = words[i][0].upper() + words[i][1:]
    #   combine as a single word
    result = ''.join(words)
    #   append braces for methods
    if kind == 'M':
        result = result + "()"
    return result


input_values = [ "S;V;iPad\nC;M;mouse pad\nC;C;code swarm\nS;C;OrangeHighlighter\n", "C;V;can of coke\nS;M;sweatTea()\nS;V;epsonPrinter\nC;M;santa claus\nC;C;mirror\n", ]
input_checks = [ "i pad\nmousePad()\nCodeSwarm\norange highlighter\n", "canOfCoke\nsweat tea\nepson printer\nsantaClaus()\nMirror\n", ]
assert (len(input_values) == len(input_checks))

for (lines, checks) in zip(input_values, input_checks):
    lines = lines.rstrip().split('\n')
    checks = checks.rstrip().split('\n')
    assert (len(lines) == len(checks))
    for (line, check) in zip(lines, checks):
        print("line=(%s)" % line)
        op, kind, s = line.split(';')
        result = None
        if op == 'S':
            result = inputLineSplit(kind, s)
        else:
            result = inputLineCombine(kind, s)
        print("result=(%s)" % result)
        assert (result == check)
    print()

