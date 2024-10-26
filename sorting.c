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

void tiny_sort(t_list **a)
{
    if (stack_size(*a) == 2)
    {
        if ((*a)->value > (*a)->next->value)
            sa(a);
    }
    else if (stack_size(*a) == 3)
    {
        if ((*a)->value > (*a)->next->value)
            sa(a);
        if ((*a)->next->value > (*a)->next->next->value)
            ra(a);
        if ((*a)->value > (*a)->next->value)
            sa(a);
    }
    else
    {
        while (stack_size(*a) > 3)
            pb(a, b);
        tiny_sort(a);  // Ordena os 3 elementos restantes em `a`
        while (*b)
            pa(a, b);   // Move de volta para `a` em ordem correta
    }
}

// Move elementos menores que o pivô para `b`
void quick_sort_partition(t_list **a, t_list **b, int pivot)
{
    int size = stack_size(*a);
    int moves = 0;

    while (moves < size)
    {
        if ((*a)->value <= pivot)
            pb(a, b);  // Move valores menores ou iguais ao pivô para `b`
        else
            ra(a);     // Rotaciona `a` se o valor for maior que o pivô
        moves++;
    }
}

void quick_sort_stack(t_list **a, t_list **b)
{
    int size = stack_size(*a);
    int pivot;

    while (size > 3 && !is_sorted(*a))
    {
        pivot = find_pivot(*a);  // Função para determinar o pivô
        quick_sort_partition(a, b, pivot);  // Move menores para `b`
        size = stack_size(*a); // Recalcula o tamanho da pilha `a`
    }

    // Ordena os últimos 3 elementos restantes em `a`
    tiny_sort(a);
    
    // Reinserir os elementos de `b` para `a`
    while (*b)
    {
        int max_val = find_max_value(*b);
        while ((*b)->value != max_val)
        {
            if (get_index(*b, max_val) < stack_size(*b) / 2)
                rb(b);
            else
                rrb(b);
        }
        pa(a, b);  // Move o maior valor de volta para `a`
    }
}

void radix_sort(t_list **a, t_list **b)
{
    int max_bits = 0;
    int max_num = find_max_value(*a);
    int size = stack_size(*a);

    while ((max_num >> max_bits) != 0)
        max_bits++;

    for (int i = 0; i < max_bits; i++)
    {
        int j = 0;
        while (j < size)
        {
            if ((((*a)->value >> i) & 1) == 0)
                pb(a, b);  // Move para `b` se o bit atual for 0
            else
                ra(a);     // Mantém em `a` se o bit atual for 1
            j++;
        }

        // Move todos os elementos de volta para `a`
        while (*b)
            pa(a, b);
    }
}

void sort_stack(t_list **a, t_list **b)
{
    int size = stack_size(*a);

    if (size <= 5)
        tiny_sort(a);
    else if (size <= 100)
        quick_sort_stack(a, b);
    else
        radix_sort(a, b);
}
