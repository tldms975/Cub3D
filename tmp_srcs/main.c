
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:25:25 by sielee            #+#    #+#             */
/*   Updated: 2022/10/29 23:40:41 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "t_mlx.h"
#include "t_motion.h"
#include "t_world.h"

#include "../libft/libft.h"

# include <stdlib.h>

#include <stdio.h>
#include <math.h>

#define TEX_H 64
#define TEX_W 64
#define mapWidth 24
#define mapHeight 24
int map[mapWidth][mapHeight] =
	{
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7},
		{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7},
		{4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
		{4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
		{4, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7},
		{4, 0, 4, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 0, 7, 7, 7, 7, 7},
		{4, 0, 5, 0, 0, 0, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 7, 0, 0, 0, 7, 7, 7, 1},
		{4, 0, 6, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 8},
		{4, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 1},
		{4, 0, 8, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 8},
		{4, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 7, 7, 7, 1},
		{4, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 7, 1},
		{6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
		{8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
		{6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
		{4, 4, 4, 4, 4, 4, 0, 4, 4, 4, 6, 0, 6, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3},
		{4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2},
		{4, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 5, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2},
		{4, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3}};

int	ft_next_frame(t_world *world);

void	ft_event_close(t_mlx *tmlx)
{
	mlx_destroy_window(tmlx->mlx, tmlx->win);
	exit(0);
}

int	ft_event_red_cross(int keycode)
{
	(void) keycode;
	exit (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

// void	ft_move_left()
// {
	
// }

// void	ft_move_right()
// {
	
// }

void	ft_move_backward(t_player *p)
{
	if (!map[(int)(p->pos.x - p->dir.x * p->move_speed)][(int)(p->pos.y)])
		p->pos.x -= p->dir.x * p->move_speed;
	if (!map[(int)(p->pos.x)][(int)(p->pos.y - p->dir.y * p->move_speed)])
		p->pos.y -= p->dir.y * p->move_speed;
}

void	ft_move_foreward(t_player *p)
{
	if (!map[(int)(p->pos.x + p->dir.x * p->move_speed)][(int)(p->pos.y)])
		p->pos.x += p->dir.x * p->move_speed;
	if (!map[(int)(p->pos.x)][(int)(p->pos.y + p->dir.y * p->move_speed)])
		p->pos.y += p->dir.y * p->move_speed;
}

void	ft_move_player(int keycode, t_player *p)
{
	if (keycode == KEY_W)
		ft_move_foreward(p);
	else if (keycode == KEY_S)
		ft_move_backward(p);
	// else if (keycode == KEY_A)
	// 	ft_move_left(world);
	// else if (keycode == KEY_D)
	// 	ft_move_right(world);
}

void	ft_move_sight(int keycode, t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	if (keycode == KEY_ARROW_R)
	{
		p->dir.x = p->dir.x * cos(-p->rot_speed) - p->dir.y * sin(-p->rot_speed);
		p->dir.y = old_dir_x * sin(-p->rot_speed) + p->dir.y * cos(-p->rot_speed);
		p->plane.x = p->plane.x * cos(-p->rot_speed) - p->plane.y * sin(-p->rot_speed);
		p->plane.y = old_plane_x * sin(-p->rot_speed) + p->plane.y * cos(-p->rot_speed);
	}
	else if (keycode == KEY_ARROW_L)
	{
		p->dir.x = p->dir.x * cos(p->rot_speed) - p->dir.y * sin(p->rot_speed);
		p->dir.y = old_dir_x * sin(p->rot_speed) + p->dir.y * cos(p->rot_speed);
		p->plane.x = p->plane.x * cos(p->rot_speed) - p->plane.y * sin(p->rot_speed);
		p->plane.y = old_plane_x * sin(p->rot_speed) + p->plane.y * cos(p->rot_speed);
	}
}

int	ft_key_press(t_keycode keycode, t_world *world)
{
	if (keycode == KEY_ESC)
		ft_event_close(world->tmlx);
	else if (keycode == KEY_A || keycode == KEY_W \
	|| keycode == KEY_D || keycode == KEY_S)
		ft_move_player(keycode, &world->player);
	else if(keycode == KEY_ARROW_L || keycode == KEY_ARROW_R)
		ft_move_sight(keycode, &world->player);
	mlx_clear_window(world->tmlx->mlx, world->tmlx->win);
	ft_next_frame(world);
	return (EXIT_SUCCESS);
}

int	*ft_load_image(char *path, t_mlx *tmlx)
{
	int		*res;

	tmlx->timg.img = mlx_xpm_file_to_image(tmlx->mlx, path, &tmlx->timg.w, \
	&tmlx->timg.h);
	tmlx->timg.data = (int *)mlx_get_data_addr(tmlx->timg.img, \
	&tmlx->timg.bpp, &tmlx->timg.line_len, &tmlx->timg.endian);

	res = (int *)malloc(sizeof(int) * (tmlx->timg.w * tmlx->timg.h));
	for (int y = 0; y < tmlx->timg.h; y++)
	{
		for (int x = 0; x < tmlx->timg.w; x++)
		{
			res[tmlx->timg.w * y + x] = tmlx->timg.data[tmlx->timg.w * y + x];
		}
	}
	mlx_destroy_image(tmlx->mlx, &tmlx->timg.img);
	return (res);
}

void	ft_background(t_world *world)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_H / 2)
	{
		x = 0;
		while (x < WIN_W)
		{
			world->buf[y][x] = world->ceiling.rgb;
			world->buf[WIN_H - y - 1][x] = world->floor.rgb;
			x++;
		}
		y++;
	}
}

void	ft_init_buf(int (*buf)[WIN_H][WIN_W])
{
	int	w;
	int	h;

	w = 0;
	while (w < WIN_H)
	{
		h = 0;
		while (h < WIN_W)
		{
			(*buf)[w][h] = 0;
			h++;
		}
		w++;
	}
}

void	ft_init_rc(t_player *p, t_raycast *rc, int x)
{
	rc->cam_x = 2 * x / (double)WIN_W - 1;
	rc->ray.x = p->dir.x + p->plane.x * rc->cam_x;
	rc->ray.y = p->dir.y + p->plane.y * rc->cam_x;
	rc->block.x = (int)p->pos.x;
	rc->block.y = (int)p->pos.y;
	rc->delta.x = fabs(1 / rc->ray.x);
	rc->delta.y = fabs(1 / rc->ray.y);
	//printf("%f | %f %f | %d %d | %f %f\n", rc->cam_x, rc->ray.x, rc->ray.y, rc->block.x, rc->block.y, rc->delta.x, rc->delta.y);
}

void	ft_step_dir(t_player *p,t_raycast *rc)
{
	if (rc->ray.x < 0)
	{
		rc->step.x = -1;
		rc->side.x = (p->pos.x - rc->block.x) * rc->delta.x;
	}
	else
	{
		rc->step.x = 1;
		rc->side.x = (rc->block.x + 1.0 - p->pos.x) * rc->delta.x;
	}
	if (rc->ray.y < 0)
	{
		rc->step.y = -1;
		rc->side.y = (p->pos.y - rc->block.y) * rc->delta.y;
	}
	else
	{
		rc->step.y = 1;
		rc->side.y = (rc->block.y + 1.0 - p->pos.y) * rc->delta.y;
	}
}

void	ft_check_hit(t_world *world, t_player *p, t_raycast *rc)
{
	int	hit;

	hit = 0;
	(void)world;//for parsed map
	while (hit == 0)
	{
		if (rc->side.x < rc->side.y)
		{
			rc->side.x += rc->delta.x;
			rc->block.x += rc->step.x;
			rc->is_side = 0;
		}
		else
		{
			rc->side.y += rc->delta.y;
			rc->block.y += rc->step.y;
			rc->is_side = 1;
		}
		if (map[rc->block.x][rc->block.y] > 0)
		{
			hit = 1;
		}
	}
	//printf("%d", i);
	if (rc->is_side == 0)
		rc->d = (rc->block.x - p->pos.x + (1 - rc->step.x) / 2) / rc->ray.x;
	else
		rc->d = (rc->block.y - p->pos.y + (1 - rc->step.y) / 2) / rc->ray.y;
	// printf("%d %d %f\n",rc->block.x, rc->block.y, rc->d);
	// printf("%d %d %f\n",rc->block.x, rc->block.y, rc->d);
}


int		ft_get_color(t_world *world, t_raycast *rc, t_texture *tex, t_draw *dr)
{
	int	color;

	dr->tex.y = (int)tex->pos & (TEX_H - 1);
	tex->pos += tex->step;
	color = world->texture[tex->type][TEX_H * dr->tex.y + dr->tex.x];
	if (rc->is_side == 1)
		color = (color >> 1) & DARKER;
	return (color);
}

void	ft_texture(t_world *world, t_raycast *rc, t_texture *tex, t_draw *dr)
{
	tex->type = map[rc->block.x][rc->block.y];
	if (rc->is_side == 0)
		tex->wall_x = world->player.pos.y + rc->d * rc->ray.y;
	else
		tex->wall_x = world->player.pos.x + rc->d * rc->ray.x;
	tex->wall_x -= floor(tex->wall_x);
	dr->tex.x = (int)(tex->wall_x * (double)TEX_W);
	if (rc->is_side == 0 && rc->ray.x > 0)
		dr->tex.x = TEX_W - dr->tex.x - 1;
	if (rc->is_side == 1 && rc->ray.y < 0)
		dr->tex.x = TEX_W - dr->tex.x - 1;
	tex->step = 1.0 * TEX_H / dr->line_h;
	tex->pos = (dr->start - WIN_H / 2 + dr->line_h / 2) * tex->step;
}

void	ft_fill_buf(t_world *world, t_raycast *rc, t_texture *tex, int x)
{
	t_draw	dr;
	int	y;

	dr.line_h = (int)(WIN_H / rc->d);
	dr.start = -dr.line_h / 2 + WIN_H / 2;
	dr.end = dr.line_h / 2 + WIN_H / 2;
	if (dr.start < 0)
		dr.start = 0;
	if (dr.end >= WIN_H)
		dr.end = WIN_H - 1;
	ft_texture(world, rc, tex, &dr);
	y = dr.start;
	while (y < dr.end)
	{
		world->buf[y][x] = ft_get_color(world, rc, tex, &dr);
		world->re = 1;
		y++;
	}
}

void	ft_set_world(t_world *world)
{
	t_raycast	rc;
	t_texture	tex;
	int	x;

	x = 0;
	if (world->re)
		ft_init_buf(&world->buf);
	ft_background(world);
	while (x < WIN_W)
	{
		ft_init_rc(&world->player, &rc, x);
		ft_step_dir(&world->player, &rc);
		ft_check_hit(world, &world->player, &rc);
		ft_fill_buf(world, &rc, &tex, x);
		x++;
	}
}

void	ft_on_screen(t_world *world, t_mlx *tmlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			tmlx->timg.data[y * WIN_W + x] = world->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(tmlx->mlx, tmlx->win, tmlx->timg.img, 0, 0);
}

int	ft_next_frame(t_world *world)
{
	ft_set_world(world);
	ft_on_screen(world, world->tmlx);
	return (EXIT_SUCCESS);
}

void	ft_render(t_world *world)
{
	t_mlx	*tmlx;

	tmlx = world->tmlx;
	ft_next_frame(world);
	mlx_loop_hook(tmlx->mlx, &ft_next_frame, world);
	mlx_hook(tmlx->win, X_EVENT_KEY_PRESS, 1L << 0, &ft_key_press, world);
	mlx_hook(tmlx->win, X_EVENT_KEY_DESTROY_NOTIFY, 0, &ft_event_red_cross, 0);
	mlx_loop(tmlx->mlx);
}

void	tmp_load_image(t_mlx *tmlx, int *texture, char *path, t_image *timg)
{
	int	y;
	int	x;

	y = 0;
	timg->img = mlx_xpm_file_to_image(tmlx->mlx, path, &timg->w, &timg->h);
	timg->data = (int *)mlx_get_data_addr(timg->img, &timg->bpp, &timg->line_len, &timg->endian);
	while (y < timg->h)
	{
		x = 0;
		while (x < timg->w)
		{
			texture[timg->w * y + x] = timg->data[timg->w * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(tmlx->mlx, timg->img);
}

void	tmp_load_texture(t_world *world)
{
	t_image	timg;

	tmp_load_image(world->tmlx, world->texture[0], "textures/eagle.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[1], "textures/redbrick.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[2], "textures/purplestone.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[3], "textures/greystone.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[4], "textures/bluestone.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[5], "textures/mossy.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[6], "textures/wood.xpm", &timg);
	tmp_load_image(world->tmlx, world->texture[7], "textures/colorstone.xpm", &timg);
}


void	ft_init_mlx(t_mlx *tmlx, t_world *world)
{
	tmlx->mlx = mlx_init();
	tmlx->win = mlx_new_window(tmlx->mlx, WIN_W, WIN_H, "cub3d");
	tmlx->timg.img = mlx_new_image(tmlx->mlx, WIN_W, WIN_H);
	tmlx->timg.data = (int *)mlx_get_data_addr(tmlx->timg.img, \
	&tmlx->timg.bpp, &tmlx->timg.line_len, &tmlx->timg.endian);
	world->tmlx = tmlx;
}

int	ft_init(t_mlx *tmlx, t_world *world)
{
	ft_init_mlx(tmlx, world);
	ft_init_buf(&world->buf);
	if (!(world->texture = (int **)malloc(sizeof(int *) * 8)))
		return (0);
	for (int i = 0; i < 8; i++)
	{
		if (!(world->texture[i] = (int *)malloc(sizeof(int) * (TEX_H * TEX_W))))
		{
			//free(world->texture[i], i);
			//free(world->texture);
			return (0);
		}
		//world->texture[i] = ft_load_texture(world->tex_path[i], tmlx);
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < TEX_H * TEX_W; j++)
		{
			world->texture[i][j] = 0;
		}
	}
	tmp_load_texture(world);
	
	//parse
	world->player.pos.x =22.0;
	world->player.pos.y =11.5;
	world->player.dir.x = -1.0;
	world->player.dir.y = 0.0;
	world->player.plane.x = 0.0;
	world->player.plane.y = 0.66;
	//init
	world->re = 0;
	world->floor.rgb = 0x336600;
	world->ceiling.rgb = 0x0099FF;
	world->player.move_speed = 0.05;
	world->player.rot_speed = 0.05;
	//world->map = map;
	return (1);
}

int main(void)
{
	t_mlx	tmlx;
	t_world	world;

	if (ft_init(&tmlx, &world))
		ft_render(&world);
	return (0);
}
