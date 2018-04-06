/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:37:05 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/22 19:18:51 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		main(void)
{
	char		player;
	t_obj		*p;

	if (!(p = (t_obj *)malloc(sizeof(t_obj))))
		return (0);
	player = '\0';
	while (get_data(&player, p) == 1)
		algo(p);
	return (0);
}

int		abs(int num)
{
	return (num < 0 ? -num : num);
}
