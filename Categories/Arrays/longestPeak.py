"""
Longest Peak
Write a function that takes in an array of integers and returns the length of the longest peak in the array.
A peak is defined as adjacent integers in the array that are strictly increasing until they reach a tip (the highest value in the peak), at which point they become strictly decreasing. At least three integers are required to form a peak.
For example, the integers 1, 4, 10, 2 form a peak, but the integers 4, 0, 10 don't and neither do the integers 1, 2, 2, 0 . Similarly, the integers 1, 2, 3 don't form a peak because there aren't
1, 2, 2,
1, 2, 3
any strictly decreasing integers after the
3
"""


def longestPeak(array):
    # Write your code here.
    longest_peak = 0
    cur_peak = 0
    peak = []
    last = 0
    rising = True

    for i in range(len(array)):
        print(peak)

        if i == 0:
            last = array[i]
            peak.append(array[i])
            continue

        # if peak is rising
        if rising:
            # if int is bigger than previous
            if (array[i] > last):
                # normal iterate to next int
                last = array[i]
                cur_peak += 1

                continue
            else:
                # if in the middle of proper peak
                if cur_peak > 0:
                    # signal that the peak is descending now
                    rising = False

                # else if theres not even a peak
                else:
                    # restart
                    last = array[i]
                    cur_peak = 0
                    continue
        # if peak descending
        if not rising:
            if (array[i] < last):
                last = array[i]
                cur_peak += 1
                longest_peak = (cur_peak + 1) if (cur_peak + 1) > longest_peak else longest_peak
                continue

            else:
                # restart peak
                cur_peak = 0
                rising = True

                if (array[i] > last):
                    # normal iterate to next int
                    last = array[i]
                    cur_peak += 1
                    longest_peak = (cur_peak + 1) if (cur_peak + 1) > longest_peak else longest_peak
                    continue

    return longest_peak
