# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 13:05:34 by bamghoug          #+#    #+#              #
#    Updated: 2021/06/08 18:18:56 by bamghoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME1 = client

FLAGS = -Werror -Wextra -Wall

SRC_CLI = client.c client_utils.c
SRC_SER = server.c server_utils.c

BONUS_SRC_CLI = bonus/client_bonus.c bonus/client_utils_bonus.c bonus/ft_itoa_bonus.c
BONUS_SRC_SER = bonus/server_bonus.c bonus/server_utils_bonus.c

all: $(NAME) $(NAME1)

$(NAME) : $(NAME1)
	gcc $(FLAGS) $(SRC_SER) -o $(NAME)
	
$(NAME1): $(SRC_CLI) $(SRC_SER)
	gcc $(FLAGS) $(SRC_CLI) -o $(NAME1)

clean :
	rm -rf $(NAME1) $(NAME)

fclean : clean

re: fclean all
	
bonus: fclean $(BONUS_SRC_CLI) $(BONUS_SRC_SER)
	gcc $(FLAGS) $(BONUS_SRC_SER) -o $(NAME)
	gcc $(FLAGS) $(BONUS_SRC_CLI) -o $(NAME1)