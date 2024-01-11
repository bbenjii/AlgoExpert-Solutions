def nonConstructibleChange(coins):
    # Write your code here.

    if len(coins) == 0:
        return 1
        
    coins.sort()
    
    max_change = 0
    
    for coin in coins:
        if coin > (max_change+1):
            return (max_change + 1)
    
        else:
            max_change = max_change + coin

    return max_change + 1
            
            

