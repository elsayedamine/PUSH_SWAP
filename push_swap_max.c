/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:59:28 by aelsayed          #+#    #+#             */
/*   Updated: 2025/01/29 21:46:43 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushtob(t_stack **s_a, t_stack **s_b, int *arr, t_var *var)
{
	while (*s_a)
	{
		if ((*s_a)->content <= arr[var->start])
		{
			pa_pb(s_a, s_b, 'b');
			ra_rb(s_b, 'b');
			if (var->end < var->i - 1)
				var->end++;
			if (var->start + 1 < var->end)
				var->start++;
		}
		else if ((*s_a)->content > arr[var->start]
			&& (*s_a)->content <= arr[var->end])
		{
			pa_pb(s_a, s_b, 'b');
			if ((*s_b)->next && (*s_b)->content < (*s_b)->next->content)
				sa_sb(s_b, 'b');
			if (var->end < var->i - 1)
				var->end++;
			if (var->start + 1 < var->end)
				var->start++;
		}
		else
			ra_rb(s_a, 'a');
	}
}

void	ft_pushtoa(t_stack **stack_b, t_stack **stack_a, int index, int i)
{
	if (index <= i / 2)
	{
		while (index-- > 0)
			ra_rb(stack_b, 'b');
	}
	else
	{
		while (index++ < i)
			rra_rrb(stack_b, 'b');
	}
	pa_pb(stack_b, stack_a, 'a');
}

void	ft_swaped(t_stack **stack_a, t_stack **stack_b, t_arr arr)
{
	t_var	var;

	if (arr.size <= 100 && arr.size)
		var.end = arr.size / 6;
	else if (arr.size > 100)
		var.end = arr.size / 12;
	var.start = 0;
	var.i = arr.size;
	ft_pushtob(stack_a, stack_b, arr.arr, &var);
}

void	ft_sorted(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*temp;
	t_stack	*max;
	int		pos;
	int		index;

	while (*stack_b)
	{
		temp = *stack_b;
		pos = 0;
		index = 0;
		max = temp;
		while (temp)
		{
			if (max->content < temp->content)
			{
				max = temp;
				index = pos;
			}
			temp = temp->next;
			pos++;
		}
		ft_pushtoa(stack_b, stack_a, index, i);
		i--;
	}
}

void	push_swap_max(t_stack **a, t_stack **b, t_arr arr)
{
	ft_swaped(a, b, arr);
	ft_sorted(a, b, arr.size);
}
