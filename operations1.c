/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:18:50 by isneves-          #+#    #+#             */
/*   Updated: 2024/09/26 17:56:13 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//troca os 2 primeiros elementos no topo da pilha a
void sa(t_list **a)
{
    t_list *first, *second;
    if (!*a || !(*a)->next) return;
    first = *a;
    second = (*a)->next;
    first->next = second->next;
    second->next = first;
    *a = second;
    write(1, "sa\n", 3);
}
// troca os 2 primeiros elementos no topo da pilha b
void sb(t_list **b)
{
    t_list *first, *second;
    if (!*b || !(*b)->next) return;
    first = *b;
    second = (*b)->next;
    first->next = second->next;
    second->next = first;
    *b = second;
    write(1, "sb\n", 3);
}
//sa e  sb ao mesmo tempo
void ss(t_list **a, t_list **b)
{
    sa(a);
    sb(b);
    write(1, "ss\n", 3);
}
// pega o primeiro elemento no topo de b e o coloca no topo de a
void pa(t_list **a, t_list **b)
{
    t_list *temp;
    if (!*b) return;
    temp = *b;
    *b = (*b)->next;
    temp->next = *a;
    *a = temp;
    write(1, "pa\n", 3);
}
// pega o primeiro elemento no topo de a e o coloca no topo de b
void pb(t_list **a, t_list **b)
{
    t_list *temp;
    if (!*a) return;
    temp = *a;
    *a = (*a)->next;
    temp->next = *b;
    *b = temp;
    write(1, "pb\n", 3);
}

