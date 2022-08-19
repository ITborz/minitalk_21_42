# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkristen <bkristen@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 13:31:32 by bkristen          #+#    #+#              #
#    Updated: 2021/10/26 12:50:11 by bkristen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIST =		ft_isalpha.c
LIST +=		ft_isdigit.c
LIST +=		ft_isalnum.c
LIST +=		ft_isascii.c
LIST +=		ft_isprint.c
LIST +=		ft_strlen.c
LIST +=		ft_memset.c
LIST += 	ft_bzero.c
LIST += 	ft_memcpy.c
LIST +=		ft_memmove.c
LIST += 	ft_strlcpy.c
LIST += 	ft_strlcat.c
LIST +=		ft_toupper.c
LIST +=		ft_tolower.c
LIST +=		ft_strchr.c
LIST +=		ft_strrchr.c
LIST +=		ft_strncmp.c
LIST +=		ft_memchr.c
LIST +=		ft_memcmp.c
LIST +=		ft_strnstr.c
LIST +=		ft_atoi.c
LIST +=		ft_calloc.c
LIST +=		ft_strdup.c
LIST +=		ft_substr.c
LIST +=		ft_strjoin.c
LIST +=		ft_strtrim.c
LIST +=		ft_split.c
LIST +=		ft_itoa.c
LIST +=		ft_strmapi.c
LIST +=		ft_striteri.c
LIST +=		ft_putchar_fd.c
LIST +=		ft_putstr_fd.c
LIST +=		ft_putendl_fd.c
LIST +=		ft_putnbr_fd.c


HEADER = libft.h
OBJ = $(patsubst %.c,%.o,$(LIST))
OBJ_B = $(patsubst %.c,%.o,$(LIST_B))


CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
		ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	rm -f $(OBJ) $(OBJ_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all



























