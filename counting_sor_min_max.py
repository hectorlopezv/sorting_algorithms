#!/usr/bin/python3


def counting_sort(array=None, size=None):
    """counting_sort"""
    max_ = max(array)
    min_ = min(array)
    

    counting_array = [0 for _ in range(min_, max_+1)]
    new_array = [0 for _ in range(size)]
    print(new_array)
    print(counting_array)
    
    print(max_)  
    print(len(counting_array))
    print()

    #initialize the keys and count for each key
    for idx, num in enumerate(array):
        print(num)
        counting_array[num-min_] = counting_array[num- min_] + 1
    
    print(counting_array)

    #sum of counts
    for idx, value in enumerate(counting_array[1:], 1):
        counting_array[idx] = counting_array[idx - 1] + counting_array[idx]

    print(counting_array)

    #populate new array
    print()
    for number in array[::-1]:
        print("number is {}".format(number))
        idx = counting_array[number-min_]
        print(idx)
        counting_array[number -min_] = counting_array[number-min_] - 1

        new_array[idx - 1] = number
        #print(new_array)
    
    print()
    print(new_array)

    

array = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]

print(array)
print()
counting_sort(array, len(array))
print()
print (array)