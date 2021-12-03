
def count_substring(string, sub_string):

    seen = set()
    for i in range(0, len(string)):
        index = string.find(sub_string, i)
        if index != -1:
            seen.add(index)

    return len(seen)

if __name__ == '__main__':
    input_values = [ ("ABCDCDC", "CDC"), ("ininini", "ini"), ]
    input_checks = [ 2, 3, ]
    for (string, sub_string), check in zip(input_values, input_checks):
        result = count_substring(string, sub_string)
        print("result=(%s)" % result)
        print("check=(%s)" % check)
        assert result == check, "Check comparison failed"
    print()

