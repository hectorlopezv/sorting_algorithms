#!/usr/bin/python3


def cock_tail_sort(array, size):

    sorted = True
    start = 0
    end = size - 1

    while sorted == True:

        sorted  = False

        for i in range(start, end):
            """rigth bubble"""
            sorted = False
            if array[i] > array[i + 1]:
                sorted = True
                array[i], array[i + 1] = array[i + 1], array[i]
                print(array)
            
        if sorted == False:
            break
        
        sorted = False
        end -= 1
        for i in range(end - 1, start - 1, -1):
            """left bubble"""
            if array[i] > array[i + 1]:
                sorted = True
                array[i], array[i + 1] = array[i + 1], array[i]
                print(array)

        start += 1



array = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]
print(array)
cock_tail_sort(array, len(array))
print(array)