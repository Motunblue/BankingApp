CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

SRC = bank.c bank.h cleaners.c entry.c helpers.c 

TARGET = bank

all: $(TARGET)

DEBUG_FLAGS = -g

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

debug: $(SRC)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SRC) -o bank_debug

clean:
	rm -f $(TARGET) bank_debug

betty: $(SRC)
	betty $(SRC)
