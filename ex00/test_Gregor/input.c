/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruta <gruta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:41:25 by ksuebtha          #+#    #+#             */
/*   Updated: 2024/08/31 17:56:33 by gruta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define SIZE 4

int g_topclues[SIZE];
int	g_bottomclues[SIZE];
int	g_leftclues[SIZE];
int	g_rightclues[SIZE];

int	extract_values(char *input, int *value, int max_values)
{
	int	totalnum;

	totalnum = 0;
	while (*input != 0 && totalnum < max_values
		&& (*input == ' ' || (*input >= '1' && *input <= SIZE + 48)))
	{
		if (*input >= '1' && *input <= SIZE + 48)
		{
			value[totalnum] = *input - 48;
			totalnum++;
		}
		input++;
	}
	return (totalnum);
}

int	parse_input(char *input)
{
	int	values[SIZE * 4];
	int	totalnum;
	int	i;

	totalnum = extract_values(input, values, SIZE * 4);
	i = 0;
	if (totalnum != SIZE * 4)
		return (0);
	while (i < SIZE)
	{
		g_topclues[i] = values[i];
		g_bottomclues[i] = values[i + SIZE];
		g_leftclues[i] = values[i + 2 * SIZE];
		g_rightclues[i] = values[i + 3 * SIZE];
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (parse_input(argv[1]))
		{
			for(int i = 0; i<SIZE; i++){
				printf("%d ", g_topclues[i]);
			}
			printf("\n");
			for(int i = 0; i<SIZE; i++){
				printf("%d ", g_bottomclues[i]);
			}
			printf("\n");
			for(int i = 0; i<SIZE; i++){
				printf("%d ", g_leftclues[i]);
			}
			printf("\n");
			for(int i = 0; i<SIZE; i++){
				printf("%d ", g_rightclues[i]);
			}

		}
		else
		{
			write (1, "Invalid Input.", 15);
		}

	}
	else
	{
		write (1, "Input need to be in only 1 parameter.", 38);
	}

	return (0);
}