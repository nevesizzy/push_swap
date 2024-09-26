/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:05:24 by isneves-          #+#    #+#             */
/*   Updated: 2024/09/17 20:09:20 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;
    int i = 1;

    if (argc < 2)
        return 0;
    while (i < argc)
    {
        int value = ft_atoi(argv[i]);
        t_list *new_node = create_node(value);
        if (!new_node)
            return 1;
        new_node->next = stack_a;
        stack_a = new_node;
        i++;
    }

    sort_stack(&stack_a, &stack_b);

    free_stack(&stack_a);
    free_stack(&stack_b);
    return 0;
}

