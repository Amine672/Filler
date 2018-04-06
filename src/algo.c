/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:37:10 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/19 18:37:12 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	print_best(t_pos best, t_obj *e)
{
	if (e->best.y + e->len_form_y > e->m.y
			|| e->best.x + e->len_form_x > e->m.x)
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
		free(e->pform);
		free(e->mform);
	}
	else
	{
		ft_putnbr(best.y);
		ft_putchar(' ');
		ft_putnbr(best.x);
		ft_putchar('\n');
		free(e->pform);
		free(e->mform);
	}
}

void	set_point(t_pos *o, int y, int x)
{
	o->y = y;
	o->x = x;
}

int		check_distance(t_obj *e, t_pos j, t_pos c)
{
	t_pos	k;
	t_pos	rel;
	int		dist;

	k.y = -1;
	dist = 0;
	while (++k.y < e->p.y)
	{
		k.x = -1;
		while (++k.x < e->p.x)
		{
			if (e->pform[k.y][k.x] == '*')
			{
				set_point(&rel, k.y + c.y, k.x + c.x);
				dist += abs(j.y - rel.y) + abs(j.x - rel.x);
			}
		}
	}
	return (dist);
}

int		near_ennemy(t_obj *e, t_pos c)
{
	t_pos	j;
	int		this;
	int		nearer;

	nearer = 99999999;
	j.y = -1;
	while (++j.y < e->m.y)
	{
		j.x = -1;
		while (++j.x < e->m.x)
		{
			if (e->mform[j.y][j.x] == e->advers)
			{
				if ((this = check_distance(e, j, c)) < nearer)
					nearer = this;
			}
		}
	}
	return (nearer);
}

void	algo(t_obj *e)
{
	t_pos	c;
	int		best;
	int		this;

	best = 999999999;
	c.y = -e->p.y;
	while (++c.y < e->m.y)
	{
		c.x = -e->p.x;
		while (++c.x < e->m.x)
		{
			if (can_place(e, c))
			{
				if ((this = near_ennemy(e, c)) < best)
				{
					best = this;
					set_point(&e->best, c.y, c.x);
				}
			}
		}
	}
	print_best(e->best, e);
}
