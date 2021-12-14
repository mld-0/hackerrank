
def caesarCipher(s: str, k: int) -> str:
    result = ""
    for x in s:
        if x.isalpha():
            x_code = ord(x) + k
            if x.isupper():
                while x_code > ord('Z'):
                    x_code -= 26
            elif x.islower():
                while x_code > ord('z'):
                    x_code -= 26
            x = chr(x_code)
        result += x
    return result


input_values = [ ["middle-Outz", 2], ["Always-Look-on-the-Bright-Side-of-Life", 5], ]
input_checks = [ "okffng-Qwvb", "Fqbfdx-Qttp-ts-ymj-Gwnlmy-Xnij-tk-Qnkj", ]

for (s, k), check in zip(input_values, input_checks):
    print("s=(%s), k=(%s)" % (s, k))
    result = caesarCipher(s, k)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

