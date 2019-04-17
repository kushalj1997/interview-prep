

DeepScale Challenge 2

#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the minArea function below.
def minArea(x, y, k):
    # hashing out thought process here:
    # go through all combos of squares
        # prune squares if you see a slope that is not 0 or 1
        # now see whether the len of set of points not in square is >= k and if curr_area is > maxArea
        # if so, update the square

    # get the outer bounds of the square (min x/y vals and max x/y vals)
    max_x, max_y = max(x), max(y)
    min_x, min_y = min(x), min(y)
    # print(max_x, max_y)
    # print(min_x, min_y)

    # go one outside of the points (we are guaranteed to get at least k points
    # because all of them will be inside)
    coords = [min_x - 1, min_y - 1, max_x + 1, max_y + 1]
    print(coords)

    sq_min = min(coords)
    sq_max = max(coords)

    # print("bl, br", bl_pt, br_pt)

    # can use these points for the area
    edge_size = abs(sq_min - sq_max)

    return edge_size * edge_size


def minArea(x, y, k):
    # x[0] = x, y[0] = y ... x[n]
    # hashing out thought process here:
    # go through all combos of squares
        # prune squares if you see a slope that is not 0 or 1
        # now see whether the len of set of points not in square is >= k and if curr_area is > maxArea
        # if so, update the square

    # go through all combinations of squares

    # in loop (while len(set) < k)
        # get set of points inside square:
            # iterate all points, add to set if inside square bounds
        # if len set >= k
            # return the area of current square

    XY = list(zip(x, y))

    sortX = sorted(XY, key=lambda x: x[0])
    sortY = sorted(XY, key=lambda x: x[1])

    minArea = math.inf

    # iterate all combos of squares
    for i in range(len(x) - k + 1):
        for j in range(len(y) - k + 1):
            # get all combos of left and bottom edges
            left_x, left_y = sortX[i]
            bot_x, bot_y = sortY[j]
            if left_x > bot_x or left_y < bot_y:
                continue
            left_edge = left_x - 1
            bot_edge = bot_y - 1

            # consider pts up and right of bottom left corner
            good_pts = set(sortX[i:])
            good_pts = good_pts - set(sortY[:j])

            if len(good_pts) < k:
                continue

            areas = []
            for pt in good_pts:
                edge_size = max([pt[0] + 1 - left_edge, pt[1] + 1 - bot_edge])
                areas.append(edge_size * edge_size)

            areas = sorted(areas)
            # get min area
            currArea = areas[k - 1]
            if minArea > currArea:
                minArea = currArea

    return minArea


if __name__ == '__main__':
