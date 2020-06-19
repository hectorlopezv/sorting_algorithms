#!/usr/bin/python3

def partition(array, low, max):
    """partition"""
    pivot = array[low]
    i = low - 1
    j = max + 1

    while True:

        while True:

            i += 1
            if not array[i] < pivot:
                break
        
        while True:
            j -= 1
            
            if not array[j] > pivot:
                break

        if i >= j:
            return j
        array[i], array[j] =  array[j], array[i]


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


array = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]
print(array)
quicksort(array, 0, len(array) - 1)
print(array)