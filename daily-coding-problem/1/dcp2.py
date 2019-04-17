# Daily Coding Problem
# Kushal Jaligama

# asked by Uber
# given array of ints, return new array such that each element
# at index i of the new array is the product of all the numbers in original
# array except the one at i

# example input [1, 2, 3, 4, 5] gives you [120, 60, 40, 30, 24]
# input [3, 2, 1] output is [2, 3, 6]


def soln(in_nums):
    # naive division solution
    total_product = 1
    for i in in_nums:
        total_product *= i

    out = []

    for i in in_nums:
        out.append(total_product / i)

    print("naive", out)


def main():
    in_nums = [1, 2, 3, 4, 5]
    in_nums2 = [3, 2, 1]

    soln(in_nums)
    soln(in_nums2)

    # solution without using division


if __name__ == '__main__':
    main()
