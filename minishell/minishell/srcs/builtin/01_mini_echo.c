/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_mini_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:36:44 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 18:36:44 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/**
 * check_option : Vérifie si un argument est une option '-n' valide.
 * exe_echo : gère l'option -n pour ne pas ajouter de nouvelle ligne et affiche
 * les arguments avec des espaces entre eux. return 0 si ok.
 */
static int	check_option_echo(char *str, int *start_index)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (0);
	i++;
	if (str[i] != 'n')
		return (0);
	while (str[i] == 'n')
		i++;
	if (str[i] == '\0' || str[i] == ' ')
	{
		*start_index = i;
		return (1);
	}
	return (0);
}

void	ft_fflush_stdout(void)
{
	if (stdout->_IO_write_ptr > stdout->_IO_write_base)
	{
		write(STDOUT_FILENO, stdout->_IO_write_base,
			stdout->_IO_write_ptr - stdout->_IO_write_base);
		stdout->_IO_write_ptr = stdout->_IO_write_base;
	}
}

int	parse_echo_options(char *str, int *option)
{
	int	i;
	int	start_index;

	i = 0;
	start_index = 0;
	i = skip_spaces(str, i);
	i += 4;
	i = skip_spaces(str, i);
	while (check_option_echo(&str[i], &start_index))
	{
		*option = 1;
		i += start_index;
		i = skip_spaces(str, i);
	}
	return (i);
}

int	exe_echo(char *str, t_envp *envp)
{
	int	option;
	int	i;

	option = 0;
	str = clean_string(str);
	i = parse_echo_options(str, &option);
	if (str[i] != '\0')
		printf("%s", &str[i]);
	if (!option)
		printf("\n");
	ft_fflush_stdout();
	free(str);
	return ((envp->status_cmd = 0), 0);
}
