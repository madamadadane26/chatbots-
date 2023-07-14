CC = g++
CFLAGS = -std=c++11 -pthread -lrt
DEPS = bots.h
OBJ = bots.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bots: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) bots QUOTE.txt
