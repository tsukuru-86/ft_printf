# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 03:15:33 by tsukuru           #+#    #+#              #
#    Updated: 2024/08/26 23:41:02 by tkomai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/
RM = rm -rf
NAME = libftprintf.a
EXEC = my_program

SRCS = ft_printf.c src/prt_str.c src/prt_int.c src/prt_unsigned.c src/prt_ptr.c src/prt_hexa.c main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME) $(EXEC)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

$(EXEC): main.o
	$(CC) -o $(EXEC) main.o $(NAME)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

run: $(EXEC)
	./$(EXEC)
	
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS) main.o $(EXEC) src/a.out
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) src/a.out
re: fclean all

.PHONY: all clean fclean re

.SILENT:
