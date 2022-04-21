/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:46:26 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/21 14:29:16 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACKER_PRIVATE_H

# define TRACKER_PRIVATE_H

# include <unistd.h>
# include <stdlib.h>
# include "tracker.h"

# define ERR_ALLOC "Warning: tracker can't allocate, the pointer pass is free\n"

// Utils

void	ft_util_track_bzero(void *s, size_t n);
void	*ft_util_track_memalloc(size_t size);

// List management

void	ft_lst_track_add(t_track **track, t_track *new_track);
t_track	*ft_lst_track_new(void *ptr);
void	ft_lst_track_del(t_track *track);
void	ft_lst_track_del_ptr(t_track **track, void *ptr);
void	ft_lst_track_del_ptr_dim(t_track **track, void **ptr, size_t level);
void	ft_lst_track_del_all(t_track **track);

// unused
void	ft_lst_track_del_ptr_dim_node(t_track **track, void **ptr,
			size_t level);
void	ft_lst_track_del_ptr_node(t_track **track, void *ptr);

#endif