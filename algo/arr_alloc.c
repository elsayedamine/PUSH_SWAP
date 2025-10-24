/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:20:41 by aelsayed          #+#    #+#             */
/*   Updated: 2025/10/24 20:02:31 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot)
			ft_swap(&arr[++i], &arr[j]);
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = ft_partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

void	fill_arr(t_stack *head, int *arr, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = head;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->content;
		tmp = tmp->next;
	}
	quick_sort(arr, 0, size - 1);
}

void	arr_alloc(t_arr *arr, t_stack *a)
{
	arr->size = ft_size(a);
	arr->arr = (int *)malloc(arr->size * sizeof(int));
	if (!arr->arr)
		return (ft_clear(&a), exit(1));
	fill_arr(a, arr->arr, arr->size);
}
