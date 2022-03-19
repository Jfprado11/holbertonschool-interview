#!/usr/bin/python3
"""Resolve the proble of n-queens
"""

import sys

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)

N_QUEENS = sys.argv[1]

try:
    n_queen = int(N_QUEENS)
except ValueError:
    print("N must be a number")
    sys.exit(1)

if n_queen < 4:
    print("N must be at least 4")
    sys.exit(1)


def print_solution(board):
    """prints the board as wanted
    """
    table_print = []
    for r in range(len(board)):
        for x in range(len(board[r])):
            if board[r][x] == 1:
                table_print.append([r, x])
    print(table_print)


def nq_util(board, row):
    """ checks the board and all the queens
    """
    if row == len(board):
        print_solution(board)
        return

    for i in range(len(board)):
        if is_safe(board, row, i):
            board[row][i] = 1

            nq_util(board, row + 1)

            board[row][i] = 0


def is_safe(board, row, col):
    """check that the queens dont theath each other
    """
    for i in range(row):
        if board[i][col] == 1:
            return False

    (i, j) = (row, col)
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i = i - 1
        j = j - 1

    (i, j) = (row, col)
    while i >= 0 and j < len(board):
        if board[i][j] == 1:
            return False
        i = i - 1
        j = j + 1

    return True


def queen_game():
    board = []
    for x in range(n_queen):
        board.append([0 for x in range(n_queen)])
    nq_util(board, 0)


queen_game()
