/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:26:23 by dysotoma          #+#    #+#             */
/*   Updated: 2018/08/29 12:26:28 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	sort(char **arr, int low, int high, t_ls *ls)
{
	int pivot;
	int i;
	int j;

	pivot = high;
	i = low;
	j = high;
	while (i < j)
	{
		while (i < high && cmp(arr[i], arr[pivot], ls) <= 0)
			i++;
		while (j > low && cmp(arr[j], arr[pivot], ls) > 0)
			j--;
		ft_swap_array(&arr[i], &arr[j]);
	}
	return (i);
}

void		ft_qsort(char **arr, int low, int high, t_ls *ls)
{
	int part_index;

	if (low < high)
	{
		part_index = sort(arr, low, high, ls);
		ft_qsort(arr, low, part_index - 1, ls);
		ft_qsort(arr, part_index + 1, high, ls);
	}
}

static int	sort_struct(int low, int high, t_ls *ls)
{
	int	count[4];

	count[2] = high;
	count[0] = low;
	count[1] = high;
	while (count[0] < count[1])
	{
		count[3] = 0;
		while (count[0] < high && list_cmp(ls->list[count[0]]->sub_dir_list,
		ls->list[count[2]]->sub_dir_list, ls, count) <= 0)
			count[0]++;
		count[3] = 1;
		while (count[1] > low && list_cmp(ls->list[count[1]]->sub_dir_list,
		ls->list[count[2]]->sub_dir_list, ls, count) > 0)
			count[1]--;
		if (count[0] < count[1])
			ft_swap((void**)&ls->list[count[0]], (void**)&ls->list[count[1]]);
	}
	return (count[1]);
}

void		ft_qsort_struct(int low, int high, t_ls *ls)
{
	int part_index;

	if (low < high)
	{
		part_index = sort_struct(low, high, ls);
		ft_qsort_struct(low, part_index - 1, ls);
		ft_qsort_struct(part_index, high, ls);
	}
}
