S = ")()"


def solution(S):

    if S.__len__() == 0:
        return 0
    i = 0
    j = S.__len__()
    left_probe = i
    right_probe = j - 1

    while True:
        while (left_probe < S.__len__() - 1) & (S[left_probe] != '('):
            left_probe = left_probe + 1
        while  (right_probe > 0) & (S[right_probe] != ')'):
            right_probe = right_probe - 1
        if left_probe >= right_probe:
            break
        i = left_probe
        j = right_probe
        left_probe = left_probe + 1
        right_probe = right_probe - 1

    if i + 1 >= S.__len__():
        return i + 1

    while (S[i+1] != '(') & (i + 1 < j):
        i = i + 1
        if i + 1 >= S.__len__():
            break

    return i + 1




num = solution(S)
print num

