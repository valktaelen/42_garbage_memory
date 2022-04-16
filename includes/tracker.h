/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:46:23 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/16 03:47:40 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACKER_H

# define TRACKER_H

# define DEBUG_TRACK 1

# include <stdio.h>

typedef struct s_track	t_track;

struct s_track
{
	void	*ptr;
	t_track	*prev;
	t_track	*next;
};

// Track

t_track	*ft_new_tracker(void);
void	*ft_track_dim(t_track **track, void **ptr, size_t level);
void	*ft_track(t_track **track, void *ptr);

// Free

void	ft_track_dim_free(t_track **track, void **ptr, size_t level);
void	ft_track_free(t_track **track, void *ptr);
void	ft_track_free_all(t_track **track);

#endif