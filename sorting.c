/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:29:48 by isneves-          #+#    #+#             */
/*   Updated: 2024/09/17 19:37:14 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stack(t_list **a, t_list **b)
{
    while (!is_sorted(*a))
    {
        // Simplesmente empurre os números menores para a pilha b
        while (stack_size(*a) > 3 && !is_sorted(*a))
            pb(a, b);
        // Ordenar 3 elementos
        if ((*a)->value > (*a)->next->value)
            sa(a);
        if ((*a)->next->value > (*a)->next->next->value)
            ra(a);
        if ((*a)->value > (*a)->next->value)
            sa(a);
        // Mova de volta para a pilha a
        while (*b)
            pa(a, b);
    }
}
