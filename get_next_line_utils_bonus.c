/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:06:30 by nsouchal          #+#    #+#             */
/*   Updated: 2023/12/13 12:54:31 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	size_t		len_s;
	char		*dup_s;
	size_t		i;

	i = 0;
	len_s = ft_strlen(s) + 1;
	dup_s = malloc(len_s * sizeof(char));
	if (!dup_s)
		return (0);
	while (s[i])
	{
		dup_s[i] = s[i];
		i++;
	}
	dup_s[i] = '\0';
	return (dup_s);
}

char	*concat_str(char *s1, char *s2, char *new_s)
{
	size_t	index;
	size_t	index_s2;

	index = 0;
	index_s2 = 0;
	while (s1[index])
	{
		new_s[index] = s1[index];
		index++;
	}
	while (s2[index_s2])
	{
		new_s[index] = s2[index_s2];
		index++;
		index_s2++;
	}
	new_s[index] = '\0';
	free(s1);
	return (new_s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;

	if (s1 == NULL && s2 == NULL)
		return (malloc(0));
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	new_s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new_s)
	{
		free(s1);
		return (0);
	}
	return (concat_str(s1, s2, new_s));
}

void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = n - 1;
	if (dest > src)
	{
		while (n--)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i--;
		}
		return (dest);
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
		return (dest);
	}
}
