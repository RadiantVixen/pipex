/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:14:33 by aatki             #+#    #+#             */
/*   Updated: 2023/02/21 14:31:33 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

	// int id = fork();
	// int i;

	// //int o=9;
   
	// if (id == 0)
	// {
	// 	i = 0;
	// 	while (i < 5)
	// 	{
	// 		printf("child %d\n", i);
	// 		i++;
    //         //fflush(stdout);
	// 	}
	// }
    //  if(id!=0)
    // wait(NULL);
	// if (id != 0)
	// {
	// 	i = 5;
	// 	while (i < 10)
	// 	{
	// 		printf("fother %d\n", i);
    //        // fflush(stdout);
	// 		i++;
	// 	}
	// }

int	main(void)
{
	int id1;
	id1=fork();
	int i=5;
	// int id2=fork();
	// int fd;
	// if(id1!=0)
	// {
	// 	printf("%d\n",i);
	// }
	// else
	// {
	// 	
	// 	scanf("%d",&i);
	// }
	write(1,&i,sizeof(int));//printf("give a number\n");
	//wait(NULL);
}
