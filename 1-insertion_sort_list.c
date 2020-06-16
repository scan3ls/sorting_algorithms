#include "sort.h"

/**
* insertion_sort_list - implementation of insertion sort
*
*@list: list to sort
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *placeHolder;

	if (*list == NULL)
		return;

	temp = *list;
	temp = temp->next;

	while (temp != NULL)
	{
		if (temp->prev->n > temp->n)
		{
			placeHolder = temp;
			while (temp != NULL && temp->prev->n > temp->n)
			{
				list = swap_list_node(temp, list);
				print_list(*list);
				if (temp->prev == NULL)
				{
					break;
				}
			}
			temp = placeHolder;
		}
		temp = temp->next;
	}

	/* End insertion sort */
}

/**
 * swap_list_node - swappes two nodes in a list if
 *                  previous node has a lower value
 *@node: current node to check
 *@list: pointer to the head of the list
 *
 * Return: the list with the swap node w/ updated head as needed
 */

listint_t **swap_list_node(listint_t  *node, listint_t **list)
{
	listint_t *rightNode, *leftNode, *temp = malloc(sizeof(listint_t));
	listint_t *head;

	if (node == NULL)
	{
		printf("Null node\n");
		return (NULL);
	}

	head = *list;
	rightNode = node;
	leftNode = rightNode->prev;

	temp->next = rightNode->next;
	temp->prev = rightNode->prev;

	if (node->prev->prev == NULL)
	{
		head = rightNode;
	}
	else
	{
		leftNode->prev->next = rightNode;
	}

	if (rightNode->next != NULL)
		rightNode->next->prev = leftNode;

	rightNode->next = leftNode;
	rightNode->prev = leftNode->prev;
	leftNode->prev = rightNode;
	leftNode->next = temp->next;

	free(temp);
	*list = head;
	return (list);
}
