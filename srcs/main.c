/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:42:55 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/22 17:06:19 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"
#include <limits.h>////

void	arghandeler(t_struct *val, va_list *lp)
{
	val->i++;
	ft_checkflags(val);
	ft_checkwidth(val, lp);
	ft_checkprecision(val, lp);
	ft_checklenmod(val);
	ft_checkspecifier(val, lp);
}

void	ft_strloop(t_struct *val, va_list *lp)
{
	while (val->fmt && val->fmt[val->i])
	{
		if (val->bi == BUFF_FULL)
			ft_clearbuf(val);
		if (val->fmt[val->i] == '%')
		{
			arghandeler(val, lp);
			reset_flags(val);
			val->bi = (int)ft_strlen(val->buf);
		}
		else
		{
			val->buf[val->bi] = val->fmt[val->i];
			val->i++;
			val->bi++;
		}
	}
	ft_clearbuf(val);
}

int		ft_initializer(const char *format, va_list *lp)
{
	t_struct val;

	ft_bzero(&val, sizeof(t_struct));
	ft_bzero(val.buf, BUFF_FULL);
	val.fmt = format;
	val.precis = -1;
	ft_strloop(&val, lp);
	return (val.ret);
}

int		ft_printf(const char *format, ...)
{
	va_list lp;
	int		ret;

	va_start(lp, format);
	ret = ft_initializer(format, &lp);
	va_end(lp);
	return (ret);
}
/*
int		main(void)
{
	long long i;

	i = -9223372036854775;
	//i = 340;
	//(void)i;
	//b = -100;

	printf("\n");
	printf("\n");
	ft_printf("%p \n", &i);
	printf("%p \n", &i);
	ft_printf("{%f}", 1444565444646.6465424242242454654);
	printf("\n");
	printf("{%f}", 1444565444646.6465424242242454654);
	printf("\n");
	printf("%+12.10d %0.1d, %10d, % d, %+d, ", 42, 42, 42, 42, 42);
	printf("\n");
	ft_printf("%+12.10d %0.1d, %10d, % d, %+d, ",42, 42, 42, 42, 42);
	 printf("\n");
	 printf("\n");
	ft_printf("%03.2d, %12.10d %0.1d, %10d, % d, %+d, ", -10, -42, -42, -42, -42, -42);
	printf("\n");
	printf("%03.2d, %12.10d %0.1d, %10d, % d, %+d, ", -10, -42, -42, -42, -42, -42);
	printf("\n");
	printf("\n");
	ft_printf("%0d", -42);
	printf("\n");
	printf("%0d", -42);
	printf("\n");
	printf("\n");
	ft_printf("%00d", -42);
	printf("\n");
	printf("%00d", -42);
	printf("\n");
	ft_printf("%c %s %p %i %o %lld %x %X %%%%hallooo", 'c', "hi", &i, 5000, 5000, -92233720368547758, 502300, 502300);
	printf("\n");
	printf("%c %s %p %i %o %ld %x %X %%%%hallooo", 'c', "hi", &i, 5000, 5000, -92233720368547758, 502300, 502300);
	return 0;
}
*/