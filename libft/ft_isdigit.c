/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isdigit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 07:17:32 by vmulder       #+#    #+#                 */
/*   Updated: 2019/01/15 08:41:51 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}