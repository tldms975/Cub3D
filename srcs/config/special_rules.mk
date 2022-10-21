compile_commands.json:
	$Q$(MAKE) -k PROFILE=debug TARGET=development all ; (printf "[" && find .cache -name "*.development.debug.o.part.json" | xargs cat && printf "]") > $@

dev: compile_commands.json
	$Qfind . -type d -name test | xargs -L1 -I {} make -C {} dev

run: .cache/$(NAME)$(SUFFIX).exe
	$QDYLD_LIBRARY_PATH=.cache/mlx/minilibx_opengl_20191021 ./$< $(ARGS)
