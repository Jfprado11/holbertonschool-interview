#!/usr/bin/python3
"""
a function to evaluate the result the prime game
"""


def isWinner(x, nums):
    """evaluates who is the winner a return the name of the winner person
    """
    if (x < 1):
        return None

    # values = [0, 0, 1, 1, 2, 2, 3, 3, 4]
    number = 0

    for num in range(0, x):
        number ^= nums[num % len(nums)]

    return 'Ben' if number > 0 else 'Maria'
