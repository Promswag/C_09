/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 09:26:08 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/01/30 09:26:08 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_a_sep(char c, char *sep)
{
	int	i;

	i = -1;
	while (sep[++i])
	{
		if (c == sep[i] || c == '\0')
			return (1);
	}
	return (0);
}

int	ft_word_length(char *str, char *sep)
{
	int	i;

	i = 0;
	while (!ft_is_a_sep(str[i], sep))
		i++;
	return (i);
}

void	ft_strncpy(char *dest, char *src, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		dest[i] = src[i];
	dest[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		word_count;

	i = -1;
	word_count = 0;
	while (str[++i])
		if (!ft_is_a_sep(str[i], charset) && ft_is_a_sep(str[i + 1], charset))
			word_count++;
	tab = malloc(sizeof(char *) * (word_count + 1));
	tab[word_count] = NULL;
	i = 0;
	while (i < word_count && str)
	{
		if (!ft_is_a_sep(*(str), charset))
		{
			tab[i] = malloc(sizeof(char) * (ft_word_length(str, charset) + 1));
			ft_strncpy(tab[i++], str, ft_word_length(str, charset));
			str += ft_word_length(str, charset);
		}
		str++;
	}
	return (tab);
}
