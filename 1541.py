s = input()

number = 0
afterMinus = False
ret = 0

for c in s:
    if c.isdigit():
        number = number * 10 + int(c)
    elif afterMinus:
        ret -= number
        number = 0
    else:
        ret += number
        number = 0
        if c == "-":
            afterMinus = True

if afterMinus:
    ret -= number
else:
    ret += number
print(ret)
