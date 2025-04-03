/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:56:10 by plichota          #+#    #+#             */
/*   Updated: 2025/04/03 04:50:00 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void    swap_first(t_list **stack, char *s, int checker)
{
    t_list  *p;
    t_list  *p2;

    if (s && !checker)
    {
        write(1, "s", 1);
        write(1, s, 1);
        write(1, "\n", 1);
    }
    if (!stack || !*stack || !(*stack)->next)
        return;
    p = *stack;
    p2 = p->next;
    p->next = p2->next;
    p2->next = p;
    *stack = p2;
}

void    double_swap(t_list **stack1, t_list **stack2, int checker)
{   
    if (!checker)
        write(1, "ss\n", 3);
    swap_first(stack1,  NULL, checker);
    swap_first(stack2,  NULL, checker);
}

// Push to stack1 from stack2
void    push_to(t_list **stack1, t_list **stack2, char *s, int checker)
{
    t_list  *temp;

    if (!stack1 || !stack2 || !(*stack2))
        return;
    if (s && !checker)
    {
        write(1, "p", 1);
        write(1, s, 1);
        write(1, "\n", 1);
    }
    temp = *stack2;
    *stack2 = (*stack2)->next;
    temp->next = *stack1;
    *stack1 = temp;
}

