import random
import itertools
from copy import deepcopy


#This function is used to make a board
def make_board(m=3):
    numbers = list(range(1, m**2 + 1))
    board = None

    while board is None:
        board = attempt_board(m, numbers)
    return board


#This function is used to generate a full board
def attempt_board(m,numbers):
    n = m ** 2

    board = [[None for _ in range(n)] for _ in range(n)]
    for i, j in itertools.product(range(n), repeat=2):
        i0, j0 = i - i % m, j - j % m    #origin of m * m block
        random.shuffle(numbers)
        for x in numbers:
            if (x not in board[i]                    #row
                and all(row[j] != x for row in board)#column
                and all(x not in row[j0:j0+m]
                        for row in board[i0:i])):
                board[i][j] = x
                break
        else:
            return None
    return board


#This function is used to print the whole Soduku out
def print_board(board,m = 3):
    numbers = list(range(1, m**2 + 1))
    omit = 5
    challange = deepcopy(board)
    for i, j in itertools.product(range(omit), range(m ** 2)):
        x = random.choice(numbers) - 1
        challange[x][j] = None

    spacer = "++-----+-----+-----++-----+-----+-----++-----+-----+-----++"
    print (spacer.replace('-','='))
    for i, line in enumerate(challange):
        print("||  {}  |  {}  |  {}  ||  {}  |  {}  |  {}  ||  {}  |  {}  |  {}  ||"
              .format(*(cell or ' ' for cell in line)))
        if (i + 1) % 3 == 0: print(spacer.replace('-', '='))
        else: print(spacer)
    return challange


def print_answers(board):
    spacer = "++-----+-----+-----++-----+-----+-----++-----+-----+-----++"
    print (spacer.replace('-','='))
    for i, line in enumerate(board):
        print("||  {}  |  {}  |  {}  ||  {}  |  {}  |  {}  ||  {}  |  {}  |  {}  ||"
              .format(*(cell or ' ' for cell in line)))
        if (i + 1) % 3 == 0: print(spacer.replace('-', '='))
        else: print(spacer)


def solving_soduku(challange, m=3):
    if is_full(challange):
        return challange
    test = deepcopy(challange)
    least, x, y = least_candidate(challange)
    id = x * (m**2) + y
    result = try_candidate(challange,id)
    return result


def try_candidate(challange, id, m=3):
    if is_full(challange):
        return challange
    x = id / (m**2)
    y = id % (m**2)
    while challange[x][y]:
        id = (id + 1) % m**4
        x = id / (m ** 2)
        y = id % (m ** 2)
    candidate = cal_candidate(challange, x, y)

    if len(candidate) == 0:
        return False
    for i in range(len(candidate)):
        challange[x][y] = candidate[i]
        result_r = try_candidate(challange, (id + 1) % m ** 4)
        if not result_r:
            challange[x][y] = None
        else:
            return challange
    challange[x][y] = None
    return False


def cal_candidate(challange, x, y, m = 3):

    candidate = range(1, m ** 2 + 1)
    for i in range(m**2):
        if challange[x][i] in candidate:
            candidate.remove(challange[x][i])
        if challange[i][y] in candidate:
            candidate.remove(challange[i][y])

    for i,j in itertools.product(range(m), repeat=2):
        x0, y0 = x - x % m, y - y % m
        if challange[x0+i][y0+j] in candidate:
            candidate.remove(challange[x0+i][y0+j])
    return candidate


def least_candidate(challange, m=3):
    least, x, y = m ** 2, -1, -1
    for i, j in itertools.product(range(m**2), repeat=2):
        if not challange[i][j]:
            num = len(cal_candidate(challange, i, j))
            if num < least:
                least = num
                x, y = i, j
    return least, x, y


def is_full(challange, m = 3):
    for i, j in itertools.product(range(m**2), repeat = 2):
        if challange[i][j] is None:
            return False
    return True

Board = make_board()
challange = print_board(Board)
'''
testing = [[8,9,None,3,None,4,None,6,None],
           [None,None,2,9,1,5,3,None,8],
           [5, None,None,None,8,7,None,2,None],
           [None,8,9,None,3,6,None,None,None],
           [4,1,None,5,None,2,8,7,3],
           [3,None,5,None,None,None,6,None,None],
           [9,4,3,None,7,1,None,None,6],
           [None,5,8,4,None,None,9,1,7],
           [None,None,None,None,5,None,2,None,4]]
'''

print("Raw Answer: ")
print_answers(test)
print("Calculated from your program: ")
result = solving_soduku(challange)
print_answers(result)





