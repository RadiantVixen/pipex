/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:47:12 by aatki             #+#    #+#             */
/*   Updated: 2023/02/27 22:47:21 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

void here_doc(char **av,int *infile)
{
    char *tmp=NULL;
    if(!strncmp(av[2],"here_doc",8))
    {
        *infile = open("././infile", O_RDONLY,O_CREAT);
        if (*infile < 0)
			perror("file can't open");
        while(1)
        {
            if(!strncmp(tmp,av[3],ft_strlen(tmp)))
            {
                free(tmp);
                  break;
            }
            tmp=get_next_line(0);
            write(*infile,tmp,ft_strlen(tmp));
            free(tmp);
        }
        
    }
    else
        *infile = open(av[1], O_RDONLY,O_CREAT);
        if (*infile < 0)
			perror("file can't open");
}