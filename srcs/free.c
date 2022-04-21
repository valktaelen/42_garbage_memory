/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:46:20 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/21 14:27:18 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tracker_private.h"

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

/**
 * @brief delete the node in the tracker list that mach with the pointer pass
 * 
 * unused
 * 
 * @param track the tracker
 * @param ptr the pointer of node to delete
 */
void	ft_lst_track_del_ptr_node(t_track **track, void *ptr)
{
	t_track	*tmp;

	if (!ptr)
		return ;
	tmp = *track;
	while (tmp && tmp->ptr != ptr)
		tmp = tmp->next;
	if (tmp->ptr == ptr)
		free(tmp);
}
