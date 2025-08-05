MAIN=main.c
UTIL=util.c
JOG=jogos.c
AVL=avl.c
EXEC=main

all:
	gcc -Wall -g $(MAIN) $(UTIL) $(JOG) $(AVL) -o $(EXEC)

run:
	./$(EXEC)
	
debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) $(JOG) $(AVL) -o $(EXEC)

valgrind: all
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes -s ./$(EXEC)
	
zip:
	zip exercicio7.zip main.c util.c util.h jogos.c jogos.h avl.c avl.h Makefile CSV.csv Grupo_membros

clean:
	@rm *.o
