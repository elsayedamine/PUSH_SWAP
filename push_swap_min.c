/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:45:16 by aelsayed          #+#    #+#             */
/*   Updated: 2025/01/29 21:38:28 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap3(t_stack **head)
{
	t_sort	num;

	num.a = (**head).content;
	num.b = (**head).next->content;
	num.c = (**head).next->next->content;
	if (num.b > num.a && num.b > num.c && num.a > num.c)
		rra_rrb(head, 'a');
	if (num.b > num.a && num.b > num.c && num.a < num.c)
	{
		rra_rrb(head, 'a');
		sa_sb(head, 'a');
	}
	if (num.c > num.a && num.c > num.b && num.a > num.b)
		sa_sb(head, 'a');
	if (num.a > num.b && num.a > num.c && num.b > num.c)
	{
		sa_sb(head, 'a');
		rra_rrb(head, 'a');
	}
	if (num.a > num.b && num.a > num.c && num.b < num.c)
		ra_rb(head, 'a');
}

int	min_pos(t_stack *a)
{
	t_stack	*tmp;
	int		min;
	int		min_pos;
	int		pos;

	tmp = a;
	min = tmp->content;
	min_pos = 0;
	pos = 0;
	while (tmp)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

void	move_min_to_top(t_stack **a, int pos)
{
	int	size;

	size = ft_size(*a);
	if (pos <= size / 2)
		while (pos--)
			ra_rb(a, 'a');
	else
		while (pos++ < size)
			rra_rrb(a, 'a');
}

void	push_swap_min(t_stack **a, t_stack **b, t_arr arr)
{
	if (arr.size <= 5)
	{
		if (ft_size(*a) == 2)
			return (sa_sb(a, 'a'));
		if (ft_size(*a) == 3)
			return (push_swap3(a));
		move_min_to_top(a, min_pos(*a));
		pa_pb(a, b, 'b');
		if (ft_size(*a) == 4)
		{
			move_min_to_top(a, min_pos(*a));
			pa_pb(a, b, 'b');
		}
		push_swap3(a);
		pa_pb(b, a, 'a');
		if (ft_size(*b))
			pa_pb(b, a, 'a');
		return (ft_clear(a), free(arr.arr), exit(0));
	}
}
