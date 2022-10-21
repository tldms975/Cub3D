# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 05:12:20 by hdoo              #+#    #+#              #
#    Updated: 2022/10/22 06:00:37 by hdoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= cub3D

# variables
include	config/common_variables.mk

# mlx
CFLAGS	+= -I.cache/mlx/minilibx_opengl_20191021
LDFLAGS	+= -L.cache/mlx/minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

.PHONY	: all bonus clean fclean re test dev compile_commands.json run $(EXECUTABLE_TARGETS) 

all		: $(NAME)
bonus	: all
clean	:
	$Qfind . -type d -name .cache | xargs rm -rf
fclean	:
	$Q$(MAKE) clean
	$Qrm -f $(EXECUTABLE_TARGETS)
re		:
	$Q$(MAKE) NO_ADDITIONAL_J=1 fclean
	$Q$(MAKE) NO_ADDITIONAL_J=1 all
test	:
	$Qfind . -type d -mindepth 1 -name "test" | xargs -L1 -I {} make -C {} test

# configs
include	config/make_mlx.mk
include	config/options.mk
include	config/common_rules.mk
include	config/special_rules.mk

# dependencies
-include	$(patsubst ./%.c,.cache/%$(SUFFIX).d,$(SRCS))
