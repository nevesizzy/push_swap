/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:32:45 by isneves-          #+#    #+#             */
/*   Updated: 2024/09/26 17:58:51 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// desloca todos os elementos da pilha b para baixo em 1
// O último elemento se torna o primeiro
void rrb(t_list **b)
{
    t_list *prev, *last;
    if (!*b || !(*b)->next) return;
    last = *b;
    prev = NULL;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *b;
    *b = last;
    write(1, "rrb\n", 4);
}
// rra e rrb ao mesmo tempo
void rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
    write(1, "rrr\n", 4);
}
