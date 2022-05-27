#!/usr/bin/python3

"""MOdule interview for rotationg a matrix in 90 deg
"""


def rotate_2d_matrix(matrix):
    """Functioin to rotate a matriz clockwise
    """
    l = 0
    r = len(matrix) - 1
    while l < r:
        for i in range(r - l):
            top = l
            bottom = r

            topLeft = matrix[top][l + i]

            matrix[top][l + i] = matrix[bottom - i][l]

            matrix[bottom - i][l] = matrix[bottom][r - i]

            matrix[bottom][r - i] = matrix[top + i][r]

            matrix[top + i][r] = topLeft

        r -= 1
        l += 1
