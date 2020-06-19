#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void quick_sort_hoare(int *array, size_t size);
void swap_(int *array, size_t size, int *a, int *b);
size_t hoare_partition(int *array, ssize_t size, ssize_t lo, ssize_t hi);
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi);
void counting_sort(int *array, size_t size);
#endif
