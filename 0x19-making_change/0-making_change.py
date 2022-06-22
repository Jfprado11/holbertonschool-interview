"""
Program to solve a challenge of the making change of coins
"""
import sys


def makeChange(coins, total):
    """Function which recive an amount of coins and
    the total of the value which needed for the change
    """
    if total <= 0:
        return 0
    res = [0]
    for i in range(1, total + 1):
        res.append(sys.maxsize)

    for i in range(1, total + 1):
        for j in range(len(coins)):
            if coins[j] <= i:
                current_count = res[i - coins[j]]
                if (current_count != sys.maxsize) and (current_count + 1 < res[i]):
                    res[i] = current_count + 1
    if res[total] == sys.maxsize:
        return - 1
    return res[total]
