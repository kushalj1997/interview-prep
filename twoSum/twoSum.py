
def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    for i in range (0, len(nums)):
        for j in range (0, len(nums)):
            if target - nums[j] == nums[i] and i is not j:
                return [i, j]

def main():
    nums = [3, 2, 4]
    target = 6
    idx = twoSum(nums, target)
    print(str(idx[0]) + ': ' + str(nums[idx[0]]))
    print(str(idx[1]) + ': ' + str(nums[idx[1]]))

if __name__ == '__main__':
    main()
