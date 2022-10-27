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
        from math import trunc

        coinsDict = {}
        coins = sorted(coins, reverse=True)

        while total is not None:
            for coin in coins:
                if total % coin == 0:
                    coinsDict[coin] = total / coin
                    return(int(sum(coinsDict.values())))
                else:
                    coinsDict[coin] = trunc(total / float(coin))
                    total -= (coin * coinsDict[coin])
            return -1
