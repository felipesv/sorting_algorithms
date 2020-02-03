#include "sort.h"
/**
 * insertion_sort_list  - order a list and print each swap
 * @list: list to sort
 *
 * Return: is a void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *crn = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (crn != NULL)
	{
		while (crn->prev != NULL && crn->n < crn->prev->n)
			swap(crn->prev, crn, list);
		crn = crn->next;
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
