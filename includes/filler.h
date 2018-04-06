/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:39:33 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/22 19:27:08 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# include <stdio.h>
# define STOP      "\033[0m"
# define BOLD       "\033[1m"
# define ITALIC     "\033[3m"
# define UNDERLINE  "\033[4m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_obj
{
	char		player;
	char		advers;
	t_pos		m;
	t_pos		p;
	t_pos		best;
	int			np;
	char		**pform;
	char		**mform;
	t_pos		pos;
	int			len_form_x;
	int			len_form_y;
}				t_obj;

int				line_isdigit(char *line);
void			color_map(char *map);
int				abs(int num);
int				iswall(t_obj *e, t_pos p, t_pos c);
int				is_inmap(t_pos m, t_pos pp, t_pos c);
int				can_place(t_obj *e, t_pos c);
void			len_tetri_x(char **tetri, t_obj *e);
int				len_tetri_y(char **tetri, t_obj *e);
void			recup_arena(char *line, t_obj *e);
void			recup_piece(char *line, t_obj *e);
char			init_player(char *line, t_obj *e);
int				get_data(char *player, t_obj *e);
void			print_best(t_pos best, t_obj *e);
void			set_point(t_pos *o, int y, int x);
void			algo(t_obj *e);
int				check_distance(t_obj *e, t_pos j, t_pos c);
int				near_ennemy(t_obj *e, t_pos c);

#endif
