"""

Array Of Products •
Write a function that takes in a non-empty array of integers and returns an array of the same length, where each element in the output array is equal to the product of every other number in the input array.
In other words, the value at output [il is equal to the product of every number in the input array other than input[i].

"""


def arrayOfProducts(array):
    # Write your code here.
    product = 1
    output = []
    zero_count = 0
    for int in array:
        if int == 0:
            zero_count = zero_count + 1
            if zero_count > 1:
                product = 0
        else:
            product = product * int

    for int in array:
        if zero_count > 1:
            output.append(0)
        else:
            if int == 0:
                output.append(product)
            elif zero_count == 1:
                output.append(0)
            else:
                output.append(product / int)

    return output

