/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:21:34 by pdangwal          #+#    #+#             */
/*   Updated: 2025/05/09 17:21:07 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
char	*ft_strchr(const char *s, int c)
{
	while(*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{

	printf("%s",ft_strchr("hellooooo", 48));
}//*/
