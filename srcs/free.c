/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:46:20 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/16 04:40:58 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tracker_private.h"

/**
 * @brief Free the ptr pass and remove from the tracker
 * 
 * @param track the tracker
 * @param ptr the pointer on the first element to free
 * Must be cast in void ** but can be any pointer of any type
 * @param level The level is the number of dimension of ptr
 * It's the number of Asterisk of your pointer after cast
 * It can be 1 for char * or void * [type *]
 * and can be 2 for char ** or void ** [type **] ...
 */
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

/**
 * @brief Free the ptr pass and remove from the tracker
 * It's an alias of ft_track_dim_free
 * [ft_track_dim_free(track, (void **)ptr, 1)]
 * 
 * @param track the tracker
 * @param ptr the pointer to free
 */
void	ft_track_free(t_track **track, void *ptr)
{
	ft_track_dim_free(track, (void **)ptr, 1);
}

/**
 * @brief Free the tracker and all the pointer pass to the tracker
 * 
 * @param track the tracker
 */
void	ft_track_free_all(t_track **track)
{
	ft_lst_track_del_all(track);
	*track = NULL;
}
