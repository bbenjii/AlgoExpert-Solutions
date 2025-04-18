def zeroSumSubarray(nums):
    sums = []
    for num in nums:
        if num == 0:
            return True
        elif len(sums) == 0:
            sums.append(num)
        else:
            sum_len = len(sums)
            for i in range(sum_len):
                if sums[i] + num == 0:
                    return True
                sums.append(sums[i] + num)
            sums.append(num)

    return False



input = [1, 2, -2, 3]

print(zeroSumSubarray(input))