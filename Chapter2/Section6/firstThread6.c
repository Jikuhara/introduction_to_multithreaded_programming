/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstThread6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:16:32 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/15 17:09:41 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 10000000

void *threadFunc(void *arg)
{
	double table[SIZE];
	int i;

	for (i = 0; i < SIZE; i++)
	{
		table[i] = i * 3.14;
	}
	return (NULL);
}

int main(int argc, const char *argv[])
{
	pthread_attr_t	attr;
	pthread_t		thread;
	int				n;
	int				i;

	pthread_attr_init(&attr);
	if (pthread_attr_setstacksize(&attr, SIZE*sizeof(double)+100000) != 0)
	{
		printf("Failed to set stack size.\n");
		exit(1);
	}
	if (pthread_create(&thread, &attr, threadFunc, NULL) != 0)
		{
			perror("ERROR: Failed to create thread.\n");
			exit(1);
		}
	if (pthread_join(thread, NULL) != 0)
	{
		printf("Error: Failed to wait for the thread termination.\n");
		exit(1);
	}
	return (0);
}
