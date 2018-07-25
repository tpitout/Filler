/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 08:54:36 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/25 12:15:13 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		init(t_map *m, t_piece *piece)
{
	m->m_x = 0;
	m->m_y = 0;
	m->m = NULL;
	m->player = 0;
	piece->piece_x = 0;
	piece->piece_y = 0;
	piece->piece = NULL;
}

void		result(t_piece *piece)
{
	ft_putnbr_fd(piece->pos[0][0], 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(piece->pos[0][1], 1);
	ft_putchar_fd('\n', 1);
}

void		vis(t_map *m)
{
	int		y;
	int		x;

	y = 0;
	ft_putstr_fd("\e[1;1H\e\n\n\n", 2);
	ft_putstr_fd("\x1b[36m", 2);
	ft_putstr_fd("    ████████ ███████  █████ ██████   ██   ██\n", 2);
	ft_putstr_fd("       ██    ██    ██ ██    ██    ██  ██ ██  \n", 2);
	ft_putstr_fd("       ██    ███████  █████ ██    ██   ███   \n", 2);
	ft_putstr_fd("       ██    ██   ██  ██    ██    ██  ██ ██  \n", 2);
	ft_putstr_fd("       ██    ██    ██ █████ ██████   ██   ██ \n\n", 2);
	while (y <= m->m_y - 1)
	{
		x = 0;
		ft_putchar_fd('\t', 2);
		while (x <= m->m_x - 1)
		{
			g(m, y, x);
			x++;
		}
		y++;
		ft_putchar_fd('\n', 2);
	}
}

int			main(void)
{
	t_map	*m;
	t_piece	*piece;
	char	*first_line;

	m->k = 0;
	m = (t_map *)malloc(sizeof(*m));
	piece = (t_piece *)malloc(sizeof(*piece));
	init(m, piece);
	bot(m, piece);
	ft_putstr_fd("\e[1;1H\e[5J", 2);
	while (1)
	{
		get_map(m);
		vis(m);
		get_piece(piece);
		if (get_pos(m, piece))
			break ;
		result(piece);
	}
	free(m);
	free(piece);
	return (0);
}

void		pick_algo(t_map *m, t_piece *p)
{
	if (m->mn == 0 && m->m_p == 'X')
		algo0x(m, p);
	else if (m->mn == 0 && m->m_p == 'O')
		algo0o(m, p);
	else if (m->mn == 1 && m->m_p == 'X')
		algo1x(m, p);
	else if (m->mn == 1 && m->m_p == 'O')
		algo1o(m, p);
	else if (m->mn == 2 && m->m_p == 'X')
		algo2x(m, p);
	else if (m->mn == 2 && m->m_p == 'O')
	{
		if (m->k == 0)
			algo3o(m, p);
		else
			algo3o1(m, p);
	}
}
