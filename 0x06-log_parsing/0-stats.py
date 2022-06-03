#!/usr/bin/python3
""" Module """

#import sys

from sys import stdin

stsCodes = {
    "200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0, "405": 0, "500": 0
}

size = 0


def printAll():
    """Print the states"""
    print("File size: {}".format(size))
    for sts in sorted(stsCodes.keys()):
        if stsCodes[sts]:
            print("{}: {}".format(sts, stsCodes[sts]))


if __name__ == "__main__":
    count = 0
    try:
        for i in stdin:
            try:
                items = i.split()
                size += int(items[-1])
                if items[-2] in stsCodes:
                    stsCodes[items[-2]] += 1
            except:
                pass
            if count == 9:
                printAll()
                count = -1
            count += 1
    except KeyboardInterrupt:
        printAll()
        raise
    printAll()