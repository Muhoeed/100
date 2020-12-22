CC = g++
CFLAGS = -Wall -Werror
target = main
objs   = main.o 100matches.o

all: $(target)
	./main
	
deps: $(patsubst %.o, %.d, $(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o = .d)

main: $(objs)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(DEPFLAGS)

clean:
	rm -f $(target) $(objs) $(deps)

run:
	./main

.PHONY: all run