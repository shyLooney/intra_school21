CLIENT = client
SERVER = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

SRC_CLIENT = client.c
SRC_SERVER = server.c

SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c

SRC_UTILS = ft_printf/libftprintf.a

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

OBJ_UTILS = $(SRC_UTILS:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS)
	gcc $(FLAG) $(OBJ_CLIENT) $(OBJ_UTILS) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(OBJ_UTILS)
	gcc $(FLAG) $(OBJ_SERVER) $(OBJ_UTILS) -o $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(OBJ_UTILS)
	gcc $(FLAG) $(OBJ_CLIENT_BONUS) $(OBJ_UTILS) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(OBJ_UTILS)
	gcc $(FLAG) $(OBJ_SERVER_BONUS) $(OBJ_UTILS) -o $(SERVER_BONUS)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)

fclean:		clean 
	rm -f ${CLIENT} ${SERVER} ${CLIENT_BONUS} ${SERVER_BONUS}

re: fclean all