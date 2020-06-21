#include "sort.h"


void merge_(int *array, int low, int max, int pivot , int *temp)
{
    int i, j, k;

    i = low;
    j = pivot+1;
    k = 0;

    printf("Merging...\n");
	printf("[left]: ");
	print_array(array + low, pivot);
	printf("[right]: ");
	print_array(array + pivot, max - pivot);
	printf("[Done]: ");
    

    while (i <= pivot && j <= max)
    {

        if (array[i]<=array[j])
        {
            temp[k] = array[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = array[j];
            j++;
            k++;
        }

    }
    /*put remaining elements in left array*/
    while (i<=pivot)
    {
        temp[k] = array[i];
        i++;
        k++;
    }
    /*put remaining elements in right array*/
    while (j<=max)
    {
        temp[k] = array[j];
        k++;
        j++;
    }
    /*put temp elemtn in array */
    i = low;
    while (i<=max)
    {
        array[i] = temp[i-low];
        i++;
    }

    print_array(temp + low, max - low);


}

void merge_sort_(int *array, int low, int max , int *temp)
{
    int pivot;

    if (low>= max)
    return;
    
    pivot = (max +low)/2;
    
    merge_sort_(array, low, pivot, temp);
    merge_sort_(array, pivot + 1, max, temp);
    merge_(array,low, max, pivot, temp);
}
void merge_sort(int *array, size_t size)
{
    int *temp = malloc(sizeof(int) * size);
    merge_sort_(array, 0, size-1 , temp);
    free(temp);

}