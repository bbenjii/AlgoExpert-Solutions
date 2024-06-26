"""
Write a function that takes in a "special" array and returns its product sum.
A "special" array is a non-empty array that contains either integers or other "special" arrays. The product sum of a "special" array is the sum of its elements, where "special" arrays inside it are summed themselves and then multiplied by their level of depth.
The depth of a "special" array is how far nested it is. For instance, the depth of [] is 1; the depth of the inner array in [[]] is 2; the depth of the innermost array in [E[]]] is 3).
Therefore, the product sum of [x, y] is x + y; the product sum of [x, Ly, z]] is x + 2 * (y + z) ; the product sum of [x, Ly, [z]]] is x + 2 * (y + 3z) .
"""
def productSum(array, depth = 1):
    # Write your code here.
    ProductSum = 0
    for element in array:
        if type(element) == int:
            ProductSum += element
        elif type(element) == list:
            ProductSum += (depth+1)*productSum(element, depth+1)
    return ProductSum
