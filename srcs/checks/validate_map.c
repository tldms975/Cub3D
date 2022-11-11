/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:01:09 by hdoo              #+#    #+#             */
/*   Updated: 2022/11/13 09:26:21 by hdoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "info.h"
#include <stdbool.h>
#include <stdio.h>

void	print_map(t_info *info, size_t x, size_t y);

void	print_redzone(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < info->map.height + 2)
	{
		j = 0;
		while (j + 1< info->map.width + 2)
		{
			printf("%d", info->map.redzone[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("print_redzone\n");
}
void	print_raw(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < info->map.height)
	{
		j = 0;
		while (j + 1< info->map.raw[i]->length)
		{
			printf("%c", info->map.raw[i]->str[j]);
			j++;
		}
		printf(" : %zu\n", info->map.raw[i]->length);
		i++;
	}
	printf("print_raw\n");
}

void	print_visited(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < info->map.height)
	{
		j = 0;
		while (j < info->map.width)
		{
			printf("%d", info->map.visited[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("print_visited\n");
}

char	map__check_char(char target)
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

	target = map__check_char(info->map.raw[y]->str[x]);
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

void	map__coor__add_path(t_path *open, int y, int x, int c)
{
	size_t	i;

	i = 0;
	while (i < open->capacity / sizeof(t_coor))
	{
		if (open->path[i].c == 0 || open->path[i].c == -1)
		{
			open->path[i].c = c;
			open->path[i].x = x;
			open->path[i].y = y;
			break ;
		}
		i++;
	}
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

void map__coor__add(t_coor *result, size_t y, size_t x, int c)
{
	result->x = x;
	result->y = y;
	result->c = c;
}

t_result	check_coor(t_info *info, bool precheck, size_t y, size_t x)
{
	const char	valid_land[]
		= {'0', ' '};
	size_t	i;

	if (info->map.redzone[y + 1][x + 1] == false)
	{
		return (ERROR);
	}
	i = 0;
	while (i < sizeof(valid_land))
	{
		if (precheck
				&& info->map.raw[y]->str[x] == valid_land[i]
				&& info->map.visited[y][x] == false)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

int	map__dij__visit_neighbor(t_info *info, t_coor target, t_coor added[4])
{
	const bool	prechecks[4] = 
	{
		target.x > 1,
		target.x + 1 < info->map.raw[target.y]->length,
		(target.y > 1 && target.x < info->map.raw[target.y - 1]->length),
		(target.y + 1 < info->map.height
			&& target.x < info->map.raw[target.y + 1]->length),
	};
	const int	xoffset[4] = {-1, 1, 0, 0};
	const int	yoffset[4] = {0, 0, -1, 1};
	size_t		i;
	size_t		n;
	t_result	result;

	i = 0;
	n = 0;
	while (i < 4)
	{
		result = check_coor(info, prechecks[i], target.y + yoffset[i], target.x + xoffset[i]);
		if (result == ERROR)
		{
			return (5);
		}
		else if (result == SUCCESS)
		{
			map__coor__add(&added[n++], target.y + yoffset[i], target.x + xoffset[i], '0');
		}
		i++;
	}
	map__dij__mark_visited(info, added, n);
	return (n);
}

size_t	map__dij__path__add(t_path *open, t_coor *new_coor, size_t new_size)
{
	size_t	i;

	if (open == NULL)
	{
		ft_putstr_fd("Error: add_open_path: open_path is NULL", 2);
	}
	i = 0;
	while (i < new_size)
	{
		if (open->count * sizeof(t_coor) >= open->capacity)
		{
			open->capacity *= 2;
			open->path =
				ft_realloc(open->path, sizeof(t_coor) * open->count,
						open->capacity ,&open->capacity);
		}
		map__coor__add_path(open,
				new_coor[i].y, new_coor[i].x, new_coor[i].c);
		i++;
	}
	return (i);
}

void	map__swap_coor(t_path *open, size_t i, size_t j)
{
	t_coor	tmp;

	tmp = open->path[i];
	open->path[i] = open->path[j];
	open->path[j] = tmp;
}

void	map__dij__path__remove(t_path *open, t_coor curr)
{
	size_t	i;

	i = 0;
	while (i < open->count)
	{
		if (open->path[i].x == curr.x &&
				open->path[i].y == curr.y)
		{
			open->path[i].c = -1;
			return ;
		}
		i++;
	}
	open->count--;
}

t_result	map__dij__select(t_path *open, t_coor *curr)
{
	size_t	i;

	i = 0;
	while (i < open->capacity / sizeof(t_coor))
	{
		if (open->path[i].c != -1 && open->path[i].c != 0)
		{
			*curr = open->path[i];
			return (SUCCESS);
		}
		i++;
	}
	return (FAILURE);
}

t_result	map__dij__release_path(t_info *info, t_path *open)
{
	size_t	path_total_n;;
	size_t	path_n;
	t_coor	new_visited_path[4];
	t_coor	curr;

	path_total_n = 0;
	while (open->count != 0)
	{
		// check every neighbor node, if "0" && not visited, add to open_path;
		if (map__dij__select(open, &curr) == FAILURE)
		{
			break ;
		}
		path_n = map__dij__visit_neighbor(info, curr, new_visited_path);
		if (path_n == 5)
		{
			ft_putstr_fd("Error: Invalid map: visiting redzone detected\n", 2);
			break ;
		}
		map__dij__path__remove(open, curr);
		map__dij__path__add(open, new_visited_path, path_n);
		path_total_n += path_n;
	}
	open->count = path_total_n;
	return (path_n);
}

void	init_open_path(t_info *info, t_path *open)
{
	open->capacity
		= sizeof(t_coor) * (info->map.height * info->map.width);
	open->path = malloc_safe(open->capacity);
	ft_bzero(open->path, open->capacity);
	open->count = 1;
	open->path[0].x = info->core.world.player.pos.x;
	open->path[0].y = info->core.world.player.pos.y;
	open->path[0].c = info->core.world.player.cardinal;
}

void	map__visited_init(t_info *info)
{
	size_t	i;

	i = 0;
	info->map.visited = malloc_safe(sizeof(bool *) * info->map.height);
	while (i < info->map.height)
	{
		info->map.visited[i] = malloc_safe(sizeof(bool) * info->map.width);
		ft_memset(info->map.visited[i], 0, sizeof(bool) * info->map.width);
		i++;
	}
}

t_result	map__visit_zero(t_info *info)
{
	t_result	result;
	t_path		open;

	result = FAILURE;
	init_open_path(info, &open);
	while (open.count != 0)
	{
		if (map__dij__release_path(info, &open) == ERROR)
		{
			return (ERROR);
		}
	}
	print_visited(info);
	print_raw(info);
	return (result);
}

void	map__redzone_init(t_info *info)
{
	size_t	y;
	size_t	x;
	size_t	padding;

	padding = 2;
	y = 0;
	info->map.redzone = malloc_safe(sizeof(bool *) * (info->map.height + padding));
	while (y < info->map.height + padding)
	{
		info->map.redzone[y] = malloc_safe(sizeof(bool) * (info->map.width + padding));
		ft_memset(info->map.redzone[y], 0, sizeof(bool) * (info->map.width + padding));
		y++;
	}
	y = 0;
	while (y < info->map.height)
	{
		x = 0;
		while (x < info->map.raw[y]->length)
		{
			if (map__check_char(info->map.raw[y]->str[x]) > ' ')
			{
				info->map.redzone[y + 1][x + 1] = true;
			}
			x++;
		}
		y++;
	}
	print_redzone(info);
}

bool	map__precheck(t_info *info)
{
	map__visited_init(info);
	map__redzone_init(info);
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
