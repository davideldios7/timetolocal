CC = gcc
CFLAGS = -Wall -Wextra -O2 -pipe
TARGET = timetolocal
SRC = $(wildcard *.c)
PREFIX = /usr/local

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

install: $(TARGET)
	install -D $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(notdir $(TARGET))

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(notdir $(TARGET))

clean:
	rm -rf $(TARGET)
