#!/usr/bin/env python3
"""determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """returns true if it is utf-8 otherwise false
    """
    count = 0
    for num in data:
        if count == 0:
            if num >> 5 == 0b110:
                count = 1
            elif num >> 4 == 0b1110:
                count = 2
            elif num >> 3 == 0b11110:
                count = 3
            elif num >> 7 == 1:
                return False

        else:
            if num >> 6 != 2:
                return False
            count -= 1
    return count == 0
