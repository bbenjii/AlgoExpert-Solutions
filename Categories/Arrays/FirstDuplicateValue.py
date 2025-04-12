"""
Given an array of integers between
and
, inclusive, where is the length of the array, write a
function that returns the first integer that appears more than once (when the array is read from left to right).
In other words, out of all the integers that might occur more than once in the input array, your function should return the one whose first duplicate value has the minimum index.
If no integer appears more than once, your function should return -1 .
Note that you're allowed to mutate the input
"""

def firstDuplicateValue(array):
    copy = list(array)
    for i in copy:
        if array[i-1] < 0:
            return i

        array[i-1] = i * -1

    return -1


sample_input = [2, 1, 5, 6, 3, 3, 4]
print(firstDuplicateValue(sample_input))