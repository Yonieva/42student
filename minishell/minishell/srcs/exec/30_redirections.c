/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   30_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:59:59 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Handles input redirection by opening the specified file and redirecting it
// to stdin.
int	handle_input_redirection(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur d'ouverture du fichier d'entrée");
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

// Handles output redirection based on the type (OVERWRITE or APPEND).
// If it's DOUBLE_OUT, it appends to the file, otherwise it overwrites it.
int	handle_output_redirection(const char *file, int type)
{
	int	fd;
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (type == DOUBLE_OUT)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(file, flags, 0644);
	if (fd == -1)
	{
		perror("Erreur d'ouverture du fichier de sortie");
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

// Handles redirection for heredoc, which is a way to provide multi-line input
// until a specified delimiter is encountered.
int	handle_heredoc_redirection(const char *delimiter)
{
	int		fd;
	char	*mutable_delimiter;

	mutable_delimiter = (char *)delimiter;
	fd = handle_heredoc(mutable_delimiter);
	if (fd == -1)
	{
		perror("Erreur avec le heredoc");
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

// It calls the appropriate handler based on the type of redirection.
int	manage_single_redirection(t_chevron *chevron)
{
	if (chevron->type == IN)
		return (handle_input_redirection(chevron->value));
	else if (chevron->type == OUT || chevron->type == DOUBLE_OUT)
		return (handle_output_redirection(chevron->value, chevron->type));
	else if (chevron->type == DOUBLE_IN)
		return (handle_heredoc_redirection(chevron->value));
	return (0);
}

// Handles all redirections in a list. It loops through the list of redirections
// and processes each one using manage_single_redirection.
void	handle_redirections(t_chevron *chevron_list)
{
	t_chevron	*current;

	current = chevron_list;
	while (current)
	{
		if (manage_single_redirection(current) == -1)
			return ;
		current = current->next;
	}
}
