import random, copy, sys, pygame
from pygame.locals import *

BOARDWIDTH = 7
BOARDHEIGHT = 6
assert BOARDWIDTH >= 4 and BOARDHEIGHT >= 4, 'Board must be at least 4x4.'
DIFFICULTY = 2
SPACESIZE = 50
FPS = 30
WINDOWWIDTH = 640
WINDOWHEIGHT = 480
XMARGIN = int((WINDOWWIDTH - BOARDWIDTH * SPACESIZE) / 2)
YMARGIN = int((WINDOWHEIGHT - BOARDHEIGHT * SPACESIZE) / 2)
BRIGHTBLUE = (0, 50, 255)
WHITE = (255, 255, 255)

BGCOLOR = BRIGHTBLUE
TEXTCOLOR = WHITE

RED = 'red'
BLACK = 'black'
EMPTY = None
HUMAN = 'human'
COMPUTER = 'computer'



pygame.init()
FPSCLOCK = pygame.time.Clock()
DISPLAYSURF = pygame.display.set_mode((WINDOWWIDTH, WINDOWHEIGHT))
pygame.display.set_caption('Four in a Row')
REDPILERECT = pygame.Rect(int(SPACESIZE / 2), WINDOWHEIGHT - int(3 * SPACESIZE / 2), SPACESIZE, SPACESIZE)
BLACKPILERECT = pygame.Rect(WINDOWWIDTH - int(3 * SPACESIZE / 2), WINDOWHEIGHT - int(3 * SPACESIZE / 2), SPACESIZE, SPACESIZE)
REDTOKENIMG = pygame.image.load('images/4rowred.png')
REDTOKENIMG = pygame.transform.smoothscale(REDTOKENIMG, (SPACESIZE, SPACESIZE))
BLACKTOKENIMG = pygame.image.load('images/4rowblack.png')
BLACKTOKENIMG = pygame.transform.smoothscale(BLACKTOKENIMG, (SPACESIZE, SPACESIZE))
BOARDIMG = pygame.image.load('images/4rowboard.png')
BOARDIMG = pygame.transform.smoothscale(BOARDIMG, (SPACESIZE, SPACESIZE))
HUMANWINNERIMG = pygame.image.load('images/4rowhumanwinner.png')
COMPUTERWINNERIMG = pygame.image.load('images/4rowcomputerwinner.png')
TIEWINNERIMG = pygame.image.load('images/4rowtie.png')
WINNERRECT = HUMANWINNERIMG.get_rect()
WINNERRECT.center = (int(WINDOWWIDTH / 2), int(WINDOWHEIGHT / 2))
ARROWIMG = pygame.image.load('images/4rowarrow.png')
ARROWRECT = ARROWIMG.get_rect()
ARROWRECT.left = REDPILERECT.right + 10
ARROWRECT.centery = REDPILERECT.centery


def drawBoard(board, extraToken=None):
    # DISPLAYSURF 是我们的界面，在之后会定义
    DISPLAYSURF.fill(BGCOLOR)  # 将游戏窗口背景色填充为蓝色
    spaceRect = pygame.Rect(0, 0, SPACESIZE, SPACESIZE)  # 创建Rect实例
    for x in range(BOARDWIDTH):
        # 确定每一列中每一行中的格子的左上角的位置坐标
        for y in range(BOARDHEIGHT):
            spaceRect.topleft = (XMARGIN + (x * SPACESIZE), YMARGIN + (y * SPACESIZE))

            # x =0,y =0时，即第一列第一行的格子。
            if board[x][y] == RED:  # 如果格子值为红色
                # 则在在游戏窗口的spaceRect中画红色棋子
                DISPLAYSURF.blit(REDTOKENIMG, spaceRect)
            elif board[x][y] == BLACK:  # 否则画黑色棋子
                DISPLAYSURF.blit(BLACKTOKENIMG, spaceRect)
    if extraToken != None:
        if extraToken['color'] == RED:
            DISPLAYSURF.blit(REDTOKENIMG, (extraToken['x'],
                                           extraToken['y'], SPACESIZE, SPACESIZE))
        elif extraToken['color'] == BLACK:
            DISPLAYSURF.blit(BLACKTOKENIMG, (extraToken['x'], extraToken['y'], SPACESIZE, SPACESIZE))

    # 画棋子面板
    for x in range(BOARDWIDTH):
        for y in range(BOARDHEIGHT):
            spaceRect.topleft = (XMARGIN + (x * SPACESIZE), YMARGIN + (y * SPACESIZE))
            DISPLAYSURF.blit(BOARDIMG, spaceRect)

    # 画游戏窗口中下边的棋子
    DISPLAYSURF.blit(REDTOKENIMG, REDPILERECT)  # 左边的红色棋子
    DISPLAYSURF.blit(BLACKTOKENIMG, BLACKPILERECT)  # 右边的黑色棋子


def getNewBoard():
    board = []
    for x in range(BOARDWIDTH):
        board.append([EMPTY] * BOARDHEIGHT)
    return board  # 返回board列表，其值为BOARDHEIGHT数量的None



