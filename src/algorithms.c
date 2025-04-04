/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:41:02 by plichota          #+#    #+#             */
/*   Updated: 2025/04/04 02:29:04 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_element_by_median(t_list **stack_b, t_list **stack_a, int m)
{
	if (!stack_a || !stack_b || !*stack_a)
		return ;
	push_to(stack_b, stack_a, "b", 0);
	if ((*stack_b)->content > m && ft_lstsize(*stack_b) > 1)
		rotate(stack_b, "b", 0);
}

void	insertion_sort(int *arr, int l)
{
	int	i;
	int	j;
	int	key;

	if (!arr || l <= 0)
		return ;
	i = 0;
	while (i < l)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

int	calculate_median(t_list *stack, int n)
{
	int	i;
	int	*arr;

	if (!stack || n <= 0)
		return (0);
	if (n == 1)
		return (stack->content);
	i = 0;
	arr = ft_calloc(n, sizeof(int));
	if (!arr)
		return (0);
	while (stack != NULL && i < n)
	{
		arr[i] = stack->content;
		stack = stack->next;
		i++;
	}
	insertion_sort(arr, n);
	if (n % 2 == 0)
		return (free(arr), (arr[n / 2] + arr[(n / 2) - 1]) / 2);
	return (free(arr), arr[n / 2]);
}

void	sort_three_elem(t_list **head, char *s)
{
	if (!head || !(*head) || !(*head)->next || !((*head)->next)->next)
		return ;
	if (((*head)->content > ((*head)->next)->content
			&& ((*head)->next)->content > (((*head)->next)->next)->content)
		|| ((*head)->content > ((*head)->next)->content
			&& (*head)->content < (((*head)->next)->next)->content)
		|| ((*head)->content < (((*head)->next)->next)->content
			&& ((*head)->next)->content > (((*head)->next)->next)->content)
	)
		swap_first(head, s, 0);
	if ((*head)->content > (((*head)->next)->next)->content
		&& ((*head)->next)->content < (((*head)->next)->next)->content)
		rotate(head, s, 0);
	else if ((*head)->content < ((*head)->next)->content
		&& (*head)->content > (((*head)->next)->next)->content)
		reverse_rotate(head, s, 0);
}
