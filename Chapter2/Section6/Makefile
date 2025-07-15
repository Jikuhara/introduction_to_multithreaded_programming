TARGET  := firstThread6

CFLAGS  := $(CFLAGS) -pthread
LDFLAGS := $(LDFLAGS) -pthread

all: $(TARGET)

firstThread: firstThread6.o
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) *.o
