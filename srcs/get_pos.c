/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 08:55:13 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 13:51:22 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			can_place(t_map *m, t_piece *p, int i, int j)
{
	int		count;
	int		a;
	int		b;

	count = 0;
	a = -1;
	while (++a < p->piece_y)
	{
		b = -1;
		while (++b < p->piece_x)
		{
			if (p->piece[a][b] == '*')
				if (a + i >= m->m_y || b + j >= m->m_x)
					return (0);
			if (p->piece[a][b] == '*')
				if (ft_toupper(m->m[i + a][j + b]) == m->m_p)
					count++;
			if (p->piece[a][b] == '*')
				if (ft_toupper(m->m[i + a][j + b]) == m->e_p)
					return (0);
		}
	}
	if (count == 1)
		return (1);
	return (0);
}

int			count_pos(t_map *map, t_piece *piece)
{
	int num_pos;
	int i;
	int j;

	num_pos = 0;
	i = -1;
	while (++i < map->m_y)
	{
		j = -1;
		while (++j < map->m_x)
			if (can_place(map, piece, i, j))
				num_pos++;
	}
	return (num_pos);
}

int			get_pos(t_map *map, t_piece *piece)
{
	int positions;
	int i;

	i = 0;
	positions = count_pos(map, piece);
	if (positions == 0)
	{
		ft_putendl_fd("0 0", 1);
		return (1);
	}
	piece->pos = (int **)malloc(sizeof(int *) * positions);
	while (i < positions)
	{
		piece->pos[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	pick_algo(map, piece);
	return (0);
}
