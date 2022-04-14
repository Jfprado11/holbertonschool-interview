#!/usr/bin/python3
""" module to resolve the challenge of the rain
"""


def rain(walls):
    """retuirn tr number of water rainted in th walls
    """
    res = 0
    for i in range(1, len(walls) - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        res = res + (min(left, right) - walls[i])

    return res
