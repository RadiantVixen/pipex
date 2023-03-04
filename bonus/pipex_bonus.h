/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:19:23 by aatki             #+#    #+#             */
/*   Updated: 2023/03/04 15:32:27 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <time.h>
#include"get_next_line.h"
# include <unistd.h>

char	*check_env(char **env, char **cmd);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_free(char **p);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strlen(char *s);
int     here_doc(char **av,int *infile);
void    ft_error(char *s);
#endif