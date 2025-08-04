/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:59:23 by pdangwal          #+#    #+#             */
/*   Updated: 2025/05/09 17:07:40 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	cmp;

	cmp = 0;
	while (cmp < n && *s1 && *s2)
	{
		if( *s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	if (cmp < n)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}
