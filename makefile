programming.o: main.c history.c tokenizer.c
	gcc main.c history.c tokenizer.c -o programming.o
clean:
	rm -f *.o
