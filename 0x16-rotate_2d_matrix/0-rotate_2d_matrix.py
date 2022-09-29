#!/usr/bin/python3
"""
0x16 - function Rotate 2D Matrix 
"""


def rotate_2d_matrix(matrix):
    matrix.reverse()
    matrixCopy = matrix.copy()
    lenM = len(matrix)

    for i in range(lenM):
        matrix[i] = [row[i] for row in matrixCopy]
