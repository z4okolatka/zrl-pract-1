SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)
EXE = main

.PHONY: all build clean run

all: build

build: $(OBJS)
	gcc -o $(EXE) $(OBJS)

$(OBJS): $(SRCS)
	gcc -c $(SRCS)

run: build
	./$(EXE) $(ARGS)

clean:
	rm -f $(OBJS) $(EXE)