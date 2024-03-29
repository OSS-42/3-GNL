#VARIABLES

#NAME = gnl.a

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -o
#CFLAGSTEST = -o
RM = rm -f
#AR = ar rcs
EXEC = test

#COLORS
LRED = \033[91m
LGREEN = \033[92m
LYELLOW = \033[93
LMAGENTA = \033[95m
LCYAN = \033[96m
DEF_COLOR = \033[0;39m

#SOURCES
SRC = get_next_line.c get_next_line_utils.c
SRCBON = get_next_line_bonus.c get_next_line_utils_bonus.c

#OBJ = $(SRC:.c=.o)
#OBJBON = $(SRCBON:.c=.o)

$(V).SILENT:

all:	$(NAME)

#$(NAME):	$(OBJ)
#	$(CC) $(CFLAGS) $(SRC)
#	$(AR) $(NAME) $(OBJ)
#	@echo "$(LGREEN)Compilation complete !$(DEF_COLOR)"

test:
	clear
	$(CC) $(CFLAGS) $(EXEC) $(SRC) main.c
	@echo "$(LMAGENTA)Voici le résultat tests$(DEF_COLOR)"
	./$(EXEC)
	$(RM) $(EXEC)

bonus:
	clear
	$(CC) $(CFLAGS) $(EXEC) $(SRCBON) main_bonus.c
	@echo "$(LMAGENTA) Voici le résultat bonus$(DEF_COLOR)"
	./$(EXEC)
	$(RM) $(EXEC)

clean:
	$(RM) $(OBJ)
	@echo "$(LCYAN)Objects files cleaned !$(DEF_COLOR)"

fclean:	clean
	$(RM) $(EXEC)
	@echo "$(LCYAN)Executables files cleaned !$(DEF_COLOR)"

re:	fclean all