#!/usr/bin/python3


def merge_(arr, start, mid, end):
    """merge list"""
    temp = [0] * (end - start + 1)

    i = start
    j = mid + 1
    k = 0

    while i <= mid and j <= end:
        if arr[i] <= arr[j]:
            temp[k] = arr[i]
            k = k + 1
            i = i + 1
        else:
            temp[k] = arr[j]
            j = j + 1
            k = k + 1

    # add element missing in left if necessary
    while i <= mid:
        temp[k] = arr[i]
        k = k + 1
        i = i + 1

    # add elemetns missing on right if necessary
    while j <= end:
        temp[k] = arr[j]
        k = k + 1
        j = j + 1

    # add elements from temp to orginal array
    i = start
    while i <= end:
        arr[i] = temp[i - start]
        # start es para que el indice de start comienze en 0 en los casos de la
        # sublist grande de la derecha
        i = i + 1


def merge_sort_(array1, min_, max_, size):
    """splitting list"""

    if min_ >= max_:
        return

    pivot = (min_ + max_) // 2

    merge_sort_(array1, min_, pivot, size)
    merge_sort_(array1, pivot + 1, max_, size)
    merge_(array1, min_, pivot, max_)


def merge_sort(array):
    """merge_sort"""

    merge_sort_(array, 0, len(array) - 1, len(array))


array = [2, 7, 6, 4, 1, 8, 5, 3]

print(array)
merge_sort(array)
print(array)
