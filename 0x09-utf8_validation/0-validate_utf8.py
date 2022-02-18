#!/usr/bin/python3
"""determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """returns true if it is utf-8 otherwise false
    """
    count = 0
    for num in data:
        bin_rep = format(num, '#010b')[-8:]

        if count == 0:
            for bit in bin_rep:
                if bit == '0':
                    break
                count += 1

            if count == 0:
                continue

            if count == 1 or count > 4:
                return False

        else:
            if not (bin_rep[0] == '1' and bin_rep[1] == '0'):
                return False
        count -= 1
    return count == 0
