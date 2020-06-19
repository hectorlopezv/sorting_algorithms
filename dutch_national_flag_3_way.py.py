#!/usr/bin/python3

def national_flag_3_way(array=None, low=None, max=None):
    """national flag partion"""
    
    low = low
    mid = low
    high = max 

    while mid <= high:

        if array[mid] == 0:
            
            array[low], array[mid] = array[mid], array[low]
            low =  low + 1
            mid = mid + 1

        elif array[mid] == 1:
            mid = mid + 1

        elif array[mid] == 2:
            
            array[mid], array[high] = array[high], array[mid]
            high -= 1

array =  [2, 0, 1, 2, 1, 2, 2, 0, 1, 1,1]
print(array)
national_flag_3_way(array, 0, len(array) - 1)
print(array)
