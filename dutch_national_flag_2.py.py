#!/usr/bin/python3

def national_flag_2_way(array, low, max):
    """national flag partion"""
    
    low = low
    high = max

    while low <= high:

        if array[low] == 0:
            
            low = low + 1
        
        else:

            array[low], array[high] = array[high], array[low]
            high = high - 1
        



array =  [0, 0, 1, 1, 0, 1, 0, 0, 0, 1]
print(array)
national_flag_2_way(array, 0, len(array) - 1)
print(array)