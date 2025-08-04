/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:27:56 by pdangwal          #+#    #+#             */
/*   Updated: 2025/05/09 15:58:23 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	
	str = NULL;
	while(*s)
	{
		if (*s == c)
			str = (char *)s;
		s++;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%s",ft_strrchr("hello world", 'a'));
	printf("%s",strrchr("hello world", 'a'));
	return 0;
}//*/
