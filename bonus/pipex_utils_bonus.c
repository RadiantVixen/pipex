/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:36:28 by aatki             #+#    #+#             */
/*   Updated: 2023/03/06 16:24:33 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	if ((unsigned char)s1[i] < (unsigned char)s2[i])
		return (-1);
	else if ((unsigned char)s1[i] > (unsigned char)s2[i])
		return (1);
	else
		return (0);
}

void	ft_error(char *s)
{
	perror("Error\n");
	perror(s);
	exit(1);
}

char	*check_env(char **env, char **cmd)
{
	int		i;
	char	**ret;
	char	*path;
	char	*temp;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			ret = ft_split(env[i] + 5, ':');
	}
	i = -1;
	while (ret[++i])
	{
		temp = ft_strjoin(ret[i], "/");
		path = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (access(path, R_OK) == 0)
			break ;
		else
			free(path);
	}
	if (access(path, R_OK) == -1)
		ft_error("no access to the command\n");
	ft_free(ret);
	return (path);
}
