/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:37:11 by pdangwal          #+#    #+#             */
/*   Updated: 2025/05/09 19:01:57 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void ft_bzero(void *s, size_t n)
{
	unsigned char*	ptr;
	ptr = (unsigned char*)s;

	while(n--)
	{
		ptr[n] = '\0';
	}
}
int main(void)
{
    char str[] = "helloworld";     // Original string for ft_bzero
    char str1[] = "helloworldeeee"; // Original string for bzero

    // Printing original strings
    printf("Before ft_bzero: %s\n", str);
    printf("Before bzero: %s\n", str1);

    // Zero out the first 4 bytes of each string
    ft_bzero(str, 4);   // Set the first 4 characters of str to '\0'
    bzero(str1, 4);      // Set the first 4 characters of str1 to '\0'

    // Printing strings after applying ft_bzero and bzero
    printf("After ft_bzero: %s\n", str + 5);
    printf("After bzero: %s\n", str1 + 5);

    return 0;
}
