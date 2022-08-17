#!/usr/bin/python3
"""
Module rain
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.
    """

    totalWater = 0

    if not walls or not isinstance(walls, list):
        return 0

    for i, wall in enumerate(walls):
        right = i + 1
        if wall <= right:
            if right != 0:
                totalWater += wall
            else:
                totalWater += 1

    return totalWater
