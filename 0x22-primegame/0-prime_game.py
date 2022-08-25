#!/usr/bin/python3
"""
a function to evaluate the result the prime game
"""


def isWinner(x, nums):
    """evaluates who is the winner a return the name of the winner person
    """
    if (x < 1):
        return None

    number = 0

    for num in nums:
        number ^= nums[num % len(nums)]

    return 'Ben' if number > 0 else 'Maria'
