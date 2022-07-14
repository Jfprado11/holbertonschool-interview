#!/usr/bin/python3

"""
Module fot the solution the island piramid
"""


def island_perimeter(grid):
    """returns the perimeter of a grid"""
    count = 0
    lists = len(grid)
    single = len(grid[0])
    for y in range(lists):
        for x in range(single):
            if grid[y][x] == 1:
                count += 4
                if (y - 1) >= 0 and grid[y - 1][x] == 1:
                    count -= 1
                if (x - 1) >= 0 and grid[y][x - 1] == 1:
                    count -= 1
                if (x + 1) < single and grid[y][x + 1] == 1:
                    count -= 1
                if (y + 1) < lists and grid[y + 1][x] == 1:
                    count -= 1

    return count
