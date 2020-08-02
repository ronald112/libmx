NAME = libmx.a

CC = clang

SRCD = src
OBJD = obj

INC = $(wildcard inc/*.h)
FILES = $(wildcard src/*.c)

OBJ = $(FILES:$(SRCD)%.c=$(OBJD)%.o)
COMPILE = $(CC) $(CFLAGS) -c -o $@ $< -Iinc
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install

install: $(OBJD) compile_lib

compile_lib: $(OBJ)
	@ar rcs $(NAME) $^ $(INC)

$(OBJD):
	@mkdir -p $@
	
$(OBJD)/%.o: $(SRCD)/%.c $(INC)
	@$(COMPILE)

uninstall: clean
	@rm -rf $(NAME)

clean:
	@rm -rf $(OBJD)

reinstall: uninstall install