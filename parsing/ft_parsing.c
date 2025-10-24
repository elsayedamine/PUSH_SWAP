/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:11:10 by aelsayed          #+#    #+#             */
/*   Updated: 2025/10/24 20:02:05 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_onlydigit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] && (ft_isdigit(str[i])))
		i++;
	if (!str[i])
		return (1);
	return (0);
}

void	ft_isrepeat(t_stack *head)
{
	t_stack	*store1;
	t_stack	*store2;

	store1 = head;
	store2 = head;
	while (store2)
	{
		store1 = store2->next;
		while (store1)
		{
			if (store1->content == store2->content)
				return (write(2, "Error\n", 6), ft_clear(&head), exit(1));
			store1 = store1->next;
		}
		store2 = store2->next;
	}
}

void	fill_split(char *s, t_stack **lst)
{
	char	**split;
	int		i;

	split = ft_split(s, ' ');
	if (!split || !*split)
		return (ft_free("2", split), write(2, "Error\n", 6), ft_clear(lst),
			exit(1));
	i = ft_arrlen(split) - 1;
	while (i >= 0)
	{
		if (ft_onlydigit(split[i]))
			ft_addfront(lst, ft_new(ft_lstatoi(split[i--], lst, split)));
		else
			return (ft_free("2", split), write(2, "Error\n", 6), ft_clear(lst),
				exit(1));
	}
	ft_free("2", split);
	return ;
}

int	ft_issorted(t_stack **stack_a, int i)
{
	t_stack	*temp;

	if (i == 1)
		return (ft_clear(stack_a), exit(0), 0);
	temp = *stack_a;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (ft_clear(stack_a), exit(0), 0);
}

int	ft_parsing(char **av, int ac, t_stack **head)
{
	int	i;

	i = ac - 1;
	while (i)
	{
		if (ft_onlydigit(av[i]))
			ft_addfront(head, ft_new(ft_lstatoi(av[i--], head, NULL)));
		else if (ft_strchr(av[i], ' '))
			fill_split(av[i--], head);
		else
			return (ft_clear(head), write(2, "Error\n", 6), 0);
	}
	ft_isrepeat(*head);
	ft_issorted(head, ft_size(*head));
	return (1);
}
