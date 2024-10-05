CC = gcc
CFLAGS = -Iinclude -Wall -Wextra

LIBDIR = ./lib
BDIR = ./bin
ODIR = $(BDIR)/obj

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=$(ODIR)/%.o)
TARGET = $(LIBDIR)/libdatastructures.dll

all: $(BIN) $(ODIR) $(LIBDIR) $(TARGET)

# library rule
$(TARGET): $(OBJ)
	$(CC) -shared -o $@ $^

# objs rule
$(ODIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BDIR):
	if not exist "$(BDIR)" ( mkdir "$(BDIR)")

$(ODIR):
	if not exist "$(ODIR)" ( mkdir "$(ODIR)")

$(LIBDIR):
	if not exist "$(LIBDIR)" ( mkdir "$(LIBDIR)")

.PHONY: clean
clean:
	-rmdir /s /q "./bin"
	-rmdir /s /q "./lib"
