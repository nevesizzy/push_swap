/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:07:37 by isneves-          #+#    #+#             */
/*   Updated: 2024/09/17 19:07:38 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Retorna o índice de um valor específico na pilha
int get_index(t_list *stack, int value)
{
    int index = 0;

    while (stack)
    {
        if (stack->value == value)
            return index;
        stack = stack->next;
        index++;
    }
    return -1; // Retorna -1 se o valor não for encontrado
}

// Função auxiliar para ordenar um array usando bubble sort
void bubble_sort(int *arr, int size)
{
    int temp;
    int i = 0;
    int j;

    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

// Calcula o pivô como o valor mediano da pilha
int find_pivot(t_list *stack)
{
    int *values = stack_to_array(stack);
    int size = stack_size(stack);
    int pivot;

    bubble_sort(values, size); // Ordena o array
    pivot = values[size / 2];  // Seleciona o valor mediano como pivô
    free(values);

    return pivot;
}
