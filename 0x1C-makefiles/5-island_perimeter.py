#!/usr/bin/python3

def island_perimeter(grid):
    """
    Function to Calculate the perimeter of the island described in the grid.

    :param grid: List of lists of integers representing the island grid
    :return: The perimeter of the island described in grid
    """
    perimeter = 0
    width = len(grid[0])
    height = len(grid)
    size = 0
    edge = 0

    for r in range(height):
        for c in range(width):
            if grid[r][c] == 1:
                size += 1
                if (r > 0 and grid[r - 1][c] == 1):
                    edge += 1
                if (c > 0 and grid[r][c - 1] == 1):
                    edge += 1
                if (r < height - 1 and grid[r + 1][c] == 1):
                    edge += 1
                if (c < width - 1 and grid[r][c + 1] == 1):
                    edge += 1
    return ((size * 4) - (edge))
