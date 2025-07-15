/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstThread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:16:32 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/15 14:55:24 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *threadFunc(void *arg)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("I'm threadFunc %d\n", i);
		sleep(1);
	}
	return (NULL);
}

int main(void)
{
	pthread_t	threads;
	int 		i;

	if (pthread_create(&threads, NULL, threadFunc, NULL) != 0)
		{
			perror("ERROR: Failed to create thread.\n");
			exit(1);
		}

	for (int i = 0; i < 3; i++)
	{
		printf("I'm main: %d\n", i);
		sleep(1);
	}
	return (0);
}
