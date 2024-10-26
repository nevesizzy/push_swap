/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:07:21 by isneves-          #+#    #+#             */
/*   Updated: 2024/09/17 19:07:22 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ainda nao sei se vou calcular dessa forma, foi apenas uma possibilidade

#include "push_swap.h"

// Calcula o número de rotações para trazer o valor `value` ao topo
int calculate_rotations_to_top(t_list *stack, int value)
{
    int index = get_index(stack, value);
    int size = stack_size(stack);

    if (index <= size / 2)
        return index;            // Rotação normal
    else
        return size - index;     // Rotação reversa
}

// Encontra o menor número de movimentos para inserir o valor `b_value` na posição correta em `a`
int calculate_insertion_cost(t_list *a, int b_value)
{
    t_list *current = a;
    int rotations = 0;

    while (current && current->next)
    {
        if (current->value < b_value && current->next->value > b_value)
            break;
        current = current->next;
        rotations++;
    }
    return rotations;
}

// Encontra o movimento mais barato para mover um elemento de `b` para `a`
t_list *find_cheapest_move(t_list *a, t_list *b)
{
    t_list *current = b;
    t_list *cheapest = NULL;
    int min_cost = INTMAX;

    while (current)
    {
        int rotations_b = calculate_rotations_to_top(b, current->value);
        int rotations_a = calculate_insertion_cost(a, current->value);
        int total_cost = rotations_b + rotations_a;

        if (total_cost < min_cost)
        {
            min_cost = total_cost;
            cheapest = current;
        }
        current = current->next;
    }
    return cheapest;
}

void execute_cheapest_move(t_list **a, t_list **b)
{
    t_list *cheapest = find_cheapest_move(*a, *b);
    int rotations_b = calculate_rotations_to_top(*b, cheapest->value);
    int rotations_a = calculate_insertion_cost(*a, cheapest->value);

    // Ajusta `b` para colocar o `cheapest` no topo
    while (rotations_b > 0)
    {
        if (get_index(*b, cheapest->value) <= stack_size(*b) / 2)
            rb(b);
        else
            rrb(b);
        rotations_b--;
    }

    // Ajusta `a` para a posição correta de inserção
    while (rotations_a > 0)
    {
        if (calculate_insertion_cost(*a, cheapest->value) <= stack_size(*a) / 2)
            ra(a);
        else
            rra(a);
        rotations_a--;
    }

    // Move o elemento de `b` para `a`
    pa(a, b);
}
