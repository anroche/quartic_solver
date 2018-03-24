/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anroche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 19:56:25 by anroche           #+#    #+#             */
/*   Updated: 2017/08/09 17:36:40 by anroche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_benumber(char *s)
{
	int i;

	i = 0;
	if (s[0] == '-')
	{
		while (s[++i] != '\0')
			if (ft_isdigit(s[i++]) == 0)
				return (0);
		return (1);
	}
	while (s[i] != '\0')
		if (ft_isdigit(s[i++]) == 0)
			return (0);
	return (1);
}