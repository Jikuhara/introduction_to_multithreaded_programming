TARGET  := firstThread3

CFLAGS  := $(CFLAGS) -pthread
LDFLAGS := $(LDFLAGS) -pthread

all: $(TARGET)

firstThread: firstThread3.o
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) *.o
