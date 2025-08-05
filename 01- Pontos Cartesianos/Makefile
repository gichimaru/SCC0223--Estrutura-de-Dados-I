PONTO=ponto.c
CAM=caminho.c
MAIN=main.c
BINARY=main

all:
	gcc -Wall -g $(PONTO) $(CAM) $(MAIN) -o $(BINARY) -lm

run:
	./$(BINARY)
	
debug:
	gcc -DDEBUG -Wall $(MAIN) $(PONTO) $(CAM) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes -s ./$(BINARY)

clean:
	@rm *.o
