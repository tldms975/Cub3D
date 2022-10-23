.PHONY: internal-target error_handler

error_handler:
	bash -c "trap 'trap - SIGINT SIGTERM ERR; exit 1' SIGINT SIGTERM ERR; $(MAKE) internal-target"

internal-target:
	ps | grep -v grep | grep "spinning_icon.sh" | cut -c 1-5 | xargs kill
