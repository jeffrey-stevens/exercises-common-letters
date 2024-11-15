SOURCES=common-letters.c
BINARY=common-letters.exe
OPTS=-Wall
DEBUG=-g -O0

build: $(SOURCES)
	gcc $(OPTS) -o $(BINARY) $(SOURCES)

debug: $(SOURCES)
	gcc $(OPTS) $(DEBUG) -o $(BINARY) $(SOURCES)

$(BINARY): build

clean:
	rm ./*.exe

test: $(BINARY)
	./$(BINARY) "A long time ago in a galaxy far, far away..." "Space, the final frontier..."