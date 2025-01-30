/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:43:04 by aelsayed          #+#    #+#             */
/*   Updated: 2025/01/30 16:53:47 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack **a, int c)
{
	if (!a || !*a || !(*a)->next || ft_size(*a) < 2)
		return ;
	ft_swap(&((*a)->content), &((*a)->next->content));
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	pa_pb(t_stack **b, t_stack **a, int c)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	tmp = *b;
	*b = tmp->next;
	ft_addfront(a, tmp);
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}

void	ra_rb(t_stack **a, int c)
{
	t_stack	*tmp;

	tmp = *a;
	*a = tmp->next;
	ft_addback(a, tmp);
	tmp->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra_rb(a, 's');
	ra_rb(b, 's');
	write(1, "rr\n", 3);
}

void	rra_rrb(t_stack **a, int c)
{
	t_stack	*tmp;
	t_stack	*fin;

	if (!(*a))
		return ;
	tmp = ft_last(*a);
	fin = *a;
	while (fin->next->next != NULL)
		fin = fin->next;
	tmp->next = *a;
	*a = tmp;
	fin->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}
