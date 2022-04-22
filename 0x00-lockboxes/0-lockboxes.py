#!/usr/bin/python3
from itertools import dropwhile


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened."""

    keys = {0}
    boxesRange = range(len(boxes))

    while True:
        not_found = set()

        for i in boxesRange:
            if i in keys:
                for key in dropwhile(lambda k: k in keys, boxes[i]):
                    keys.add(key)
            else:
                not_found.add(i)

        if boxesRange == not_found:
            return False        

        if not not_found:
            return True

        boxesRange = not_found
