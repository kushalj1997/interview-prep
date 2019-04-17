from math import sqrt


def cavityMap(arr):
    # convert the array to 1D array
    # arr2 = []
    # for elt in arr:
    #     for char in elt:
    #         arr2.append(char)
    # populate a list of list for map
    map_wh = len(arr)

    # once we have the map, iterate through each elt that is not on the border
    # and check if the adjacent tiles are all strictly below
    # doing this on a 1D array means that the indices of the tiles to check will be as follows:
    # example map: 010
    #              101 => (1, 1) becomes 4 (1 * map_wh + 1) and y = index / map_wh and x = index % map_wh
    #              211
    # serialized as 010101211
    # get indices of N/S/E/W tiles for all inner tiles and check depths
    # convert current to 2D index, get N/S/E/W, then convert back to 1D index

    output = arr.copy()

    # for i in range(len(arr2)):
    #     res = get_NSEW_indices(i, map_wh)
    #     if res != -1:
    #         n, s, e, w = res
    #         if arr2[n] < arr2[i] and arr2[s] < arr2[i] and arr2[e] < arr2[i] and arr2[w] < i:
    #             output[i] = "X"

    for row in range(1, map_wh - 1):
        for col in range(1, map_wh - 1):
            n = arr[row - 1][col]
            s = arr[row + 1][col]
            e = arr[row][col + 1]
            w = arr[row][col - 1]
            curr = arr[row, col]
            print("current", curr)
            if curr > n and curr > s and curr > e and curr > w:
                # we have found a cavity
                output[row, col] = "X"
            # print(output[row, col])
        # print()

    return output


def main():
    arr = ["1112", "1912", "1892", "1234"]
    cavityMap(arr)


if __name__ == '__main__':
    main()
