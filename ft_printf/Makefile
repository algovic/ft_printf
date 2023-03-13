# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 16:59:43 by agonzalv          #+#    #+#              #
#    Updated: 2023/03/09 16:59:57 by agonzalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GREEN		=\033[0;32m
BLUE 		=\033[0;34m
ORANGE		=\033[38;5;214m
RED			=\033[0;31m
YELLOW		=\033[0;33m
WHITE		=\033[0;37m

SRC			= ft_printf ft_itoa ft_print_char ft_print_decimal ft_print_hexa \
			  ft_print_string ft_print_unsigned ft_uitoa ft_print_ptr

SRCS		= $(addsuffix .c, ${SRC})

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

CC			= gcc
RM			= rm -f
AR			= ar rcs
HEADER		= ft_printf.h

CFLAGS		= -Wall -Wextra -Werror

%.o : %.c $(HEADER)
			@echo "$(YELLOW) Compilando  ➟  $(BLUE)$< $(WHITE)"
			@ ${CC} ${CFLAGS} -I $(HEADER) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
			$(AR) $(NAME) $(OBJS)
			@echo "$(GREEN)\n libftprintf.a creado ✓ $(NAME)\n$(WHITE)"

all:		$(NAME)
			@echo "$(YELLOW) Borrado y recompilado.:) $(WHITE)"

clean:
			$(RM) $(OBJS)
			@echo "$(RED)\n ✗ Archivos .o borrados.‼️ \n$(WHITE)";

fclean:		clean
			$(RM) $(NAME)
			@echo "$(RED)\n ✗ Todo borrado.‼️ \n$(WHITE)";

re:			fclean all

.PHONY:		all bonus clean fclean re

