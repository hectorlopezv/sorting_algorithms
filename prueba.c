#include <stdio.h>
#include <stdlib.h>


typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *n;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        n = (int *)&node->n;
        *n = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *next, *prev, *head;
    listint_t *rev, *prev_r, *next_r;
	prev = NULL;
    head = *list;
	
	if(head->next == NULL || list == NULL)
		return;
		
	while(head->next != NULL)
	{   
	    if (head->n > head->next->n)
	    {
	            next = head->next;
                if (next->next != NULL)
                    next->next->prev = head;

                head->next = next->next;
                head->prev = next;

                next->next = head;
                next->prev = prev;

                if (prev != NULL)
                    prev->next = next;

                if (next->prev == NULL)
                    *list = next;

                print_list(*list);
                head = next;  
                rev = head;

                while(rev != NULL && rev->prev != NULL)
                {   
                   
                    if (rev->n < rev->prev->n)
                    {

                        prev_r = rev-> prev;
                        next_r = prev_r->prev;

                        prev_r->next = rev->next;
                        rev->next->prev = prev_r;

                        rev->next = prev_r;
                        prev_r->prev = rev;

                        if (next_r != NULL)
                        {
                            next_r->next = rev;
                        }
                        if (next_r == NULL)
                        {
                            *list = rev;
                        }
                        rev->prev = next_r;
                        rev = prev_r;

                    }
                    else{break;}
                    if (rev->prev == NULL)
                    {
                        *list = rev;
                    }
                    print_list(*list);
                    rev = rev->prev;
                }
        }
        

        prev = head;
        head = head->next;
	}


}

int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}

