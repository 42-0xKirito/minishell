# Détection de l'OS
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
    READLINE_FLAGS = -I/opt/homebrew/opt/readline/include
    READLINE_LIBS  = -L/opt/homebrew/opt/readline/lib -lreadline
else
    READLINE_FLAGS =
    READLINE_LIBS  = -lreadline
endif

# Dossiers
SRC_DIR         = src
OBJ_DIR         = obj
LIBFT_DIR       = libft
LIBFT_A         = $(LIBFT_DIR)/libft.a

# Fichiers sources
SRCS            = $(shell find $(SRC_DIR) -name "*.c")
OBJS            = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Nom du programme final
NAME            = minishell

# Compilateur et flags
CC              = cc
CFLAGS          = -Wall -Wextra -Werror -g -Iinclude $(READLINE_FLAGS)

# Commandes
RM              = rm -rf
MKDIR           = mkdir -p

# Règles
all: $(LIBFT_A) $(OBJ_DIR) $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

# Compilation : ne recompile que si le .c est modifié
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Link final : ne relink que si un .o a changé
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME) $(READLINE_LIBS)

bonus: all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
