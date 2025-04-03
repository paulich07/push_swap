/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:41:09 by plichota          #+#    #+#             */
/*   Updated: 2025/04/03 06:12:33 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(char *s)
{
	int			i;
	int			sign;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	if (!s)
		return (0);
	while (s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		num = num * 10 + (s[i] - '0');
		i++;
	}
	if ((num < INT_MIN && sign == -1) || (num > INT_MAX && sign == 1))
		return (0);
	return (1);
}

void	free_stack(t_list **stack)
{
	t_list	*p;

	if (!stack || !*stack)
		return ;
	while (*stack != NULL)
	{
		p = (*stack)->next;
		free(*stack);
		*stack = p;
	}
}

int	is_unique(t_list *stack, int n)
{
	if (!stack)
		return (1);
	while (stack != NULL)
	{
		if (stack->content == n)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// fd = 1 scrive sul terminale OPPURE in un file se è stato rediretto
// fd = 2 scrive forzatamente sul terminale
//	ANCHE SE è stato rediretto (posso forzare anche questo con 2>)
// Lo usiamo perchè consente di gestire output e errori separatamente
void	handle_error(t_list **stack_1, t_list **stack_2)
{
	if (stack_1)
		free_stack(stack_1);
	if (stack_2)
		free_stack(stack_2);
	write(2, "Error\n", 6);
}

t_list	*create_stack(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*new_node;
	int		new_content;
	int		i;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		if (!is_int(argv[i]))
			return (handle_error(&stack_a, NULL), NULL);
		new_content = ft_atoi(argv[i]);
		if (is_unique(stack_a, new_content) != 1)
			return (handle_error(&stack_a, NULL), NULL);
		new_node = ft_lstnew(new_content);
		if (!new_node)
			return (handle_error(&stack_a, NULL), NULL);
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}
