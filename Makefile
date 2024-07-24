# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsukuru <tsukuru@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 03:15:33 by tsukuru           #+#    #+#              #
#    Updated: 2024/07/24 15:00:54 by tsukuru          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/
RM = rm -rf
NAME = libftprintf.a
EXEC = my_program

SRCS = ft_printf.c src/prt_str.c src/prt_int.c src/prt_unsigned.c src/prt_ptr.c main.c
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

run: $(EXEC)  # 実行ターゲットを追加
	./$(EXEC)
	
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS) main.o $(EXEC)
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re

.SILENT:
