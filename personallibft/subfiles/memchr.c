/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:32 by pdangwal          #+#    #+#             */
/*   Updated: 2025/05/09 18:36:24 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *ptr;
	unsigned char	d;

	ptr = (unsigned char*)s;
	d = (unsigned char)c;
	while(n--)
	{
		if (*ptr == d)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
/*
int	main(void)
{
	void *str = "hello world";
	printf("%s\n",ft_memchr(str, 'l', 5));
	printf("%s",memchr(str,'l',5));
	return 0;
}//*/
