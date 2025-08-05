JOGO=jogo.c
CAT=catalogo.c
MAIN=main.c
EXEC=main

all:
	gcc -Wall -g $(JOGO) $(CAT) $(MAIN) -o $(EXEC)

run:
	./$(EXEC)
	
debug:
	gcc -DDEBUG -Wall $(MAIN) $(JOGO) $(CAT) -o $(EXEC)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes -s ./$(EXEC)
	
zip:
	zip exercicio2.zip main.c jogo.c jogo.h catalogo.c catalogo.h Makefile

clean:
	@rm *.o
