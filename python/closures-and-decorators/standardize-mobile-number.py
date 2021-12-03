
def wrapper(f):
    def fun(l):
        transformed = [ "+91 " + num[::-1][:10][::-1][:5] + " " + num[::-1][:10][::-1][5:] for num in l ]
        f(transformed)
    return fun

@wrapper
def sort_phone(l):
    print(*sorted(l), sep='\n')

sort_phone_wrapped = wrapper(sort_phone)

if __name__ == '__main__':
    l = [ "07895462130", "919875641230", "9195969878", ]
    sort_phone(l)
    print()
    sort_phone_wrapped(l)
    print()

