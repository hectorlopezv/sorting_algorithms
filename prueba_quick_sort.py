#!/usr/bin/python3
#array = [9, 7, 5, 11, 12, 2, 14, 3, 10, 6]
array = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]

def partition(array=None, min=None, max=None):
    """partition """
    
    pivot = array[max]
    i = min -1
    j = 0

    for j in range(min, max):
        
        if array[j] < pivot:
            i += 1
            array[i], array[j] = array[j], array[i]
    
    array[i + 1], array[j + 1] = array[j + 1],  array[i + 1]

    return i + 1

        



def  quick_sort(array, min, max):
    """quick sort"""
    while min < max:#reduce #numebrs of recursion calls
        #print(array)

        idx = partition(array, min, max)


        #quick_sort(array, idx)
        #idx = partition(array, 0, idx - 1)
        #if left side is smaller call recursion 
        # else call recursion on the right side

        if idx - min < max - idx:
            quick_sort(array, min, idx - 1)
            min = idx + 1;# tail recursion elimination 
                            #reduce number of recursion calls
        
        else:
            quick_sort(array, idx + 1, max)
            max = idx - 1
        
        #min = idx + 1

        
        #quick_sort(array, min, idx - 1)

        #min = idx + 1
       # quick_sort(array, idx + 1, max)

print(array)
quick_sort(array, 0, len(array) - 1)

print(array)

    

