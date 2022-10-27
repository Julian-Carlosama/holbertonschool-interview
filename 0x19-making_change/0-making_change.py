#!/usr/bin/python3
"""
Main file for testing
"""


def makeChange(coins, total):
    """
        Given a pile of coins of different values, determine the fewest
        number of coins needed to meet a given amount total.
    """
    if total <= 0:
        return 0
    
    else:
        coins = {}