/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:39:59 by yonieva           #+#    #+#             */
/*   Updated: 2024/04/01 23:22:29 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALH_H
# define MINITALK_H
# include "libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>


void	title_client(void);
void	title_server(void);
void	ft_btoa(int sig);
void	ft_atob(int pid, char c);

#endif
/**************************************************************************/