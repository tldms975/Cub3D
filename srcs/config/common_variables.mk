Q			:= $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE		:= $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory) $(if $(filter 1,$(NO_ADDITIONAL_J)),,-j $(shell sh ../assets/nproc.sh))
ifneq (shell uname -m, x86_64)
	MAKE	:= arch -x86_64 $(MAKE)
endif

# CC			:= clang
CCLD		:= cc
AR			:= ar
ARFLAGS		:= cr$(if $(filter 1,$(V) $(VERBOSE)),v,)
CPPFLAGS	:= $(shell find . -type d -mindepth 1 | grep -v .git | sed "s/^/-I /" | xargs)
CFLAGS		:= -std=c99 -pedantic $(CPPFLAGS)

SRCS		:= $(shell find . -name "*.c" | grep -v .cache | grep -v test | grep -v bonus | xargs)
SRCS_LIBFT	:= $(shell find . -name "ft_*.c" | grep -v .cache  | grep -v test | xargs)

EXECUTABLE_TARGETS := $(NAME)
