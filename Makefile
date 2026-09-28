CC = gcc
CFLAGS = -Wall -Wextra -O2 -pipe 
LDLIBS = 
TARGET = timetolocal
SRC = $(wildcard *.c)
OBJ = $(SRC:src/%.c=obj/%.o)
PREFIX = /usr/local

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDLIBS)

install: $(TARGET)
	install -D $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(notdir $(TARGET))

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(notdir $(TARGET))

obj/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj/ $(TARGET)
