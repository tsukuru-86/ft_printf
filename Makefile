# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomai <tkomai@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 03:15:33 by tsukuru           #+#    #+#              #
#    Updated: 2026/08/26 00:00:00 by tkomai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iincludes
AR = ar rcs
RM = rm -f

MANDATORY_SRCS = ft_printf.c \
			src/prt_utils.c \
			src/prt_str.c \
			src/prt_int.c \
			src/prt_unsigned.c \
			src/prt_ptr.c \
			src/prt_hexa.c

BONUS_SRCS = ft_printf_bonus.c \
			src/prt_utils.c \
			src/parse_format_bonus.c \
			src/format_utils_bonus.c \
			src/text_output_bonus.c \
			src/number_format_bonus.c \
			src/number_output_bonus.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
MANDATORY_MARK = .mandatory
BONUS_MARK = .bonus

all: $(NAME)

$(NAME): $(MANDATORY_MARK)

$(MANDATORY_MARK): $(MANDATORY_OBJS)
	$(RM) $(BONUS_MARK)
	$(RM) $(NAME)
	$(AR) $(NAME) $(MANDATORY_OBJS)
	touch $(MANDATORY_MARK)

bonus: $(BONUS_MARK)

$(BONUS_MARK): $(BONUS_OBJS)
	$(RM) $(MANDATORY_MARK)
	$(RM) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJS)
	touch $(BONUS_MARK)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS) $(MANDATORY_MARK) $(BONUS_MARK)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
