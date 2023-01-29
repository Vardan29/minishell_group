NAME			=	minishell
CC				=	cc
SRC_DIR			=	src
OBJS_DIR		=	objs
LIBFT_DIR		=	libft
LIBFT			=	$(LIBFT_DIR)/libft.a
PREFIX			=	$(shell find ${HOME} -type d -name readline_out)
MODULES			=	$(shell find $(SRC_DIR) -type d)
DIST_MODULES	=	$(patsubst $(SRC_DIR), $(OBJS_DIR), $(patsubst $(SRC_DIR)/%, $(OBJS_DIR)/%, $(MODULES)))
SRCS			=	$(shell find $(SRC_DIR) -type f -name *.c)
OBJS			=	$(patsubst $(SRC_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
MKDIR			=	mkdir -p
RM				=	rm -rf
INC				=	-Iinc -I$(LIBFT_DIR)
READLINE_OUT	=	${HOME}/readline_out
READLINE_INC	=	-I$(READLINE_OUT)/include
INCLUDES		=	$(INC) $(READLINE_INC)
READLINE_DIR	=	readline
READLINE_LIB	=	$(READLINE_OUT)/lib
LINKERS			=	-L$(READLINE_LIB) -lreadline -L$(LIBFT_DIR) -lft
CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address -g
.DEFAULT_GOAL	=	all

$(OBJS_DIR):
	@$(MKDIR) $(OBJS_DIR)

$(OBJS_DIR)/%:	$(SRC_DIR)/%
	@$(MKDIR) $(DIST_MODULES)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

making: $(NAME)

all:
	@$(MAKE) making || $(MAKE) clean

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(DIST_MODULES) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LINKERS)

$(READLINE_OUT):
	@$(MKDIR) $(READLINE_OUT)

clean:
	@$(RM) $(DIST_MODULES)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

readline: $(READLINE_OUT)
	@cd ./readline && ./configure --prefix=$(PREFIX) &&\
	make clean &&\
	make &&\
	make install

debug: $(DIST_MODULES) $(OBJS)
	@# @echo $(MODULES)
	@# @echo $(DIST_MODULES)
	@# echo $(OBJS)

.PHONY: making all clean fclean re readline
