/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:46:03 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/21 14:19:23 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tracker_private.h"

/**
 * @brief Initialise a new tracker
 * 
 * @return t_track* a new tracker
 */
t_track	*ft_new_tracker(void)
{
	t_track	*track;

	track = ft_util_track_memalloc(sizeof(t_track));
	if (!track)
		return (NULL);
	track->ptr = NULL;
	return (track);
}

/**
 * @brief Add a pointer in the tracker
 * 
 * @param track the tracker
 * @param ptr the pointer to add
 * @return void* the pointer if all is good, if the tracker can't allocate
 * a new node the pointer is free and return NULL
 */
static void	*ft_track_add_ptr(t_track **track, void *ptr)
{
	t_track	*tmp;

	tmp = ft_lst_track_new(ptr);
	if (!tmp)
	{
		if (DEBUG_TRACK)
			write(2, ERR_ALLOC, 59);
		if (FREE_IF_ERROR)
			free(ptr);
		return (NULL);
	}
	ft_lst_track_add(track, tmp);
	return (ptr);
}

static void	ft_crash(t_track **track, void **ptr, size_t i, size_t level)
{
	if (FREE_IF_ERROR)
	{
		while (i != 0)
			ft_lst_track_del_ptr_dim(track, ptr[--i], level - 1);
		ft_lst_track_del_ptr(track, ptr);
	}
	else
	{
		while (i != 0)
			ft_lst_track_del_ptr_dim_node(track, ptr[--i], level - 1);
		ft_lst_track_del_ptr_node(track, ptr);
	}
}

/**
 * @brief Add ptr to the tracker
 * 
 * @param track the tracker
 * @param ptr the pointer on the first element
 * Must be cast in void ** but can be any pointer of any type
 * @param level The level is the number of dimension of ptr
 * It's the number of Asterisk of your pointer after cast
 * It can be 1 for char * or void * [type *]
 * and can be 2 for char ** or void ** [type **] ...
 * @return void* if an error occurs NULL, else the value of ptr
 */
void	*ft_track_dim(t_track **track, void **ptr, size_t level)
{
	size_t	i;

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
	if (!ft_track_add_ptr(track, ptr))
		return (NULL);
	i = 0;
	while (ptr[i])
	{
		if (!ft_track_dim(track, (void **)ptr[i++], level - 1))
		{
			ft_crash(track, ptr, i, level);
			return (NULL);
		}
	}
	return (*ptr);
}

/**
 * @brief ADD the ptr to the tracker
 * It's an alias of ft_track_dim
 * [ft_track_dim(track, (void **)ptr, 1)]
 * 
 * @param track the tracker
 * @param ptr the pointer to track
 * @return void* if an error occurs NULL, else the value of ptr
 */
void	*ft_track(t_track **track, void *ptr)
{
	return (ft_track_dim(track, (void **)ptr, 1));
}
