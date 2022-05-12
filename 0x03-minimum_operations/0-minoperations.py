#!/usr/bin/python3
""" Task that define the minimum operations """


def minOperations(n):


    div, numop = 2, 0

    while n > 1:
        if n % div == 0:
            n /= div
            numop += div
        else:
            div += 1
    return numop
