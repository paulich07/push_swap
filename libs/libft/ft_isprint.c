/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:07:23 by plichota          #+#    #+#             */
/*   Updated: 2024/11/18 17:07:24 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}
/*
int main(void)
{
	printf("is print %d", ft_isprint(127));
}
*/
