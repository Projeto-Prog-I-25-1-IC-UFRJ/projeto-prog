
prog/%.o: prog/%.c prog/%.h
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS) -lncurses

projeto: src/*.c prog/utilidades.o
	$(CC) -o $@ $^ $(CFLAGS) -I. $(LIBS) -lncurses

.PHONY: clean

clean:
	rm -f prog/*.o
	rm -f projeto

