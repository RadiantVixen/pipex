/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:14:33 by aatki             #+#    #+#             */
/*   Updated: 2023/02/26 20:47:17 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	execution(char **av, char **env)
// {
// 	char	*path;
// 	char *c[] = {av[2], av[1],NULL};
// 	char	**cmd;
// 	cmd = ft_split(av[2], ' ');
// 	path = check_env(env, cmd);
// 	execve(path, c, env);
// 	ft_free(c);
// 	ft_free(cmd);
// }

void	execution(char *command, char **env)
{
	char	*path;
	char	**cmd;

	path = NULL;
	cmd = ft_split(command, ' ');
	if (access(cmd[0], R_OK) == 0)
	{
		if (execve(cmd[0], cmd, env) < 0)
			perror("command can't executude");
	}
	else
	{
		path = check_env(env, cmd);
		if (execve(path, cmd, env) < 0)
			perror("command can't executude");
	}
	free(path);
	ft_free(cmd);
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	id;
	int	infile;
	int	outfile;
	int	id2;

	if (ac == 5)
	{
		if (pipe(fd) < 0)
			perror("can't pipe");
		id = fork();
		if (id < 0)
			perror("can't fork");
		// fd[1] write
		// fd[0] read
		if (id == 0)
		{
			infile = open(av[1], O_RDONLY);
			if (infile < 0)
				perror("file can't open");
			if (close(fd[0]) < 0)
				perror("file can't close");
			if (dup2(fd[1], 1) < 0||dup2(infile, 0) < 0)
				perror("can't dup");
			execution(av[2], env);
			if (close(infile) < 0)
				perror("file can't close");
		}
		id2 = fork();
		if (id2 < 0)
			perror("can't fork");
		if (id2 == 0)
		{
			outfile = open(av[4], O_TRUNC | O_RDWR | O_CREAT, 0644);
			if (outfile < 0)
				perror("file can't open");
			if (close(fd[1]) < 0)
				perror("file can't close");
			if (dup2(outfile, 1) < 0)
				perror("can't dup");
			if (dup2(fd[0], 0) < 0)
				perror("can't dup");
			execution(av[3], env);
			// close(fd[0]);
			close(outfile);
		}
		if (close(fd[0]) < 0)
			perror("file can't close");
		if (close(fd[1]) < 0)
			perror("file can't close");
		waitpid(id, NULL, 0);
		waitpid(id2, NULL, 0);
	}
	//system("leaks pipex");
}
