/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:16:30 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/22 19:23:58 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	color_map(char *map)
{
	int		i;
	char	*amine;
	char	*amine2;

	i = 0;
	amine = ft_strdup("\e[38;5;174;01m");
	amine2 = ft_strdup("\e[38;5;163;01m");
	while (map[i])
	{
		if (map[i] == 'O')
			dprintf(2, "%s%c%s", amine2, 'O', STOP);
		else if (map[i] == 'X')
			dprintf(2, "%s%c%s", amine, 'X', STOP);
		else
			dprintf(2, "%s%c%s", BLUE, '.', STOP);
		i++;
	}
	free(amine);
	free(amine2);
	ft_putendl_fd("", 2);
}

int		line_isdigit(char *line)
{
	int i;

	i = 8;
	while (!ft_isdigit(line[i]))
		++i;
	return (i);
}
