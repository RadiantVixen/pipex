/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:14:33 by aatki             #+#    #+#             */
/*   Updated: 2023/03/05 21:52:17 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execution(char *command, char **env)
{
	char	*path;
	char	**cmd;

	path = NULL;
	cmd = ft_split(command, ' ');
	if (access(cmd[0], X_OK) == 0)
	{
		if (execve(cmd[0], cmd, env) < 0)
			ft_error("command can't executude");
	}
	else
	{
		path = check_env(env, cmd);
		// dprintf(1,"%s\n", );
		if (execve(path, cmd, env) < 0)
			ft_error("command can't executude");
	}
	free(path);
	ft_free(cmd);
}

void	child_one(int *fd, char **av, char **env, int ac)
{
	int	infile;
	int	i;
	int	ph[2];
	int	id;

	i = 2;
	infile = open(av[1], O_RDWR, 0644);
	if (infile < 0)
		ft_error("file can't open");
	while (i < ac - 2)
	{
		if (pipe(ph) < 0)
			ft_error("cant pipe in child one");
		id = fork();
		if (id < 0)
			ft_error("cant fork in child one");
		if (id == 0)
		{
			if (i == 2)
				fd[0] = infile;
			if (dup2(fd[0], 0) < 0)
				ft_error("cant dup 1 in child one");
			if (dup2(ph[1], 1) < 0)
				ft_error("cant dup 2 in child one");
			// if (close(fd[1]) < 0)
			// 	ft_error("file 1 can't close in child 1");
			// if (close(fd[0]) < 0)
			// 	ft_error("file 2 can't close in child 1");
			execution(av[i], env);
		}
		fd[0] = dup(ph[0]);
		close(ph[1]);
		i++;
	}
}

void	child_two(int *fd, char **av, char **env, int ac)
{
	int	outfile;

	outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile < 0)
		ft_error("file can't opennn");
	// fd[1] = outfile;
	if (close(fd[1]) < 0)
		ft_error("file can't close in child 2");
	if (dup2(fd[0], 0) < 0)
		ft_error("can't 2 dup in child 2");
	if (dup2(outfile, 1) < 0)
		ft_error("can't 1 dup in child 2");
	execution(av[ac - 2], env);
}

void	here_docc(char **av)
{
	int		infile;
	char	*tmp;

	tmp = NULL;
	infile = open("file", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (infile < 0)
		perror("file can't open");
	write(1,"here_doc> ",10);
	tmp = get_next_line(0);
	while (tmp)
	{
		write(1,"here_doc> ",10);
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
	execution(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	id2;
	int	id;

	id = 0;
	if (ac >= 5)
	{
		if (!strncmp(av[1], "here_doc", 8))
		{
			here_docc(av);
			pipe(fd);
			id = fork();
			if (id == 0)
				here_doc_child(fd, av, env);
			id2 = fork();
			if (id2 == 0)
				child_two(fd, av, env, ac);
			// waitpid(id, NULL, 0);
			// waitpid(id2, NULL, 0);
		}
		else
		{
			child_one(fd, av, env, ac);
			id2 = fork();
			if (id2 == 0)
				child_two(fd, av, env, ac);
			waitpid(id2, NULL, 0);
		}
	}
}
