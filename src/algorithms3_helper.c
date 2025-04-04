/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms3_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:34:03 by plichota          #+#    #+#             */
/*   Updated: 2025/04/04 02:23:09 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_list_elem_by_index(t_list *stack, int index)
{
	int	i;

	if (!stack)
		return (NULL);
	i = 0;
	while (i < index)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

t_moves	*get_rotation_moves(t_list *stack_a, t_list *stack_b, int i)
{
	t_moves	*new_moves;
	t_list	*elem;
	int		pos;
	int		common_rotations;

	if (!stack_a || !stack_b)
		return (NULL);
	new_moves = ft_calloc(1, sizeof(t_moves));
	if (!new_moves)
		return (NULL);
	elem = get_list_elem_by_index(stack_b, i);
	if (!elem)
		return (free(new_moves), NULL);
	pos = find_insertion_index(stack_a, elem);
	common_rotations = get_min(i, pos);
	new_moves->rr = common_rotations;
	new_moves->ra = pos - common_rotations;
	new_moves->rb = i - common_rotations;
	new_moves->total_moves = new_moves->rr + new_moves->ra + new_moves->rb;
	return (new_moves);
}

t_moves	*get_reverse_rotation_moves(t_list *stack_a, t_list *stack_b, int i)
{
	t_moves	*new_moves;
	t_list	*elem;
	t_var	s;

	if (!stack_a || !stack_b)
		return (NULL);
	new_moves = ft_calloc(1, sizeof(t_moves));
	if (!new_moves)
		return (NULL);
	elem = get_list_elem_by_index(stack_b, i);
	if (!elem)
		return (free(new_moves), NULL);
	s.pos = find_insertion_index(stack_a, elem);
	s.moves_a = ft_lstsize(stack_a) - s.pos;
	s.moves_b = ft_lstsize(stack_b) - i;
	s.common_rotations = get_min(s.moves_a, s.moves_b);
	new_moves->rrr = s.common_rotations;
	new_moves->rra = s.moves_a - s.common_rotations;
	new_moves->rrb = s.moves_b - s.common_rotations;
	new_moves->total_moves = new_moves->rrr + new_moves->rra + new_moves->rrb;
	return (new_moves);
}

t_moves	*get_combined_rotation_moves(t_list *stack_a, t_list *stack_b, int i)
{
	t_moves	*new_moves;
	t_list	*elem;
	int		pos;

	if (!stack_a || !stack_b)
		return (NULL);
	new_moves = ft_calloc(1, sizeof(t_moves));
	if (!new_moves)
		return (NULL);
	elem = get_list_elem_by_index(stack_b, i);
	if (!elem)
		return (free(new_moves), NULL);
	pos = find_insertion_index(stack_a, elem);
	if (pos > ft_lstsize(stack_a) / 2)
		new_moves->rra = ft_lstsize(stack_a) - pos;
	else
		new_moves->ra = pos;
	if (i > ft_lstsize(stack_b) / 2)
		new_moves->rrb = ft_lstsize(stack_b) - i;
	else
		new_moves->rb = i;
	new_moves->total_moves = new_moves->ra + new_moves->rra
		+ new_moves->rb + new_moves->rrb;
	return (new_moves);
}
