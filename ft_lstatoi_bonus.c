/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstatoi_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:53:02 by aelsayed          #+#    #+#             */
/*   Updated: 2025/02/08 22:49:13 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_clear(t_stack **lst)
{
	t_stack	*store;

	if (lst && *lst)
	{
		while (*lst)
		{
			store = (*lst)->next;
			free(*lst);
			*lst = store;
		}
		*lst = NULL;
	}
}

int	ft_lstatoi(char const *str, t_stack **lst, char **spl)
{
	unsigned int	i;
	int				sign;
	long			n;

	i = 0;
	sign = 1;
	n = 0;
	if (!ft_strncmp(str, "2147483648", 10) || !*str || \
			!ft_strncmp(str, "+2147483648", 11))
		return (ft_clear(lst), write(2, "Error\n", 6), exit(1), 0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] <= '9' && str[i] >= '0')
	{
		n = n * 10 + (str[i++] - '0');
		if (n > 2147483648)
			return (ft_clear(lst), ft_free("2", spl), write(2, "Error\n", 6),
				exit(1), 0);
	}
	return (n * sign);
}
