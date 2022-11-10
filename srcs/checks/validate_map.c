/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:01:09 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/12 07:10:48 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "info.h"
#include <stdbool.h>
#include <stdio.h>

void	print_map(t_info *info, size_t x, size_t y);

char	map__start_point__check_char(char target)
{
	size_t		i;
	const char	valid_char[]
		= {'\n', ' ', '0', '1', 'D', 'N', 'S', 'W', 'E'};

	i = 0;
	while (i < sizeof(valid_char))
	{
		if (valid_char[i] == target)
		{
			return (valid_char[i]);
		}
		i++;
	}
	return (FAILURE);
}

t_result	map__start_point__init(t_info *info, int x, int y)
{
	char	target;

	target = map__start_point__check_char(info->map.raw[y]->str[x]);
	if (target == FAILURE)
	{
		ft_putstr_fd("Error: Invalid character in map\n", 2);
		return (ERROR);
	}
	else if (target > 'D')
	{
		if (info->core.world.player.cardinal == 0)
		{
			info->core.world.player.cardinal = target;
			info->core.world.player.pos.x = x;
			info->core.world.player.pos.y = y;
			info->map.visited[y][x] = true;
			return (SUCCESS);
		}
		else
		{
			ft_putstr_fd("Error: Multiple start point founded\n", 2);
			return (ERROR);
		}
	}
	return (FAILURE);
}

t_result	map__start_point__find(t_info *info)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < info->map.height)
	{
		j = 0;
		while (j < info->map.raw[i]->length)
		{
			if (map__start_point__init(info, j, i) == ERROR)
			{
				return (FAILURE);
			}
			j++;
		}
		i++;
	}
	if (info->core.world.player.cardinal == 0)
	{
		ft_putstr_fd("Error: No start point founded\n", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}

void	map__coor__add(t_coor *result, int y, int x, int c)
{
	result->x = x;
	result->y = y;
	result->c = c;
}

int	map__dij__visit_neighbor(t_info *info, t_coor target, t_coor result[4])
{
	size_t		i;
	const bool	upper_x_precheck
		= target.x + 1 < info->map.raw[target.y]->length;
	const bool	lower_y_precheck
		= (target.y > 1 && target.x < info->map.raw[target.y - 1]->length);
	const bool	upper_y_precheck = (target.y + 1 < info->map.height
			&& target.x < info->map.raw[target.y + 1]->length);

	i = 0;
	if (target.x > 1 
			&& info->map.raw[target.y]->str[target.x - 1] == '0'
			&& info->map.visited[target.y][target.x - 1] == false)
		map__coor__add(&result[i++], target.y, target.x - 1, '0');
	if (upper_x_precheck 
			&& info->map.raw[target.y]->str[target.x + 1] == '0'
			&& info->map.visited[target.y][target.x + 1] == false)
		map__coor__add(&result[i++], target.y, target.x + 1, '0');
	if (upper_y_precheck 
			&& info->map.raw[target.y + 1]->str[target.x] == '0'
			&& info->map.visited[target.y + 1][target.x] == false)
		map__coor__add(&result[i++], target.y - 1, target.x, '0');
	if (lower_y_precheck 
			&& info->map.raw[target.y - 1]->str[target.x] == '0'
			&& info->map.visited[target.y - 1][target.x] == false)
		map__coor__add(&result[i++], target.y + 1, target.x, '0');
	return (i);
}

size_t	map__dij__path__add(t_path *open_path, t_coor *new_coor, size_t new_size)
{
	size_t	i;

	if (open_path == NULL)
	{
		ft_putstr_fd("Error: add_open_path: open_path is NULL", 2);
	}
	i = 0;
	while (i < new_size)
	{
		if (open_path->count * sizeof(t_coor) >= open_path->capacity)
		{
			open_path->capacity *= 2;
			open_path->coor =
				ft_realloc(open_path->coor, sizeof(t_coor) * open_path->count,
						open_path->capacity ,&open_path->capacity);
		}
		map__coor__add(&open_path->coor[open_path->count + i],
				new_coor[i].x, new_coor[i].y, new_coor[i].c);
		i++;
	}
	return (i);
}

void	map__dij__path__remove(t_path *open_path)
{
	open_path->coor[open_path->count - 1].c = -1;
	open_path->coor[open_path->count - 1].x = -1;
	open_path->coor[open_path->count - 1].y = -1;
}

void	map__dij__mark_visited(t_info *info, t_coor visited[4],	size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		info->map.visited[visited[i].y][visited[i].x] = true;
		i++;
	}
}

t_result	map__dij__release_path(t_info *info, t_path *open_path)
{
	size_t	path_total_n;;
	size_t	path_n;
	t_coor	new_visited_path[4];

	path_total_n = 0;
	while (open_path->count > 0)
	{
		// check every neighbor node, if "0" && not visited, add to open_path;
		path_n = map__dij__visit_neighbor(info, open_path->coor[open_path->count - 1], new_visited_path);
		map__dij__path__remove(open_path);
		map__dij__mark_visited(info, new_visited_path, path_n);
		if (map__dij__path__add(open_path, new_visited_path, path_n) != path_n)
		{
			ft_putstr_fd("Error: path not added successfully", 2);
		}
		path_total_n += path_n;
		printf("visited_path[0]: %zu, %zu, %c\n, visited_path[1]: %zu, %zu, %c\n, visited_path[2]: %zu, %zu, %c\n, visited_path[3]: %zu, %zu, %c\n", new_visited_path[0].x, new_visited_path[0].y, new_visited_path[0].c, new_visited_path[1].x, new_visited_path[1].y, new_visited_path[1].c, new_visited_path[2].x, new_visited_path[2].y, new_visited_path[2].c, new_visited_path[3].x, new_visited_path[3].y, new_visited_path[3].c);
		open_path->count--;
	}
	open_path->count = path_total_n;
	return (path_n);
}

void	init_open_path(t_info *info, t_path *open_path)
{
	open_path->capacity
		= sizeof(t_coor) * (info->map.height * info->map.width);
	open_path->coor = malloc_safe(open_path->capacity);
	ft_bzero(open_path->coor, open_path->capacity);
	open_path->count = 1;
	open_path->coor[0].x = info->core.world.player.pos.x;
	open_path->coor[0].y = info->core.world.player.pos.y;
	open_path->coor[0].c = info->core.world.player.cardinal;
}

void	map__visited_init(t_info *info)
{
	size_t	i;

	i = 0;
	info->map.visited = malloc_safe(sizeof(bool *) * (info->map.height));
	while (i < info->map.height)
	{
		info->map.visited[i] = malloc_safe(sizeof(bool) * info->map.width);
		ft_memset(info->map.visited[i], 0, sizeof(bool) * info->map.width);
		i++;
	}

	for (size_t i = 0; i < info->map.height; i++)
	{
		for (size_t j = 0; j < info->map.width; j++)
		{
			printf("%d", info->map.visited[i][j]);
		}
		printf("\n");
	}
}

t_result	map__visit_zero(t_info *info)
{
	t_result	result;
	t_path		open_path;

	result = FAILURE;
	init_open_path(info, &open_path);
	map__visited_init(info);
	// while (open_path.count != 0)
	// {
		// map__dij__release_path(info, &open_path);
	// }
	return (result);
}

bool	map__precheck(t_info *info)
{
	if (map__start_point__find(info) == true
		&& map__visit_zero(info) == SUCCESS)
	{
		printf("start point : x: %f\ny: %f\n", info->core.world.player.pos.x,
				info->core.world.player.pos.y);
		return (true);
	}
	else
	{
		ft_putstr_fd("Error: Map precheck failed\n", 2);
		return (false);
	}
}

t_result	map__validate(t_info *info)
{
	t_result	retval;

	retval = FAILURE;
	if (map__precheck(info) == true)
	{
		retval = SUCCESS;
	}
	return (retval);
}
