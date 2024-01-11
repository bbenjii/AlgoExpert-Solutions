def isMonotonic(array):
    # Write your code here.
       # Write your code here.

    order = "unknown"
    # figure out if its increasing or decreading
    if(len(array) > 1):

        for x in range(1, len(array)):
            if order == "unknown":
                if array[x] > array[x-1]:
                    order = "inc"
                elif array[x] < array[x-1]:
                    order = "dec"

            elif order == "inc":
                if array[x] < array[x-1]:
                    return False

            elif order == "dec":
                if array[x] > array[x-1]:
                    return False


        return True

    else:
        return True
