/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:40:58 by isneves-          #+#    #+#             */
/*   Updated: 2024/09/17 20:37:11 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct s_list
{
    int value;
    struct s_list *next;
} t_list;

// Operações de pilha
void sa(t_list **a);
void sb(t_list **b);
void ss(t_list **a, t_list **b);
void pa(t_list **a, t_list **b);
void pb(t_list **a, t_list **b);
void ra(t_list **a);
void rb(t_list **b);
void rr(t_list **a, t_list **b);
void rra(t_list **a);
void rrb(t_list **b);
void rrr(t_list **a, t_list **b);

// Algoritmos de ordenação
void sort_stack(t_list **a, t_list **b);
void tiny_sort(t_list **a);
void quick_sort_partition(t_list **a, t_list **b, int pivot);
void radix_sort(t_list **a, t_list **b);

// Funções utilitárias
t_list *create_node(int value);
void free_stack(t_list **stack);
int is_sorted(t_list *stack);
int stack_size(t_list *stack);
int find_max_value(t_list *stack);

#endif
