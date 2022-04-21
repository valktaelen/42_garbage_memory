/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:46:15 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/21 13:49:43 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tracker_private.h"

/**
 * @brief Add the new node to the list of pointer track
 * 
 * @param track the tracker
 * @param new_track the node of the new pointer
 */
void	ft_lst_track_add(t_track **track, t_track *new_track)
{
	t_track	*tmp;

	if (!new_track)
		return ;
	new_track->next = NULL;
	if (!(*track))
	{
		new_track->prev = NULL;
		*track = new_track;
	}
	else
	{
		tmp = *track;
		while (tmp->next)
		{
			if (tmp == new_track)
				return ;
			tmp = tmp->next;
		}
		if (tmp == new_track)
			return ;
		new_track->prev = tmp;
		tmp->next = new_track;
	}
}

/**
 * @brief Allocate a new node with the pointer pass in param
 * 
 * @param ptr the pointer
 * @return t_track* the node that contain the new pointer
 */
t_track	*ft_lst_track_new(void *ptr)
{
	t_track	*new_track;

	if (!ptr)
		return (NULL);
	new_track = ft_util_track_memalloc(sizeof(t_track));
	if (!new_track)
		return (NULL);
	new_track->ptr = ptr;
	return (new_track);
}

/**
 * @brief delete a node of the tracker list
 * 
 * @param track the node to delete and free
 */
void	ft_lst_track_del(t_track *track)
{
	if (!track)
		return ;
	if (track->prev)
		track->prev->next = track->next;
	if (track->next)
		track->next->prev = track->prev;
	free(track->ptr);
	free(track);
}

/**
 * @brief delete the node in the tracker list that mach with the pointer pass
 * 
 * @param track the tracker
 * @param ptr the pointer to delete and free
 */
void	ft_lst_track_del_ptr(t_track **track, void *ptr)
{
	t_track	*tmp;

	if (!ptr)
		return ;
	tmp = *track;
	while (tmp && tmp->ptr != ptr)
		tmp = tmp->next;
	if (tmp->ptr == ptr)
		ft_lst_track_del(tmp);
}

/**
 * @brief Free all the pointer track and delete the track list
 * 
 * @param track the tracker
 */
void	ft_lst_track_del_all(t_track **track)
{
	t_track	*tmp;

	while ((*track))
	{
		tmp = (*track)->next;
		ft_lst_track_del(*track);
		*track = tmp;
	}
}
