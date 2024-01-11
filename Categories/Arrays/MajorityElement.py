def majorityElement(array):
    # Write your code here.

    counter = 0
    maj = array[0]

    if len(array) == 1:
        return array[0]

        
    for n in array[1:]:
        if n == maj:
            counter = counter+1
        else:
            if counter == 0:
                maj = n
            else:
                 counter = counter - 1
                

    return maj
