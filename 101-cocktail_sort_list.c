#include "sort.h"
/**
 * cocktail_sort_list - sort and double linked list
 * @list: head
 *
 * Return: is a void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *crn = NULL, *tmp = NULL;
	int lim1 = 0, lim2 = 0, cnt = 0, dir = 0;

	if (list == NULL || *list == NULL)
		return;
	crn = *list;
	while ((crn = crn->next) != NULL)
		lim2++;
	crn = *list;
	while (lim1 != lim2)
	{
		if (dir == 0)
		{
			if (crn->next == NULL || cnt > lim2)
			{
				dir = 1;
				lim2--;
				continue;
			}
			if (crn->n > crn->next->n)
				swap(crn, crn->next, list);
			else
				crn = crn->next;
			cnt++;
		}
		if (dir == 1)
		{
			if (crn->prev == NULL || cnt < lim1)
			{
				dir = 0;
				lim1++;
				continue;
			}
			if (crn->n < crn->prev->n)
				swap(crn->prev, crn, list);
			else
				crn = crn->prev;
			cnt--;
		}
	}
}
/**
 * swap - swap two elements
 * @first: first node to swap with second
 * @second: second node to swap with first
 * @head: head
 *
 * Return: is a void
 */
void swap(listint_t *first, listint_t *second, listint_t **head)
{
	first->next = second->next;
	if (first->prev != NULL)
		first->prev->next = second;
	second->prev = first->prev;
	first->prev = second;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	if (second->prev == NULL)
		(*head) = second;
	print_list(*head);
}
