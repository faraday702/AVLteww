CC = g++
#CFLAGS = -Wall -g

#Flag for AVL tree else BST
CFLAGS += -DCONFIG_AVL

target: source.o avl.o
	@$(CC) $(CFLAGS) -o source source.o avl.o
	@source

source.o: source.cpp avl.h
	@$(CC) $(CFLAGS) -c source.cpp

avl.o: avl.cpp avl.h
	@$(CC) $(CFLAGS) -c avl.cpp

clean:
	@del *.o *.exe target