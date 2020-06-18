#include "sort.h"

listint_t *bubble_rigth(listint_t **list, listint_t **start,
		listint_t **end, int *sorted, listint_t **start_mov);

void bubble_left(listint_t **list, listint_t **end, listint_t **start_mov,
		int *sorted);

/**
 * cocktail_sort_list - extension of bubble sort
 * @list: list of nodes
 * Return: return starting point
 */
void cocktail_sort_list(listint_t **list)
{

	listint_t  *start, *start_mov, *end_mov, *end;

	int sorted = 1;

	end_mov = end = NULL;

	if (list == NULL || *list == NULL)
		return;

	if ((*list)->next == NULL)
		return;

	start = *list;
	start_mov = NULL;
	do {
		sorted = 0;
		end = bubble_rigth(list, &start, &end, &sorted, &start_mov);
		if (sorted == 0)
			break;
		sorted = 0;

		end_mov = end;
		bubble_left(list, &end, &start_mov, &sorted);

		start = start_mov->next;
		if (end->next != NULL)
			end = end_mov->prev;

	} while (sorted);

}

/**
 * bubble_rigth - bubble_rigth
 * @start: start limit of bubble sort(left limit)
 * @list: list of nodes
 * @start_mov: the left limit of bubble sort(left limit)
 * @sorted: sort boolean
 * @end: rigth limit of bubble sort
 * Return: return starting point
 */
listint_t *bubble_rigth(listint_t **list, listint_t **start,
		listint_t **end, int *sorted, listint_t **start_mov)
{
	listint_t *prev, *next, *end_t, *start_t;

	start_t = *start;
	end_t = *end;
	next = prev = NULL;

	while (start_t->next != end_t)
	{
		next = start_t->next;
		if (start_t->n > next->n)
		{
			if (next->next != NULL)
				next->next->prev = start_t;

			start_t->prev = next;
			start_t->next = next->next;

			next->next = start_t;
			next->prev = prev;

			if (prev != NULL)
				prev->next = next;

			if (next->prev == NULL)
			{
				*list = next;
				*start_mov = next;
			}
			start_t = next;
			*sorted = 1;
			print_list(*list);
		}
		prev  = start_t;
		start_t = start_t->next;
	}

	return (start_t);
}

/**
 * bubble_left - bubble_left
 * @end: end limit of bubble sort(rigth limit)
 * @list: list of nodes
 * @start_mov: the left limit of bubble sort(left limit)
 * @sorted: sort boolean
 * Return: return nothing
 */
void bubble_left(listint_t **list, listint_t **end,
		listint_t **start_mov, int *sorted)
{
	listint_t *prev, *end_t;

	end_t = *end;

	while (end_t->prev != *start_mov)
	{
		prev = end_t->prev;

		if (end_t->n < prev->n)
		{
			end_t->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = end_t;

			if (prev->prev == NULL)
				*list = end_t;

			prev->next = end_t->next;

			if (end_t->next != NULL)
				end_t->next->prev = prev;


			end_t->next = prev;
			prev->prev = end_t;


			end_t = prev;
			*sorted = 1;
			print_list(*list);
		}
		end_t = end_t->prev;
	}

	if (*start_mov == NULL)
		*start_mov = *list;

}
