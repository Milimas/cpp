SUBDIRS = $(wildcard */*)

all:
	for dir in $(SUBDIRS); do \
		echo $$dir; \
        $(MAKE) -C $$dir/.; \
    done

clean: $(SUBDIRS)
	for dir in $(SUBDIRS); do \
		echo $$dir; \
        $(MAKE) clean -C $$dir; \
    done

fclean:
	for dir in $(SUBDIRS); do \
		echo $$dir; \
        $(MAKE) fclean -C $$dir; \
    done

re: fclean all

.PHONY: all clean fclean re