/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:51:30 by acabarba          #+#    #+#             */
/*   Updated: 2024/10/15 18:57:20 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dup(int fildes)
{
	int	ret;

	ret = dup(fildes);
	if (ret == -1)
	{
		perror("dup error occurred");
		exit(EXIT_FAILURE);
	}
	return (ret);
}
