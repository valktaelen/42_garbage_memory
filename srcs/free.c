/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:46:20 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/16 03:46:22 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tracker_private.h"

void	ft_track_dim_free(t_track **track, void **ptr, size_t level)
{
	void	*dim;

	if (!ptr)
		return ;
	if (level < 1)
	{
		if (DEBUG_TRACK)
			write(2, "Error: bad level\n", 18);
		return ;
	}
	else if (level == 1)
		ft_lst_track_del_ptr(track, (void *)ptr);
	else
	{
		dim = (void *)ptr;
		while (*ptr)
		{
			ft_track_dim_free(track, (void **)*ptr, level - 1);
			++ptr;
		}
		ft_lst_track_del_ptr(track, dim);
	}
}

void	ft_track_free(t_track **track, void *ptr)
{
	ft_track_dim_free(track, (void **)ptr, 1);
}

void	ft_track_free_all(t_track **track)
{
	ft_lst_track_del_all(track);
}
