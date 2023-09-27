/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:40:37 by mkizilde          #+#    #+#             */
/*   Updated: 2023/09/28 00:40:37 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = -1;
	j = 0;
	if (!s1)
	{
		new = (char *)malloc(sizeof(char));
		new[0] = '\0';
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1[++i] != '\0')
		new[i] = s1[i];
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	free (s1);
	return (new);
}
