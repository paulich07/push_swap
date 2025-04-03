/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:27:18 by plichota          #+#    #+#             */
/*   Updated: 2025/04/03 06:32:30 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_moves
{
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
    int total_moves;
} t_moves;


// Main (da eliminare)
// void	print_stack(t_list *stack);
// void    print_double_stack(t_list *stack_a, t_list *stack_b);
void    push_swap_algo(t_list **stack_a, t_list **stack_b);

// Utils
t_list  *create_stack(int argc, char **argv);
void	handle_error(t_list **stack_1, t_list **stack_2);
int     is_unique(t_list *stack, int n);
void    free_stack(t_list **stack);
int     is_int (char *s);

// Operations
void	swap_first(t_list **stack, char *s, int checker);
void	double_swap(t_list **stack1, t_list **stack2, int checker);
void	push_to(t_list **stack1, t_list **stack2, char *s, int checker);
void	rotate(t_list **stack, char *s, int checker);


// Operations 2
void	double_rotate(t_list **stack1, t_list **stack2, int checker);
void	reverse_rotate(t_list **stack, char *s, int checker);
void	double_reverse_rotate(t_list **stack1, t_list **stack2, int checker);


// Operations Helpers
void    rotate_stack(t_list **stack, int rotations, char *s);
void    reverse_rotate_stack(t_list **stack, int rotations, char *s);
void    double_rotate_stack(t_list **stack1, t_list **stack2, int rotations);
void    double_reverse_rotate_stack(t_list **stack1, t_list **stack2, int rotations);

// Algorithms
void	insert_element_by_median(t_list **stack_a, t_list **stack_b, int m);
void	insertion_sort(int *arr, int l);
int		calculate_median(t_list *stack, int n);
void	sort_three_elem(t_list **head, char *s);

// Algorithms2
void	set_best_moves(t_moves **best, t_moves **current);
t_moves	*calculate_best_moves(t_list *stack_a, t_list *stack_b);
void	insert_sorted_stack(t_list **stack_a, t_list **stack_b);
void	rotate_stack_to_start(t_list **stack);

// Algorithms3
int		find_start_position(t_list *head);
int		is_max_or_min(t_list *elem, t_list *stack);
int     find_insertion_index(t_list *stack_a, t_list *stack_b);
int     is_sorted(t_list *stack);
int     get_min(int a, int b);

// Algorithms3 Helper
t_list	*get_list_elem_by_index(t_list *stack, int index);
t_moves *get_rotation_moves(t_list *stack_a, t_list *stack_b, int i);
t_moves *get_reverse_rotation_moves(t_list *stack_a, t_list *stack_b, int i);
t_moves *get_combined_rotation_moves(t_list *stack_a, t_list *stack_b, int i);


#endif