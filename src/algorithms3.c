/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:43:38 by plichota          #+#    #+#             */
/*   Updated: 2025/04/03 05:25:47 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_start_position(t_list *head)
{
	int	i;
	int min;
	int min_i;

	if (!head || !head->next)
		return (0);
	i = 0;
	min = head->content;
	min_i = 0;
	while (head != NULL)
	{
		if (head->content < min)
		{
			min = head->content;
			min_i = i;
		}
		head = head->next;
		i++;
	}
	return (min_i);
}

int		is_max_or_min(t_list *elem, t_list *stack)
{
	int	bigger_exist;
	int	smaller_exist;

	bigger_exist = 0;
	smaller_exist = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		if (stack->content > elem->content)
			bigger_exist = 1;
		if (stack->content < elem->content)
			smaller_exist = 1;
		if (smaller_exist && bigger_exist)
			return (0);
		stack = stack->next;
	}
	return (smaller_exist ^ bigger_exist);
}

int		find_insertion_index(t_list *stack_a, t_list *stack_b)
{
	int i;
	t_list *prev;

	if (is_max_or_min(stack_b, stack_a))
		return (find_start_position(stack_a));
	prev = ft_lstlast(stack_a);
	if (stack_a->content > stack_b->content && stack_a->content > prev->content
		&& prev->content < stack_b->content)
		return (0);
	i = 1;
	prev = stack_a;
	stack_a = stack_a->next;
	while (stack_a != NULL)
	{
		if (stack_a->content > stack_b->content && stack_a->content > prev->content
			&& prev->content < stack_b->content)
			return (i);
		prev = stack_a;
		stack_a = stack_a->next;
		i++;
	}
	return (0);
}

int	is_sorted(t_list *stack)
{
	if (stack && !stack->next)
		return (1);
	if (!stack || !stack->next)
		return (-1);
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->content > (stack ->next)->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}