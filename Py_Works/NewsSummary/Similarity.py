import sys
from nltk.tokenize import sent_tokenize, word_tokenize
from nltk.corpus import stopwords
import math
from itertools import product, count
from string import punctuation
from heapq import nlargest
import pymysql

stopwords = set(stopwords.words('english') + list(punctuation))


def flattern_text(a):
    with open("test2_%s.txt" % a, "r") as myfile:
        text = myfile.read().replace('\n', '')
    sents = sent_tokenize(text)

    word_sent = [word_tokenize(s.lower()) for s in sents]

    # 把停用词去除
    for i in range(len(word_sent)):
        for word in word_sent[i]:
            if word in stopwords:
                word_sent[i].remove(word)
    words = []
    for i in range(len(word_sent)):
        for word in word_sent[i]:
            words.append(word)
    return words

def calculate_similarity(sen1, sen2):

    counter = 0
    for word in sen1:
        if word in sen2:
            counter += 1
    return counter / (math.log(len(sen1)) + math.log(len(sen2)))


def creat_similarity_graph(a0, a1, a2, a3):

    board = [[0.0 for _ in range(30)] for _ in range(4)]
    top_score0 = flattern_text(a0)
    top_score1 = flattern_text(a1)
    top_score2 = flattern_text(a2)
    top_score3 = flattern_text(a3)


    '''
    如果想要改变一开始推荐的新闻数量
    请修改上下的数值30
    '''

    for i in range(30):
        textofwords = flattern_text(i)

        board[0][i] = calculate_similarity(top_score0, textofwords)
        board[1][i] = calculate_similarity(top_score1, textofwords)
        board[2][i] = calculate_similarity(top_score2, textofwords)
        board[3][i] = calculate_similarity(top_score3, textofwords)

    return board


def get_the_scores(board, s0, s1, s2, s3):
    for i in range(len(board[0])):
        board[0][i] = board[0][i] * s0
    for i in range(len(board[0])):
        board[1][i] = board[0][i] * s1
    for i in range(len(board[0])):
        board[2][i] = board[0][i] * s2
    for i in range(len(board[0])):
        board[3][i] = board[0][i] * s3

    scores = [0.0 for x in range(30)]

    for i in range(30):
        scores[i] = board[0][i] + board[1][i] + board[2][i] + board[3][i]

    return scores


# print ('Number of arguments:', len(sys.argv), 'arguments.')
# print ('Argument List:', str(sys.argv))

if __name__ == '__main__':
    board = creat_similarity_graph(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]), int(sys.argv[4]))
    scores = get_the_scores(board, int(sys.argv[5]), int(sys.argv[6]), int(sys.argv[7]), int(sys.argv[8]))
    sent_selected = nlargest(10, zip(scores, count()))
    sent_index = []

    for i in range(10):
        sent_index.append(sent_selected[i][1])
    print(sent_index)
