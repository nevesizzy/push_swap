/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:19:00 by isneves-          #+#    #+#             */
/*   Updated: 2024/09/26 17:58:10 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// desloca todos os elementos da pilha a para cima em 1
void ra(t_list **a)
{
    t_list *first, *last;
    if (!*a || !(*a)->next) return;
    first = *a;
    last = *a;
    while (last->next) last = last->next;
    *a = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "ra\n", 3);
}
// desloca todos os elementos da pilha b em 1
void rb(t_list **b)
{
    t_list *first, *last;
    if (!*b || !(*b)->next) return;
    first = *b;
    last = *b;
    while (last->next) last = last->next;
    *b = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "rb\n", 3);
}
// ra e rb ao mesmo tempo
void rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);
    write(1, "rr\n", 3);
}
// desloca todos os elementos da pilha a para baixo em 1
// O último elemento se torna o primeiro.
void rra(t_list **a)
{
    t_list *prev, *last;
    if (!*a || !(*a)->next) return;
    last = *a;
    prev = NULL;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *a;
    *a = last;
    write(1, "rra\n", 4);
}