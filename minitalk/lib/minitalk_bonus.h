/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:39:59 by yonieva           #+#    #+#             */
/*   Updated: 2024/04/01 23:36:30 by yonieva          ###   ########.fr       */
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
void	ft_btoa(int signum, siginfo_t *info, void *context);
void	ft_atob(int pid, char c);
void    signal_recu_du_server(int signum);

#endif
/**************************************************************************/