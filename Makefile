SOURCES=common-letters.c
BINARY=common-letters
OPTS=-Wall
DEBUG=-g -O0

build: $(SOURCES)
	gcc $(OPTS) -o $(BINARY) $(SOURCES)

debug: $(SOURCES)
	gcc $(OPTS) $(DEBUG) -o $(BINARY) $(SOURCES)

clean:
	rm ./*.exe
