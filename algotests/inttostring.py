def itoa(value, retstring, base) :
    cstring = ""
    cbase = base
    while value > 0:
        cstring += chr(int((value % cbase) / (cbase/base) + 48))
        value -= value % cbase
        cbase *= base
    fstring = ""
    for c in cstring:
        fstring += c
    return fstring


print(itoa(65, "", 2))
print(itoa(1234567, "", 10))