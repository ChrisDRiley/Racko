a.out: gameController.o deck.o linked_list.o single_node.o main.o
	g++ gameController.o deck.o linked_list.o single_node.o main.cpp
main.o: main.cpp gameController.o deck.o linked_list.o single_node.o
	g++ -c main.cpp gameController.o
gameController.o: gameController.cpp gameController.h deck.cpp linked_list.cpp
	g++ -c gameController.cpp
deck.o: deck.cpp deck.h
	g++ -c deck.cpp
linked_list.o: linked_list.cpp linked_list.h 
	g++ -c linked_list.cpp 
single_node.o: single_node.cpp single_node.h
	g++ -c single_node.cpp 
clean:
	rm -rf a.out *.o
