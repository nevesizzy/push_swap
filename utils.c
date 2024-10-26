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

int ft_atoi(const char *str)
{
    int sign = 1;
    long result = 0;

    while (*str == ' ' || (*str >= 9 && *str <= 13)) // Skip whitespace
        str++;
    if (*str == '-' || *str == '+') // Handle sign
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9') // Convert string to int
    {
        result = result * 10 + (*str - '0');
        str++;
        if (result * sign > INT_MAX) // Check for overflow
            return (-1); // Handle overflow
        if (result * sign < INT_MIN) // Handle underflow
            return (0);
    }
    return (result * sign);
}
