CC = gcc
LDFLAGS =
BLDDIR = .
INCDIR = $(BLDDIR)/inc
SRCDIR = $(BLDDIR)/src
OBJDIR = $(BLDDIR)/obj
CFLAGS = -c -w -I$(INCDIR) -g
PSQLFLAGS = -L /opt/homebrew/opt/libpq/lib -lpq
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
EXE = main

.PHONY: all clean

all: clean $(EXE) run

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(PSQLFLAGS) $(OBJDIR)/*.o -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJDIR)/*.o $(EXE)

run:
	./$(EXE)

build:
	@echo "\033[1;34mBuilding Folder Structure...\033[0m"
	@mkdir -p $(INCDIR) $(SRCDIR)
	@echo "#include <stdio.h>" > $(SRCDIR)/main.c
	@echo "#include <stdlib.h>" >> $(SRCDIR)/main.c
	@echo "" >> $(SRCDIR)/main.c
	@echo "int main() {" >> $(SRCDIR)/main.c
	@echo "	return 0;" >> $(SRCDIR)/main.c
	@echo "}" >> $(SRCDIR)/main.c
	@echo ""
	@echo "\033[1;34mBuilding .editorconfig and .clang-format...\033[0m"
	@echo ""
	@echo "root = true" > .editorconfig
	@echo "" >> .editorconfig
	@echo "[*]" >> .editorconfig
	@echo "indent_style = space" >> .editorconfig
	@echo "indent_size = 2" >> .editorconfig
	@echo "end_of_line = lf" >> .editorconfig
	@echo "charset = utf-8" >> .editorconfig
	@echo "trim_trailing_whitespace = true" >> .editorconfig
	@echo "insert_final_newline = true" >> .editorconfig
	@echo "BasedOnStyle: LLVM" > .clang-format
	@echo "IndentWidth: 2" >> .clang-format
	@echo "UseTab: Always" >> .clang-format

	@echo "\033[1;32mBuilded!\033[0m"