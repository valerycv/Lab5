CC = gcc
CFLAGS = -Wall -g
TARGET = main

all: $(TARGET)

$(TARGET): main.c double_list.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c double_list.c

clean:
	rm -f $(TARGET)
