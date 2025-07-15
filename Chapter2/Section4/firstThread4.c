/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstThread4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:16:32 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/15 15:14:21 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *threadFunc(void *arg)
{
	int n = (int)arg;
	int i;

	for (i = 0; i < n; i++)
	{
		printf("I'm threadFunc %d\n", i);
		sleep(1);
	}
	return ((void *)n);
}

int main(int argc, const char *argv[])
{
	pthread_t	thread;
	int 		n, i, ret;

	if (argc > 1)
		n = atoi(argv[1]);
	else
		n = 1;
	if (pthread_create(&thread, NULL, threadFunc, (void *)n) != 0)
		{
			perror("ERROR: Failed to create thread.\n");
			exit(1);
		}

	for (int i = 0; i < 5; i++)
	{
		printf("I'm main: %d\n", i);
		sleep(1);
	}
	if (pthread_join(thread, (void **)&ret) != 0)
	{
		printf("Error: Failed to wait for the thread termination.\n");
		exit(1);
	}
	printf("threadFunc has been treminated with number %d\n", ret);
	printf("Bye.\n");
	return (0);
}
