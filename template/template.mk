NAME = cub3D

EXECUTABLE_TARGETS = $(NAME)

CFLAGS = -Wall -Wextra -Werror -O
LDFLAGS := -lmlx -framework OpenGL -framework AppKit
ARFLAGS := cr

default: all
.PHONY: default

.PHONY: all
all: $(NAME)

.PHONY: bonus
bonus: all

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(EXECUTABLE_TARGETS)

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all

$(EXECUTABLE_TARGETS):
	$(CC) $(LDFLAGS) -o $@ $^

$(NAME): $(OBJS)
