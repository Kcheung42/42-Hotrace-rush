/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_strcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 12:48:16 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 23:22:36 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#ifdef TEST
# include <stdio.h>
#endif

int		sse_strcmp(const char *s1, const char *s2)
{
	int	result;
	size_t idx;

	__asm__("mov $-16, %1\n"
			"cmploop: add $16, %1\n"
			"movdqu (%1,%2), %%xmm1\n"
			"movdqu (%1,%3), %%xmm0\n"
			"pcmpistri $24, %%xmm0, %%xmm1\n"
			"jnbe cmploop\n"
			"jnc equal\n"
			"add %%rcx, %1\n"
			"mov $1, %0\n"
			"jmp done\n"
			"equal: xor %0, %0\n"
			"done:nop"
			: "=r"(result), "+r"(idx)
			: "r"(s1), "r"(s2)
			: "rcx", "cc", "xmm0", "xmm1");
	if (result)
		return (s2[idx] - s1[idx]);
	return (0);
}	
