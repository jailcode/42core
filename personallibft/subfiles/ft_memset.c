/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:23:14 by pdangwal          #+#    #+#             */
/*   Updated: 2025/05/09 17:38:27 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
void	*ft_memset(void *b, int c, size_t l)
{

	unsigned char* ptr;

	ptr = (unsigned char*)b;
	while(l--)
	{
		*ptr = c;
		ptr++;
	}
	return (b);
}
/*
int	main(void)
{
	char str[] = "hello world";
	char str1[] = "hello world";



	printf("%s\n", ft_memset(str, 48, 5));
	printf("%s\n", memset(str1, 48, 5));
	printf("%s\n", ft_memset(str, 304, 5));
	printf("%s\n", memset(str1, 304, 5));

	return 0;
}
*/