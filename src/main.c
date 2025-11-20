/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:13:33 by mdiederi          #+#    #+#             */
/*   Updated: 2025/10/20 10:14:15 by mdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	(void)argv;
	t_cub *cub = ft_calloc(1, sizeof(*cub));   // zero-initialized struct
    if (!cub) 
		error_exit(cub, "Error\nMalloc failure\n", NULL);
	if (argc != 2)   // to do:  ./cub3D 'map.cub" 
	{ // || !check_file_ext(argc, argv)
		error_exit(cub,
			"Please provide exactly one valid .cub file as an argument\n", NULL);
	}	
	parse_file(argv[1], cub);
	clean_up(cub);

	return (0);
}
