Q			:= $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE		:= $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory) $(if $(filter 1,$(NO_ADDITIONAL_J)),,-j $(shell sh ../assets/nproc.sh))

CC			:= clang
CCLD		:= clang
AR			:= ar
ARFLAGS		:= cr$(if $(filter 1,$(V) $(VERBOSE)),v,)
CPPFLAGS	:= $(shell find . -type d -mindepth 1 | grep -v .git | sed "s/^/-I /" | xargs)
CFLAGS		:= -Wall -Wextra -Werror -std=c99 -pedantic $(CPPFLAGS)

SRCS		:= $(shell find . -name "*.c" | grep -v .cache | grep -v test | xargs)
SRCS_LIBFT	:= $(shell find . -name "ft_*.c" | grep -v .cache  | grep -v test | xargs)

EXECUTABLE_TARGETS := $(NAME)
