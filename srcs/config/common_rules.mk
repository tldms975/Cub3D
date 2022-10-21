.cache/%.a:
	$Qmkdir -p $(@D)
	$Q$(AR) $(ARFLAGS) $@ $^
.cache/%.exe:
	$Qmkdir -p $(@D)
	$Q$(CCLD) $(LDFLAGS) -o $@ $^
.cache/%$(SUFFIX).o: %.c | .cache/mlx
	$Qmkdir -p $(@D)
	$Q$(CC) $(CFLAGS) -MJ $@.part.json -MMD -o $@ -c $<

.cache/libft$(SUFFIX).a: $(patsubst ./%.c,.cache/%$(SUFFIX).o,$(SRCS_LIBFT))

.cache/$(NAME)$(SUFFIX).exe: $(patsubst ./%.c,.cache/%$(SUFFIX).o,$(SRCS)) .cache/libft$(SUFFIX).a | .cache/mlx/minilibx_opengl_20191021/libmlx.dylib

$(EXECUTABLE_TARGETS): %: .cache/%$(SUFFIX).exe
	$Qcp $< $@
	@ps | grep -v grep | grep "spinning_icon.sh" | cut -c 1-5 | xargs kill
	@printf "\b"
	@echo $(NAME) created
