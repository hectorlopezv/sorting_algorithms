#!/usr/bin/python3

def insertion_sort(array, size):
    """insertion_sort"""
    for i in range (1, size):
        j = i
        while j > 0 and array[j - 1] > array[j]:
            array[j], array[j - 1] = array[j - 1], array[j]
            j = j - 1

array = [4,0,3,2,1,9,7]
print(array)
insertion_sort(array, len(array))
print(array)


