error_handler:
	@sh ../assets/spinning_icon.sh&
	@bash -c "trap 'trap - SIGINT SIGTERM ERR; ps | grep -v grep | grep -E \"spinning_icon.sh\" | cut -c 1-5 | xargs kill; exit 1' SIGINT SIGTERM ERR; $(MAKE) all"
