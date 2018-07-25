/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:17:32 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/25 12:10:16 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		algo2o(t_map *m, t_piece *p)
{
	int		i;
	int		j;
	int		a;

	a = 0;
	i = m->m_y;
	if (ft_strstr(m->m[0], "O"))
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
		(ft_strstr(m->m[0], "O") ? i++ : i--);
	}
}

void		algo2x(t_map *m, t_piece *p)
{
	int		i;
	int		j;
	int		a;

	i = 0;
	if (ft_strstr(m->m[m->m_y - 1], "X"))
		i = m->m_y;
	a = 0;
	while (i <= m->m_y && i >= 0)
	{
		j = 0;
		while (j <= m->m_x && j >= 0)
		{
			if (can_place(m, p, i, j))
				valid(p, a, i, j);
			j++;
			j++;
		}
		(ft_strstr(m->m[m->m_y - 1], "X") ? i-- : i++);
	}
}

void		algo3o1(t_map *m, t_piece *p)
{
	int		i;
	int		j;
	int		a;

	a = 0;
	i = m->m_y;
	if (ft_strstr(m->m[0], "O"))
		i = 0;
	while (i >= 0 && i <= m->m_y)
	{
		j = m->m_x;
		while (j <= m->m_x && j >= 0)
		{
			if (can_place(m, p, j, i))
				valid(p, a, j, i);
			j--;
			j--;
		}
		(ft_strstr(m->m[0], "O") ? i++ : i--);
	}
	m->k = (m->k == 0 ? 1 : 0);
}

void		algo3o(t_map *m, t_piece *p)
{
	int		i;
	int		j;
	int		a;

	a = 0;
	i = 0;
	while (i >= 0 && i <= m->m_y)
	{
		j = 0;
		while (j >= 0 && j <= m->m_x)
		{
			if (can_place(m, p, i, j))
				valid(p, a, i, j);
			j++;
		}
		i++;
		i++;
	}
	m->k = (m->k == 0 ? 1 : 0);
}

void		g(t_map *m, int y, int x)
{
	if (m->m[y][x] == 'X')
	{
		ft_putstr_fd("\x1B[31m", 2);
		ft_putstr_fd("█", 2);
	}
	else if (m->m[y][x] == 'O')
	{
		ft_putstr_fd("\x1B[32m", 2);
		ft_putstr_fd("█", 2);
	}
	else
	{
		ft_putstr_fd("\x1B[0m", 2);
		ft_putstr_fd("░", 2);
	}
}
