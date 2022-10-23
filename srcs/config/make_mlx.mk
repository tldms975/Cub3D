.cache/mlx:
	$Qmkdir -p .cache/mlx.tmp
	$Qtar xf ../assets/minilibx_opengl.tgz -C .cache/mlx.tmp
	$Qrm -rf .cache/mlx
	$Qmv .cache/mlx.tmp .cache/mlx
.cache/mlx/minilibx_opengl_20191021/libmlx.dylib: .cache/mlx
	$Qmake -s -C .cache/mlx/minilibx_opengl_20191021 -j 1 $(if $(filter 1,$(V) $(VERBOSE)),,2> /dev/null)
