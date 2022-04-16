/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges & jmilhas <@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:46:08 by aartiges &        #+#    #+#             */
/*   Updated: 2022/04/16 03:46:11 by aartiges &       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tracker_private.h"

void	ft_util_track_bzero(void *s, size_t n)
{
	unsigned char	*ps;

	ps = (unsigned char *)s;
	while (n > 0)
	{
		*ps++ = 0;
		n--;
	}
}

void	*ft_util_track_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (mem)
	{
		ft_util_track_bzero(mem, size);
		return (mem);
	}
	else
		return (NULL);
}
