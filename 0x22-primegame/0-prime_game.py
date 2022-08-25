#!/usr/bin/python3
"""
a function to evaluate the result the prime game
"""


def isWinner(x, nums):
    """evaluates who is the winner a return the name of the winner person
    """
    if (x < 1):
        return None

    values = [0, 0, 1, 1, 2, 2, 3, 3, 4]
    number = 0

    for num in nums:
        number ^= values[num % len(values)]

    return 'Maria' if number > 0 else 'Ben'
