# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 16:22:23 by bkristen          #+#    #+#              #
#    Updated: 2022/02/05 18:28:31 by bkristen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= minitalk
SERVER_NAME 	= server
CLIENT_NAME 	= client

LIBFT 		 	= ./libft/libft.a
HEADER			= includes/minitalk.h

SERVER_SRC		= server.c
CLIENT_SRC		= client.c
SERVER_OBJ		= $(SERVER_SRC:.c=.o)
CLIENT_OBJ		= $(CLIENT_SRC:.c=.o)

SERVER_SRC_BONUS		= server_bonus.c
CLIENT_SRC_BONUS		= client_bonus.c
SERVER_OBJ_BONUS		= $(SERVER_SRC_BONUS:.c=.o)
CLIENT_OBJ_BONUS		= $(CLIENT_SRC_BONUS:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : lib server client

all : $(NAME)



lib:
	make -C libft
	
server: $(SERVER_OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER_NAME)
	
client: $(CLIENT_OBJ)  $(LIBFT)
		$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT_NAME)
	
bonus :
	make "SERVER_OBJ=$(SERVER_OBJ_BONUS)" "CLIENT_OBJ=$(CLIENT_OBJ_BONUS)" all

clean :
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS)
	make clean -C libft

fclean : clean
	@rm -f $(SERVER_NAME) $(CLIENT_NAME)
	make fclean -C libft
	
%.o : %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@	

re : fclean all

.PHONY : all clean fclean re bonus