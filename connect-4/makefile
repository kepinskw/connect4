all:
	cc main.c funkcje.c -o connect -lm

test: all
	./connect

memory:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes --track-origins=yes -v ./connect