/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:14:48 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/25 12:10:43 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		algo0x(t_map *m, t_piece *p)
{
	int		i;
	int		j;
	int		a;

	a = 0;
	i = (ft_strstr(m->m[0], "X") ? 0 : m->m_y);
	while (i <= m->m_y && i >= 0)
	{
		j = m->m_x;
		while (j <= m->m_x && j >= 0)
		{
			if (can_place(m, p, i, j))
				valid(p, a, i, j);
			j--;
		}
		(ft_strstr(m->m[0], "X") ? i++ : i--);
	}
}

void		algo0o(t_map *m, t_piece *p)
{
	int		i;
	int		j;
	int		a;

	a = 0;
	if (!(ft_strstr(m->m[0], "O")))
		i = (ft_strstr(m->m[8], "X") ? m->m_y : 0);
	i = (ft_strstr(m->m[0], "O") ? 0 : m->m_y);
	while (i >= 0 && i <= m->m_y)
	{
		j = 0;
		while (j >= 0 && j <= m->m_x)
		{
			if (can_place(m, p, i, j))
				valid(p, a, i, j);
			j++;
		}
		(ft_strstr(m->m[0], "O") ? i++ : i--);
	}
}

void		algo1x(t_map *m, t_piece *p)
{
	int		i;
	int		j;
	int		a;

	a = 0;
	i = m->m_y;
	if (ft_strstr(m->m[0], "X"))
		i = 0;
	while (i >= 0 && i <= m->m_y)
	{
		j = m->m_x;
		while (j <= m->m_x && j >= 0)
		{
			if (can_place(m, p, i, j))
				valid(p, a, i, j);
			j--;
		}
		(ft_strstr(m->m[0], "X") ? i++ : i--);
	}
}

void		algo1o(t_map *m, t_piece *p)
{
	int		i;
	int		j;
	int		a;

	i = (ft_strstr(m->m[m->m_y - 1], "O") ? m->m_y : 0);
	a = 0;
	while (i <= m->m_y && i >= 0)
	{
		j = 0;
		while (j <= m->m_x && j >= 0)
		{
			if (can_place(m, p, i, j))
				valid(p, a, i, j);
			j++;
		}
		(ft_strstr(m->m[m->m_y - 1], "O") ? i-- : i++);
	}
}

void		valid(t_piece *p, int a, int i, int j)
{
	p->pos[a][0] = i;
	p->pos[a][1] = j;
	a++;
}
