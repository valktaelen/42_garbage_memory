/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:26:53 by aartiges          #+#    #+#             */
/*   Updated: 2022/04/21 14:29:25 by aartiges         ###   ########lyon.fr   */
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
 * @brief Free all the node of the tracker which are in the pointer
 * with the pointer
 * 
 * @param track the tracker
 * @param ptr the pointer
 * @param level the level (dimension [number of asterisk])
 */
void	ft_lst_track_del_ptr_dim(t_track **track, void **ptr, size_t level)
{
	size_t	i;

	if (level < 1)
		return ;
	if (level == 1)
		ft_lst_track_del_ptr(track, ptr);
	else
	{
		i = 0;
		while (ptr[i])
		{
			ft_lst_track_del_ptr_dim(track, ptr[i], level - 1);
			i++;
		}
		ft_lst_track_del_ptr(track, ptr);
	}
}

/**
 * @brief Free all the node of the tracker which are in the pointer
 * but not the pointer
 * 
 * @param track the tracker
 * @param ptr the pointer
 * @param level the level (dimension [number of asterisk])
 */
void	ft_lst_track_del_ptr_dim_node(t_track **track, void **ptr, size_t level)
{
	size_t	i;

	if (level < 1)
		return ;
	if (level == 1)
		ft_lst_track_del_ptr_node(track, ptr);
	else
	{
		i = 0;
		while (ptr[i])
		{
			ft_lst_track_del_ptr_dim_node(track, ptr[i], level - 1);
			i++;
		}
		ft_lst_track_del_ptr_node(track, ptr);
	}
}
