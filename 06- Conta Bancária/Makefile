UTIL=util.c
CAD=cadastro.c
AVR=arvore.c
MAIN=main.c
EXEC=main

all:
	gcc -Wall -g $(UTIL) $(CAD) $(AVR) $(MAIN) -o $(EXEC)

run:
	./$(EXEC)
	
debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) $(CAD) $(AVR) -o $(EXEC)

valgrind: all
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes -s ./$(EXEC)
	
zip:
	zip exercicio6.zip main.c util.c util.h cadastro.c cadastro.h arvore.c arvore.h Makefile

clean:
	@rm *.o
