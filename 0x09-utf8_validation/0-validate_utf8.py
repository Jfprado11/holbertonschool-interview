#!/usr/bin/python3
"""determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """returns true if it is utf-8 otherwise false
    """
    count = 0
    for c in data:
        if count == 0:
            if (c >> 5) == 0b110:
                count = 1
            elif (c >> 4) == 0b1110:
                count = 2
            elif (c >> 3) == 0b11110:
                count = 3
            elif (c >> 7):
                return False
        else:
            if (c >> 6) != 0b10:
                return False
            count -= 1
    return count == 0
