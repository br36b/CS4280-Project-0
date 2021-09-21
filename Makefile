CC	= g++ -g3
CFLAGS	= -std=c++11 -g3
TARGET	= P0
OBJS	= main.o tree.o tree_traversal.o

$(TARGET):	$(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o:	main.cpp tree.h tree_traversal.h node.h
	$(CC) $(CFLAGS) -c main.cpp

tree.o:	tree.cpp tree.h node.h
	$(CC) $(CFLAGS) -c tree.cpp

tree_traversal.o: tree_traversal.cpp tree_traversal.h node.h
	$(CC) $(CFLAGS) -c tree_traversal.cpp

clean:
	rm -f *.o *.preorder *.inorder *.postorder $(TARGET)
