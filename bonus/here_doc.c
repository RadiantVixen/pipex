/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:47:12 by aatki             #+#    #+#             */
/*   Updated: 2023/03/06 16:26:05 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_docc(char **av)
{
	int		infile;
	char	*tmp;

	tmp = NULL;
	infile = open("file", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (infile < 0)
		perror("file can't open");
	write(1, "here_doc> ", 10);
	tmp = get_next_line(0);
	while (tmp)
	{
		write(1, "here_doc> ", 10);
		if ((ft_strncmp(tmp, av[2], ft_strlen(tmp) - 1) == 0) && ft_strlen(tmp)
			- 1 == ft_strlen(av[2]))
		{
			free(tmp);
			break ;
		}
		write(infile, tmp, ft_strlen(tmp));
		free(tmp);
		tmp = get_next_line(0);
	}
	close(infile);
}

void	here_doc_child(int *fd, char **av, char **env)
{
	int	infile;

	infile = open("file", O_RDONLY);
	close(fd[0]);
	if (dup2(infile, 0) < 0)
		ft_error("can't dup");
	if (dup2(fd[1], 1) < 0)
		ft_error("can't dup");
	unlink("file");
	execution(av[3], env);
}
