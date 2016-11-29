import random
import string

def randomstring(n = 2):

    characters = string.ascii_letters + ' '
    return ''.join(random.choice(characters) for k in range(n))

def compareString(input , result = 'ab'):
    flag = True
    for k in range(2):
        if result[k] != input[k]:
            flag = False
    return flag

for k in range(1000):
    str = randomstring()
    if compareString(str):
        print k
        break
    else:
        print("No")