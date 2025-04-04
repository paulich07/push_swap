/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:38:37 by plichota          #+#    #+#             */
/*   Updated: 2025/04/04 02:35:10 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_list **stack, int rotations, char *s)
{
	int	i;

	if (!stack || !*stack || !rotations)
		return ;
	i = 0;
	while (i < rotations)
	{
		rotate(stack, s, 0);
		i++;
	}
}

void	reverse_rotate_stack(t_list **stack, int rotations, char *s)
{
	int	i;

	if (!stack || !*stack || !rotations)
		return ;
	i = 0;
	while (i < rotations)
	{
		reverse_rotate(stack, s, 0);
		i++;
	}
}

void	double_rotate_stack(t_list **stack1, t_list **stack2, int rotations)
{
	int	i;

	if (!stack1 || !*stack1 || !stack2 || !*stack2 || !rotations)
		return ;
	i = 0;
	while (i < rotations)
	{
		double_rotate(stack1, stack2, 0);
		i++;
	}
}

void	double_reverse_rotate_stack( t_list **stack1,
	t_list **stack2, int rotations)
{
	int	i;

	if (!stack1 || !*stack1 || !stack2 || !*stack2 || !rotations)
		return ;
	i = 0;
	while (i < rotations)
	{
		double_reverse_rotate(stack1, stack2, 0);
		i++;
	}
}
