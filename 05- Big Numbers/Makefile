UTIL=util.c
LIST=list.c
MAIN=main.c
EXEC=main

all:
	gcc -Wall -g $(UTIL) $(LIST) $(MAIN) -o $(EXEC)

run:
	./$(EXEC)
	
debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) $(LIST) -o $(EXEC)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes -s ./$(EXEC)
	
zip:
	zip exercicio4.zip main.c list.c list.h util.c util.h Makefile

clean:
	@rm *.o
