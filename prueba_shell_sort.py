#!/usr/bin/python3

def shell_sort(array, max):
    """shell sort"""

    h = 1
    size  = max

    while h < size/3:
        h = h * 3 + 1
    gap = h


    while gap >= 1:

        for i in range (gap, size):

            j = i
            
            while j >= gap and array[j - gap] > array[j]:

                array[j], array[j - gap] = array[j - gap], array[j]
                
                j -= gap

        gap //= 3
        print(array)




        





array = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]
print(array)
shell_sort(array, len(array))
print(array)