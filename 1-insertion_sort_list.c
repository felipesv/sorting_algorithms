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

	if (list == NULL || *list == NULL)
		return;

	while (crn != NULL)
	{
		if (crn->next != NULL && crn->n > crn->next->n)
		{
			swap(crn, crn->next, list);
			swap_rever(crn->prev, list);
			crn = crn->prev;
		}
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
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	if (first->prev != NULL)
		first->prev->next = second;
	first->prev = second;
	if (second->prev == NULL)
		*head = second;
	print_list(*head);
}

/**
 * swap_rever - check new node swap with others
 * @crn: current
 * @head: head
 *
 * Return: is a void
 */
void swap_rever(listint_t *crn, listint_t **head)
{
	while (crn != NULL && crn->prev != NULL)
	{
		if (crn->n < crn->prev->n)
		{
			swap(crn->prev, crn, head);
			crn = crn->next;
		}
		crn = crn->prev;
	}
}
