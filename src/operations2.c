/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:43:03 by plichota          #+#    #+#             */
/*   Updated: 2025/04/03 04:44:13 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// The last element becomes the first one.
void    rotate(t_list **stack, char *s, int checker)
{
    t_list  *temp;
    t_list  *last;

    if (s && !checker)
    {
        write(1, "r", 1);
        write(1, s, 1);
        write(1, "\n", 1);
    }
    if (!stack || !(*stack) || !(*stack)->next)
        return;
    temp = *stack;
    *stack = (*stack)->next;
    last = ft_lstlast(*stack);
    last->next = temp;
    temp->next = NULL;
}

void    double_rotate(t_list **stack1, t_list **stack2, int checker)
{
    if (!checker)
        write(1, "rr\n", 3);
    rotate(stack1, NULL, checker);
    rotate(stack2, NULL, checker);
}

// The last element becomes the first one
void    reverse_rotate(t_list **stack, char *s, int checker)
{
    t_list *prev_last;
    t_list *last;

    if (s && !checker)
    {
        write(1, "rr", 2);
        write(1, s, 1);
        write(1, "\n", 1);
    }
    if (!stack || !(*stack) || !(*stack)->next)
        return;
    prev_last = *stack;
    while ((prev_last->next)->next != NULL)
        prev_last = prev_last->next;
    last = prev_last->next;
    prev_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

void    double_reverse_rotate(t_list **stack1, t_list **stack2, int checker)
{
    if (!checker)
        write(1, "rrr\n", 4);
    reverse_rotate(stack1, NULL, checker);
    reverse_rotate(stack2, NULL, checker);
}