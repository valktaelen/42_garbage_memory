/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:46:03 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/16 03:46:05 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tracker_private.h"

t_track	*ft_new_tracker(void)
{
	t_track	*track;

	track = ft_util_track_memalloc(sizeof(t_track));
	if (!track)
		return (NULL);
	track->ptr = NULL;
	return (track);
}

static void	*ft_track_add_ptr(t_track **track, void *ptr)
{
	t_track	*tmp;

	tmp = ft_lst_track_new(ptr);
	if (!tmp)
	{
		free(ptr);
		return (NULL);
	}
	ft_lst_track_add(track, tmp);
	return (ptr);
}

void	*ft_track_dim(t_track **track, void **ptr, size_t level)
{
	if (!ptr)
		return (NULL);
	if (level < 1)
	{
		if (DEBUG_TRACK)
			write(2, "Error: bad level\n", 18);
		return (NULL);
	}
	else if (level == 1)
		return (ft_track_add_ptr(track, (void *)ptr));
	else
	{
		if (!ft_track_add_ptr(track, ptr))
			return (NULL);
		while (*ptr)
		{
			if (!ft_track_dim(track, (void **)*ptr, level - 1))
				return (NULL);
			++ptr;
		}
	}
	return (*ptr);
}

void	*ft_track(t_track **track, void *ptr)
{
	return (ft_track_dim(track, (void **)ptr, 1));
}
