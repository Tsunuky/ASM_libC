##
## EPITECH PROJECT, 2019
## ASM_minilibc_2018
## File description:
## Makefile
##

NAME = libasm.so

OUTTESTS = tests.out

CC = gcc

MAKE = /usr/bin/make

SRC_DIR = ./src/
TEST_DIR = ./tests/

SRC =	$(SRC_DIR)strchr.asm				\
		$(SRC_DIR)strlen.asm				\
		$(SRC_DIR)strncmp.asm				\
		$(SRC_DIR)strcmp.asm				\
		$(SRC_DIR)strcasecmp.asm			\
		$(SRC_DIR)memcpy.asm				\
		$(SRC_DIR)memset.asm				\
		$(SRC_DIR)memmove.asm				\
		$(SRC_DIR)strcspn.asm				\
		$(SRC_DIR)strpbrk.asm				\
		$(SRC_DIR)strstr.asm				\
		$(SRC_DIR)rindex.asm				\

SRCSTESTS =	$(TEST_DIR)test_memcpy.c		\
			$(TEST_DIR)test_memmove.c		\
			$(TEST_DIR)test_memset.c		\
			$(TEST_DIR)test_rindex.c		\
			$(TEST_DIR)test_strcasecmp.c	\
			$(TEST_DIR)test_strchr.c		\
			$(TEST_DIR)test_strcmp.c		\
			$(TEST_DIR)test_strcspn.c		\
			$(TEST_DIR)test_strlen.c		\
			$(TEST_DIR)test_strncmp.c		\
			$(TEST_DIR)test_strpbrk.c		\
			$(TEST_DIR)test_strstr.c		\

OBJ = $(SRC:.asm=.o)

OBJSTESTS = $(SRCSTESTS:.c=.o)

RM = rm -f

TESTSFLAGS = -lcriterion -fno-builtin-strlen

TESTSFLAGS += -lgcov --coverage -ldl

all: $(NAME)

$(NAME):
		$(foreach s, $(SRC), nasm -f elf64 $(s);)

		ld --shared -o $(NAME) $(SRC_DIR)/*.o

clean:
		$(RM) $(OBJ) $(OBJSTESTS)

fclean: clean
		$(RM) $(NAME) $(OBJSTESTS)

tests_run: fclean all $(OBJSTESTS)
		$(CC) $(TESTSFLAGS) -o $(OUTTESTS) $(OBJSTESTS)
		./$(OUTTESTS)

re: fclean all

.PHONY: re all fclean`clean lib

