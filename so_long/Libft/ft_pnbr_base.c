/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnbr_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:26:05 by vacuccu           #+#    #+#             */
/*   Updated: 2025/07/15 17:32:50 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pnbr_base(unsigned long n, char *base)
{
	unsigned long	base_len;
	int				printed_chars;
	int				result;

	result = 0;
	base_len = ft_strlen(base);
	printed_chars = 0;
	if (n >= base_len)
		printed_chars += ft_pnbr_base((n / base_len), base);
	result = (n % base_len);
	printed_chars += ft_pchar(base[result]);
	return (printed_chars);
}
