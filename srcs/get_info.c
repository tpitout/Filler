/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 08:54:52 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/23 10:39:05 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	bot(t_map *m, t_piece *piece)
{
	char	*line;
	char	*p;
	int		player;

	get_next_line(0, &line);
	p = ft_strchr(line, 'p');
	p++;
	player = ft_atoi(p);
	if (player == 1)
	{
		m->m_p = 'O';
		m->e_p = 'X';
	}
	else if (player == 2)
	{
		m->m_p = 'X';
		m->e_p = 'O';
	}
	ft_strdel(&line);
}

void	mapsize(t_map *m, char *line)
{
	int y;
	int x;
	int i;

	y = 0;
	x = 0;
	i = 0;
	while (!(ft_isdigit(line[i])))
		i++;
	while (ft_isdigit(line[i]))
	{
		y = (y * 10) + (line[i] - '0');
		i++;
	}
	while (!(ft_isdigit(line[i])))
		i++;
	while (ft_isdigit(line[i]))
	{
		x = (x * 10) + (line[i] - '0');
		i++;
	}
	m->m_x = x;
	m->m_y = y;
}

void	get_map(t_map *m)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	mapsize(m, line);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	m->m = (char **)malloc(sizeof(char *) * m->m_y + 1);
	i = 0;
	while (i < m->m_y)
	{
		get_next_line(0, &line);
		m->m[i] = (char *)malloc(sizeof(char) * m->m_x + 1);
		m->m[i] = ft_strdup((char const *)&line[4]);
		ft_strdel(&line);
		i++;
	}
	if (m->m_x < 18)
		m->mn = 0;
	else if (m->m_x > 18 && m->m_x < 41)
		m->mn = 1;
	else
		m->mn = 2;
}

void	piecesize(t_piece *piece, char *line)
{
	int y;
	int x;
	int i;

	y = 0;
	x = 0;
	i = 0;
	while (!(ft_isdigit(line[i])))
		i++;
	while (ft_isdigit(line[i]))
	{
		y = (y * 10) + (line[i] - '0');
		i++;
	}
	while (!(ft_isdigit(line[i])))
		i++;
	while (ft_isdigit(line[i]))
	{
		x = (x * 10) + (line[i] - '0');
		i++;
	}
	piece->piece_x = x;
	piece->piece_y = y;
}

void	get_piece(t_piece *p)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	piecesize(p, line);
	ft_strdel(&line);
	p->piece = (char **)malloc(sizeof(char *) * p->piece_y + 1);
	i = 0;
	while (i < p->piece_y)
	{
		get_next_line(0, &line);
		p->piece[i] = (char *)malloc(sizeof(char) * p->piece_x + 1);
		p->piece[i] = ft_strdup((char const *)line);
		ft_strdel(&line);
		i++;
	}
}
