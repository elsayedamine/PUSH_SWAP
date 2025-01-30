/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:33:46 by aelsayed          #+#    #+#             */
/*   Updated: 2025/01/29 21:38:04 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_arr	arr;

	a = NULL;
	b = NULL;
	if (ac == 1 || !ft_parsing(av, ac, &a))
		return (1);
	arr_alloc(&arr, a);
	push_swap_min(&a, &b, arr);
	push_swap_max(&a, &b, arr);
	return (ft_clear(&a), free(arr.arr), 0);
}
