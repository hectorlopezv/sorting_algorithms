#!/usr/bin/python3


def merge_sub_list(array1, array2, array3):
    """how to merge 2 sublist"""
    i = 0
    j = 0
    k = 0
    n1 = len(array1)
    n2 = len(array2)

    while i < n1 and j < n2:
        
        if array1[i] == array2[j]:
            array3[k]  = array1[i]
            i = i + 1
            k = k + 1
        elif array1[i] <  array2[j]:

            array3[k] = array1[i]
            i = i + 1
            k = k + 1
            print(array3)

        elif array2[j] < array1[i]:
            
            array3[k] = array2[j]
            j = j + 1
            k = k + 1
            print(array3)

    if i == n1:
        for x in range(j, n2):
            array3[k] = array2[x]
            k = k + 1

    if j == n2:
        for x in range(i, n1):
            array3[k] = array1[x]
            k = k + 1
 
        
        print(array3)


        


array1 = [1,3,4, 7]
array2 = [2,5,7,8]
array3 = [0] * (len(array1) + len(array2))
print(array1)
print(array2)
print(array3)

merge_sub_list(array1, array2, array3)
print(array3)

