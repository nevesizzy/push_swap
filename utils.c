#include "push_swap.h"

int find_max_value(t_list *stack)
{
    int max = stack->value;
    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return max;
}

int *stack_to_array(t_list *stack)
{
    int size = stack_size(stack);
    int *array = malloc(size * sizeof(int));
    int i = 0;

    while (stack)
    {
        array[i++] = stack->value;
        stack = stack->next;
    }
    return array;
}

int stack_size(t_list *stack)
{
    int size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return size;
}

int is_sorted(t_list *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return 0;
        stack = stack->next;
    }
    return 1;
}
