CC = clang
CFLAGS = -g -Wall
DEPS = tree.h list.h
OBJS = ttol.o tree.o list.o
TARGET = ttol

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm *.o $(TARGET)

all: clean $(TARGET)

