/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:47:12 by aatki             #+#    #+#             */
/*   Updated: 2023/03/04 16:22:55 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

int here_doc(char **av,int *infile)
{
    char *tmp=NULL;
    if(!strncmp(av[1],"here_doc",8))
    {
        *infile = open("../.aatki.tmp", O_RDWR|O_CREAT| O_TRUNC);
        if (*infile < 0)
			ft_error("file can't open");
        while(1)
        { 
            tmp=get_next_line(0);
            if(!strncmp(tmp,av[2],ft_strlen(tmp)-1))
            {
                free(tmp);
                return 3;
            }
            write(*infile,tmp,ft_strlen(tmp));
            free(tmp);
        }
    }
    else
    {
        *infile = open(av[1], O_RDONLY);
        if (*infile < 0)
			ft_error("file can't open");
        return 2;
    }
}