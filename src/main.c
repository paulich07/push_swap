/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:11:17 by plichota          #+#    #+#             */
/*   Updated: 2025/04/03 05:59:27 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void    print_stack(t_list *stack)
{
	if (!stack)
	{
		printf("(nil)\n");
		return;
	}
	printf("------<s\n");
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
	printf("------<e\n");
} */

/* void    print_double_stack(t_list *stack_a, t_list *stack_b)
{
	printf("\n");
	printf("___  ___\n");
	while (stack_a || stack_b)
	{
		if (stack_a && stack_a->content) {
			printf("%d     ", stack_a->content);
			stack_a = stack_a->next;
		}
		else
		{
			printf("      ");
		}

		if (stack_b && stack_b->content) {
			printf("%d", stack_b->content);
			stack_b = stack_b->next;
		}
		printf("\n");
	}
	printf("___  ___\n");
	printf(" A    B \n\n");
} */

void	push_swap_algo(t_list **stack_a, t_list **stack_b)
{
	int	median;

	median = 0;
	if (!stack_a || !(*stack_a))
		return (handle_error(stack_a, 0));
	if (is_sorted(*stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 2)
	{
		rotate(stack_a, "a", 0);
		return ;
	}
	if (ft_lstsize(*stack_a) > 3)
	{
		median = calculate_median(*stack_a, (ft_lstsize(*stack_a) - 3));
		while (ft_lstsize(*stack_a) > 3)
			insert_element_by_median(stack_b, stack_a, median);
	}
	if (ft_lstsize(*stack_a) == 3)
		sort_three_elem(stack_a, "a");
	if (ft_lstsize(*stack_b) > 0)
		insert_sorted_stack(stack_a, stack_b);
	rotate_stack_to_start(stack_a);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (-1);
	stack_a = create_stack(argc, argv);
	if (!stack_a)
		return (-2);
	push_swap_algo(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
