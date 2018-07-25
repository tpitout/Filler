/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 09:52:53 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/24 15:37:48 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct		s_map
{
	int				m_x;
	int				m_y;
	char			**m;
	int				player;
	char			m_p;
	char			e_p;
	int				mn;
	int				k;
}					t_map;

typedef struct		s_piece
{
	int				piece_x;
	int				piece_y;
	char			**piece;
	int				**pos;
}					t_piece;

void				valid(t_piece *piece, int a, int i, int j);
void				statement(t_map *m);
int					get_pos(t_map *m, t_piece *piece);
void				bot(t_map *m, t_piece *piece);
void				get_map(t_map *m);
void				get_piece(t_piece *piece);
void				pick_algo(t_map *map, t_piece *piece);
void				algo0x(t_map *m, t_piece *piece);
void				algo1x(t_map *m, t_piece *piece);
void				algo0o(t_map *m, t_piece *piece);
void				algo3o(t_map *m, t_piece *piece);
void				algo2o(t_map *m, t_piece *piece);
void				algo2x(t_map *m, t_piece *piece);
void				algo3o1(t_map *m, t_piece *piece);
void				algo1o(t_map *m, t_piece *piece);
int					can_place(t_map *m, t_piece *piece, int i, int j);
void				vis(t_map *m);

#endif
