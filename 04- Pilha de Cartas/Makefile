CARD=carta.c
STACK=baralho.c
MAIN=main.c
EXEC=main

all:
	gcc -Wall -g $(CARD) $(STACK) $(MAIN) -o $(EXEC)

run:
	./$(EXEC)
	
debug:
	gcc -DDEBUG -Wall $(MAIN) $(CARD) $(STACK) -o $(EXEC)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes -s ./$(EXEC)
	
zip:
	zip exercicio4.zip main.c carta.c carta.h baralho.c baralho.h Makefile

clean:
	@rm *.o
