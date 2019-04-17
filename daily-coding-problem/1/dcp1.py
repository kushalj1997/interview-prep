# Daily Coding Problem 1

# Given a list of numbers and a number k, return whether any two numbers from list
# add up to k

# example: given [10, 15, 3, 7] and k = 17
# return true since 10 + 7 is 17


def main():
    nums = [10, 16, 3, 7]
    k = 17

    # # brute force soln
    # for num in nums:
    #     for num2 in nums:
    #         if num + num2 == k:
    #             print("true", num, num2)
    #             return True

    # one pass solution
    diff_hash_set = set()
    for num in nums:
        if k - num in diff_hash_set:
            print("true", num, k - num)
            return True
        diff_hash_set.add(num)

    print("False")
    return False


if __name__ == '__main__':
    main()
