/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 02:56:07 by plichota          #+#    #+#             */
/*   Updated: 2025/04/04 02:48:41 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// utilizzo: ./checker 1 3 2 4    (ovvero lo stack)
// se argc < 2 non fa niente (ovvero se scrivo "./checker" senza argomenti)
// se passo: lettere,
//           stringa vuota ./checker ""
//           numeri non interi (maggiori di MAXINT o minori di MININT)
//           parametri duplicati
// stampo Error\n
// quando presso CTRL+D finisce lettura e restituisce OK o KO

// quando runno ./checker 0 1 2 e poi CTRL+D deve restituire OK
// quando runno ./checker 0 1 2 e poi CTRL+D deve restituire OK

#include "checker.h"

int	parse_move(char *move, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(move, "ra\n", 3) == 0)
		rotate(stack_a, "a", 1);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rotate(stack_b, "b", 1);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		double_rotate(stack_a, stack_b, 1);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		reverse_rotate(stack_a, "a", 1);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		reverse_rotate(stack_b, "b", 1);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		double_reverse_rotate(stack_a, stack_b, 1);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		push_to(stack_a, stack_b, "a", 1);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		push_to(stack_b, stack_a, "b", 1);
	else if (ft_strncmp(move, "sa\n", 3) == 0)
		swap_first(stack_a, "a", 1);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		swap_first(stack_b, "b", 1);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		double_swap(stack_a, stack_b, 1);
	else
		return (0);
	return (1);
}

int	read_moves(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!parse_move(line, stack_a, stack_b))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = create_stack(argc, argv);
	if (!stack_a)
		return (0);
	stack_b = NULL;
	if (!read_moves(&stack_a, &stack_b))
		return (handle_error(&stack_a, &stack_b), 0);
	if (stack_b != NULL)
		return (handle_error(&stack_a, &stack_b), 0);
	if (is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
