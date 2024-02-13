# Write a function that takes in an array of positive integers and returns the maximum sum of non-adjacent elements in the array.
# If the input array is empty, the function should return 0

def maxSubsetSumNoAdjacent(array):
    # Write your code here.
    if (len(array) == 0):
        return 0
    elif(len(array) == 1):
        return array[0]

    else:
        maxsum = array[0]
        previous_maxsum = 0

        for i in range(1, len(array)):
            potential_max = previous_maxsum + array[i]
            if(potential_max > maxsum):
                previous_maxsum = maxsum
                maxsum = potential_max
            else:
                previous_maxsum = maxsum

        return maxsum
