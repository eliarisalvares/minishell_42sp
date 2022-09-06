/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:40:44 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 17:12:14 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		s1_size;
	int		s2_size;

	if (!s1 && !s2)
		return (NULL);
	s1_size = (ft_strlen((char *)s1));
	s2_size = (ft_strlen((char *)s2));
	join = (char *)malloc((s1_size + s2_size + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	ft_strlcpy(&join[0], s1, s1_size + 1);
	ft_strlcpy(&join[s1_size], s2, s2_size + 1);
	return (join);
}
