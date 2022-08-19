#!/usr/bin/python3
"""
Module rain
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.
    """

    totalWater = 0
    i = 0
    j = len(walls) - 1
    right = 0
    left = 0

    if not walls or len(walls) < 1:
        return 

    while i < j:
        if walls[i] < walls[j]:
            if walls[i] < left:
                totalWater += left - walls[i]
            left = max(left, walls[i])
            i += 1
        else:
            if walls[j] < right:
                totalWater += right - walls[j]
            right = max(right, walls[j])
            j -= 1

    return totalWater
