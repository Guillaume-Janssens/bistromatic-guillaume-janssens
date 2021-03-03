##
## EPITECH PROJECT, 2020
## evalexper
## File description:
## makefile
##

CC	=	gcc

RM	=	rm -f

SRC	=	doop.c		\
		function.c	\
		my_gest_doop.c	\
		my_str_isnum.c	\
		my_getnbr.c	\
		my_put_nbr.c	\
		my_strlen.c	\
		evalexpr.c	\
		my_putchar.c 	\
		my_itoa.c	\
		my_nb_nbs_sw.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_revstr.c	\
		my_add.c	\
		infin_add.c	\
		my_soustract.c	\
		base_op.c	\
		my_putstr.c	\
		my_infin_div.c	\
		my_translator.c	\
		my_duprev.c	\
		main.c		\
		infin_modulo.c	\
		my_priorities.c	\
		my_infin_mult.c	\
		my_errors.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -g -I./include

NAME	=	calc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
