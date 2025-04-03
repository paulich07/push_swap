/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:21:37 by plichota          #+#    #+#             */
/*   Updated: 2025/04/03 05:32:33 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_best_moves(t_moves **best, t_moves **current)
{
	if (!current || !(*current))
		return;
	if (!(*best))
	{
		*best = *current;
		*current = NULL;
		return;
	}
	if ((*current)->total_moves < (*best)->total_moves)
	{
		free(*best);
		*best = *current;
		*current = NULL;
	}
	else
	{
		free(*current);
		*current = NULL;
	}
}

t_moves	*calculate_best_moves(t_list *stack_a, t_list *stack_b)
{
	t_moves *best;
	t_moves *current;
	int i;

	current = NULL;
	best = NULL;
	if (!stack_a || !stack_b) return (NULL);
	i = 0;
	while (i < ft_lstsize(stack_b))
	{
		current = get_rotation_moves(stack_a, stack_b, i);
		set_best_moves(&best, &current);
		current = get_reverse_rotation_moves(stack_a, stack_b, i);
		set_best_moves(&best, &current);
		current = get_combined_rotation_moves(stack_a, stack_b, i);
		set_best_moves(&best, &current);
		i++;
	}
	return (best);
}

void	insert_sorted_stack(t_list **stack_a, t_list **stack_b)
{
	t_moves *best_moves;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
	    return;
	while (*stack_b != NULL)
	{
		best_moves = calculate_best_moves(*stack_a, *stack_b);
		if (!best_moves)
			return;
		while (--best_moves->rr >= 0)
			double_rotate(stack_a, stack_b, 0);
		while (--best_moves->rrr >= 0)
			double_reverse_rotate(stack_a, stack_b, 0);
		while (--best_moves->ra >= 0)
			rotate(stack_a, "a", 0);
		while (--best_moves->rra >= 0)
			reverse_rotate(stack_a, "a", 0);
		while (--best_moves->rb >= 0)
			rotate(stack_b, "b", 0);
		while (--best_moves->rrb >= 0)
			reverse_rotate(stack_b, "b", 0);
		push_to(stack_a, stack_b, "a", 0);
		free(best_moves);
	}
}

void	rotate_stack_to_start(t_list **stack)
{
	int	rotations;

	if (!stack || !*stack || !(*stack)->next)
		return;
	rotations = find_start_position(*stack);
	if (rotations > ft_lstsize(*stack) / 2)
		reverse_rotate_stack(stack, ft_lstsize(*stack) - rotations, "a");
	else
		rotate_stack(stack, rotations, "a");
}