SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)
EXE = main

all: $(EXE)

$(EXE): $(OBJS)
	gcc -o $(EXE) $(OBJS)

$(OBJS): $(SRCS)
	gcc -c $(SRCS)

run: $(EXE)
	./$(EXE) $(ARGS)

clean:
	rm -f $(OBJS) $(EXE)