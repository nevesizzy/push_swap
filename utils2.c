/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabella <isabella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:34:26 by isabella          #+#    #+#             */
/*   Updated: 2024/10/26 15:40:02 by isabella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *create_node(int value)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL; // Check for malloc failure

    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void free_stack(t_list **stack)
{
    t_list *current = *stack;
    t_list *next_node;

    while (current != NULL)
    {
        next_node = current->next; // Store the next node
        free(current); // Free the current node
        current = next_node; // Move to the next node
    }
    *stack = NULL; // Set the stack pointer to NULL after freeing
}
