#!/usr/bin/python3
""" N non-attacking queens on an N*N chessboard """
import sys


def resolve(row, column):
    resolver = [[]]
    for i in range(row):
        resolver = place_queen(i, column, resolver)
    return resolver


def place_queen(i, column, prev_solver):
    solver_queen = []
    for array in prev_solver:
        for j in range(column):
            if is_safe(i, j, array):
                solver_queen.append(array + [j])
    return solver_queen


def is_safe(i, j, array):
    """ Checks if array[column] is a valid queen """
    if j in array:
        return (False)
    else:
        return all(abs(array[column] - j) != i - column
                   for column in range(i))


def init():
    """ Method that prints the case """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    if sys.argv[1].isdigit():
        the_queen = int(sys.argv[1])
    else:
        print("N must be a number")
        sys.exit(1)
    if the_queen < 4:
        print("N must be at least 4")
        sys.exit(1)
    return(the_queen)


def n_Queens():
    """ Resolve the N queens """
    the_queen = init()
    resolver = resolve(the_queen, the_queen)
    for array in resolver:
        clean = []
        for i, j in enumerate(array):
            clean.append([i, j])
        print(clean)

if __name__ == '__main__':
    n_Queens()