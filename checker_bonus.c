/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:42:48 by ahakki            #+#    #+#             */
/*   Updated: 2025/01/30 18:52:20 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_stack **a, t_stack **b, int c)
{
	sa_sb(a, 's');
	sa_sb(b, 's');
	if (c == 's')
		write(1, "ss\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra_rrb(a, 's');
	rra_rrb(b, 's');
	write(1, "rrr\n", 4);
}

int	push_swap_language(char *buffer, t_stack **a, t_stack **b)
{
	if (ft_strncmp(buffer, "sa\n", 3) == 0)
		return (sa_sb(a, 's'), 1);
	if (ft_strncmp(buffer, "sb\n", 3) == 0)
		return (sa_sb(b, 's'), 1);
	if (ft_strncmp(buffer, "ss\n", 3) == 0)
		return (ss(b, a, 's'), 1);
	if (ft_strncmp(buffer, "ra\n", 3) == 0)
		return (ra_rb(a, 's'), 1);
	if (ft_strncmp(buffer, "rb\n", 3) == 0)
		return (ra_rb(b, 's'), 1);
	if (ft_strncmp(buffer, "rr\n", 3) == 0)
		return (rr(b, a), 1);
	if (ft_strncmp(buffer, "rra\n", 4) == 0)
		return (rra_rrb(a, 's'), 1);
	if (ft_strncmp(buffer, "rrb\n", 4) == 0)
		return (rra_rrb(b, 's'), 1);
	if (ft_strncmp(buffer, "rrr\n", 4) == 0)
		return (rrr(b, a), 1);
	if (ft_strncmp(buffer, "pa\n", 3) == 0)
		return (pa_pb(b, a, 's'), 1);
	if (ft_strncmp(buffer, "pb\n", 3) == 0)
		return (pa_pb(a, b, 's'), 1);
	get_next_line(-1);
	return (ft_clear(a), ft_clear(b), write(2, "Error\n", 6), free(buffer),
		exit(1), 0);
}

void	ft_checker(t_stack **a, t_stack **b, int i)
{
	t_stack	*temp;

	if (ft_size(*a) != i)
		return (ft_clear(a), ft_clear(b), write(1, "KO\n", 3), exit(1));
	temp = *a;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (ft_clear(a), ft_clear(b), write(1, "KO\n", 3), exit(1));
		temp = temp->next;
	}
	return (ft_clear(a), ft_clear(b), write(1, "OK\n", 3), exit(0));
}

int	main(int ac, char **av)
{
	char	*buffer;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || !ft_parsing(av, ac, &stack_a))
		return (1);
	buffer = get_next_line(0);
	while (buffer)
	{
		push_swap_language(buffer, &stack_a, &stack_b);
		free(buffer);
		buffer = get_next_line(0);
	}
	ft_checker(&stack_a, &stack_b, ft_size(stack_a));
	return (ft_clear(&stack_a), ft_clear(&stack_b), 0);
}
