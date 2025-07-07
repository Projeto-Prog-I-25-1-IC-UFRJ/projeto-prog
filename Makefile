
prog/%.o: prog/%.c prog/%.h
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

projeto: src/*.c
	$(CC) -o $@ $^ $(CFLAGS) -I. $(LIBS)

.PHONY: clean

clean:
	rm -f prog/*.o
	rm -f projeto

