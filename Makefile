CC=gcc
CFLAGS=-Iinclude -Wall -Wextra

BDIR = ./build
ODIR = $(BDIR)/objs

SRC=$(wildcard src/*.c)
OBJ=$(SRC:src/%.c=$(ODIR)/%.o)
TARGET= $(BDIR)/advanced_data_structures

all: $(BIN) $(ODIR) $(TARGET)

# executable rule
$(TARGET): $(OBJ)
	$(CC) -o $@ $^

# objs rule
$(ODIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BDIR):
	@if not exist "$(BDIR)" ( mkdir "$(BDIR)")

$(ODIR):
	@if not exist "$(ODIR)" ( mkdir "$(ODIR)")

.PHONY: clean
clean:
	@if exist "$(TARGET)" ( rm "$(TARGET)")
	@if exist "$(ODIR)" ( rmdir /S /Q "$(ODIR)")
	@if exist "$(BDIR)" ( rmdir /S /Q "$(BDIR)")
