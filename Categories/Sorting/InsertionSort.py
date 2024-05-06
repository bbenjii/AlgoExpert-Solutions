def insertionSort(array):
    # Write your code here.
    i = 0
    while(i < len(array)):
        if(i == 0):
            i += 1
        # check if array[i] is bigger than array[i - 1]
        elif (array[i] >= array[i-1]):
            #go to next index
            i +=1
        else:
            # swap the two numbers
            temp = array[i - 1]
            array[i - 1] = array[i]
            array[i] = temp
            
            i -= 1
    return array
