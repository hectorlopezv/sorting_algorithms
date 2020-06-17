#!/usr/bin/python3

def partition(array, low, max):
    """partition"""
    high = max
    pivot = array[max]
    low = low
    mid = low

    while mid <= high:
        
        if array[mid] < pivot:

            array[mid],array[low] = array[low], array[mid]
            low = low + 1
            mid = mid + 1
        elif array[mid] == pivot:
           
            mid = mid + 1
           
        elif array[mid] > pivot:
            
            array[high],array[mid] = array[mid], array[high]
            high = high - 1
           
    
    return mid

def quicksort(array, low, max):
    """quicksort recursive"""
    
    while low < max:
        idx = partition(array, low, max)
     

        if idx - low < max - idx:

            quicksort(array, low, idx)
            low = low + 1
        
        else:

            quicksort(array, idx + 1, max)
            max = max - 1


array = [4,  9,  4,  4,  1,  9,  4,  4,  9,  4,  4,  1,  4]
print(array)
quicksort(array, 0, len(array) - 1)
print(array)