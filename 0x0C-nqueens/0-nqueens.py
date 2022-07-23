#!/usr/bin/python3
""" N non-attacking queens on an N*N chessboard """
import sys


def resolve(row, column):
    """ Print the requires """
    for i in range(column):
        if row[i] == row[column]:
            return False

        if abs(row[i] - row[column]) == abs(i - column):
            return False

    return True


def place_queen(row, column):
    """ Print acording the size """
    queen_size = len(row)
    success = 0
    if queen_size == column:
        resolver = []

        for i in range(len(row)):
            resolver.append([i, row[i]])
        print(resolver)
        return True

    row[column] = -1

    while(row[column] < queen_size - 1 or success == 1):
        row[column] = row[column] + 1
        if resolve(row, column) is True:
            if column != queen_size:
                place_queen(row, (column + 1))
            else:
                success = 1
                break
    return True


if __name__ == '__main__':
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

    row = []
    size = int(sys.argv[1])
    for i in range(size):
        row.append(-1)
    place_queen(row, 0)
